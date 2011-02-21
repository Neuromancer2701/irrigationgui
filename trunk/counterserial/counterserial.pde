#include <Thermistor.h>
#include <PID_Beta6.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <MsTimer2.h>


/*  Defines  */
#define SUNSET          20  // Variable is the hour of sunset 20 = 8 pm o'clock
#define SUNRISE         6	// 6 am
#define WATER_TIME      5000     // 5 seconds
#define FIRE_TIME       600000    //10 minutes
#define PERIOD          1000
#define WIND_PERIOD     10000
#define EARTH_PIN       7
#define WIND_HOT_PIN    6
#define WIND_COLD_PIN   3
#define FIRE_PIN        5
#define WATER_PIN       4

#define READ_EARTH_PIN  3
#define READ_WIND_PIN   2
#define READ_FIRE_PIN   1
#define READ_WATER_PIN  0

/* Strings and Characters */
char cFirstChar;
char cCommand;
char acPIDscanTemplate[32] = "%f %f %f";

/* Ints and floats */
int iSetAlarms_g;
int iFireOnFlag = 0;
unsigned long ulEarthTimer = 0;
unsigned long ulWindTimer = 0;

double dEarthTemp = 0;
double dEarthDuty = 0;
double dEarthSetPoint = 80;

double dWindTemp  = 0;
double dWindDuty  = 0;
double dWindSetPoint  = 75;

int iFireRaw  = 0;
int iWaterRaw = 0;
unsigned long ulWaterTimer = 0;
unsigned long ulFireTimer  = 0;


/* Classes,Struct Enums*/
Thermistor earth_thermistor(READ_EARTH_PIN);
Thermistor wind_thermistor(READ_WIND_PIN);
PID earth(&dEarthTemp,&dEarthDuty,&dEarthSetPoint,3,4,1);
PID wind(&dWindTemp,&dWindDuty,&dWindSetPoint,3,4,1);

enum command 
{
  data = 1,
  sync = 2,
  windconstant = 3,
  earthconstant = 4,
  checktime = 5
};

/* Functions */
void determineIO();
void protocol();
void sendData();         
void syncTime();		 
void updateWindConstants();
void updateEarthConstants();
void sunset();
void sunrise();
void sendCurrentTime();



    
void setup()
{
   // initialize the serial communication:
   Serial.begin(38400);
  pinMode(EARTH_PIN  , OUTPUT);
  pinMode(WIND_HOT_PIN , OUTPUT);
  pinMode(WIND_COLD_PIN , OUTPUT);
  pinMode(FIRE_PIN , OUTPUT);
  pinMode(WATER_PIN , OUTPUT);
   
   earth.SetOutputLimits(0,100);
   dEarthDuty = 50;  /* start at 50% duty cycle */
   earth.SetMode(AUTO);
   
   wind.SetOutputLimits(-100,100);  /* Not sure if this is going to work */
   dWindDuty = 50;  /* start at 50% duty cycle */ 
   wind.SetMode(AUTO);
   
   ulEarthTimer = ulWindTimer = ulFireTimer = millis();
   randomSeed(analogRead(0));

}



void loop() 
{
  dEarthTemp = earth_thermistor.getTemp();
  dWindTemp  = wind_thermistor.getTemp();
  iFireRaw = analogRead(READ_FIRE_PIN);
  iWaterRaw  = analogRead(READ_WATER_PIN);
  
 
  if(iSetAlarms_g)
  {
    Alarm.alarmRepeat(SUNRISE,0,0, sunrise);
    Alarm.alarmRepeat(SUNSET,0,0,sunset);
    iSetAlarms_g = 0;
    //Serial.print("Alarms set!!!!");
  }
  
  earth.Compute();
  wind.Compute();
  determineIO();
  
  
  protocol();

}
void determineIO()
{
  
  /* Earth  PWM IO*/
   if((millis() - ulEarthTimer) > PERIOD )
   {
     ulEarthTimer += PERIOD;
     bitSet(PORTD, EARTH_PIN);
   }
   
   if((millis() - ulEarthTimer) > (dEarthDuty * 10) )
   {
     bitClear(PORTD, EARTH_PIN);
   }
 
 
  /* Wind  PWM IO*/ 
   if((millis() - ulWindTimer) > WIND_PERIOD )
   {
     ulWindTimer  += WIND_PERIOD;
     bitSet(PORTD, WIND_HOT_PIN);
     bitSet(PORTD, WIND_COLD_PIN);
   }
   
   if(dWindDuty >= 0)
   {
     bitClear(PORTD, WIND_COLD_PIN);
     if((millis() - ulWindTimer) > (dWindDuty * 100) )
     {
       bitClear(PORTD, WIND_HOT_PIN);
     }
   }
   else
   {
     bitClear(PORTD, WIND_HOT_PIN);
     if((millis() - ulWindTimer) > (dWindDuty * -100) )
     {
       bitClear(PORTD, WIND_COLD_PIN);
     }
   }
   
   
     /* Water IO*/
   if(iWaterRaw > 400)
   {
     bitSet(PORTD, WATER_PIN);
     ulWaterTimer = millis();
   }
   
   if(millis() - ulWaterTimer > WATER_TIME && ulWaterTimer)
   {
     bitClear(PORTD, WATER_PIN);
     ulWaterTimer = 0;
   }
   
   
   
   /* Fire  IO  */
   if(millis() - ulFireTimer > FIRE_TIME)
   { 
     if(iFireRaw < 450 && iFireOnFlag )
     {
       bitSet(PORTD, FIRE_PIN);
     }
     else
     {
       bitClear(PORTD, FIRE_PIN);
     }
      
      ulFireTimer += FIRE_TIME;
   }
   
   
}


void protocol()
{
  int iParseFlag = 0;
          
  	cFirstChar = Serial.peek();
	if( Serial.available() >= 2 && cFirstChar == 'G')  // command length is 2 bytes
	{  
  
         cFirstChar = Serial.read();
         cCommand   = Serial.read();         
         
         switch(cCommand - '0')
         {
          case data:
          sendData();
          break;
            		 
          case sync:
          syncTime();
          break;
            		 
          case windconstant:
          updateWindConstants();
          break;
           		 
          case earthconstant:
          updateEarthConstants();
          break;
          
          case checktime:
          sendCurrentTime();
          break;
          
          default:
          //unknown command
          break;
          }
          Serial.flush();
          cFirstChar = 0; 
          cCommand = 0;
	}

}


void sendData()
{
   char acBuffer[64];
   
   //sprintf(acBuffer, "GS%03d%03d%04d%04d%03d%03dDONE\n",int(dEarthTemp*10), int(dWindTemp*10),iFireRaw,iWaterRaw,int(dEarthDuty) ,int(dWindDuty) );
   sprintf(acBuffer, "GS%03d%03d%04d%04d%03d%03dDONE\n",random(1023), random(1023),random(1000),random(1023),random(100) ,random(100) );

   Serial.println(acBuffer);  
}

void sendCurrentTime()
{
  Serial.println(now());
}         		 
          
void syncTime()
{
  
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acTime[32];
        int iTimeout = 0;
	int iError = 0;
	time_t tTime = 0;


        while(Serial.available() < 10 && iTimeout < 10)
        {
          delay(100);
          iTimeout++; 
        }

	while(1)
	{
		ucByte = Serial.read();
                if(ucByte == 'S')
                  break;
		acTime[iCounter] = ucByte;
		iCounter++;
		if(iCounter >=32)
                {
		 iError  = 1; //Warning did not get terminating character
		 break;
                }
	}
	
	if(iError)
	{
	  Serial.print("Protocol Sync error");
	}
	else
	{
	  tTime = (time_t) atol(acTime);
	  setTime(tTime);
	  iSetAlarms_g = 1;
	  //Serial.println("Synced!!");
	}

	
}
            		 
void updateEarthConstants()
{
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acBuffer[32];
	int iError = 0;
        double Pconst = 0.0;
        double Iconst = 0.0;
        double Dconst = 0.0;
	
	while(ucByte != '\n')
	{
		ucByte = Serial.read();
		acBuffer[iCounter] = ucByte;
		iCounter++;
		if(iCounter >=32)
			iError  = 1; //Warning did not get terminating character
			break;
	}
	
	if(iError)
	{
          Serial.print("Earth Const error");
	}
	else
	{
	 sscanf(acBuffer,acPIDscanTemplate, &Pconst, &Iconst, &Dconst);
         earth.SetTunings(Pconst,Iconst,Dconst);
	}
}
            		 
void updateWindConstants()
{
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acBuffer[32];
	int iError = 0;
        double Pconst = 0.0;
        double Iconst = 0.0;
        double Dconst = 0.0;
	
	while(ucByte != '\n')
	{
		ucByte = Serial.read();
		acBuffer[iCounter] = ucByte;
		iCounter++;
		if(iCounter >=32)
			iError  = 1; //Warning did not get terminating character
			break;
	}
	
	if(iError)
	{
    	  Serial.print("Wind Const error");
	}
	else
	{
	 sscanf(acBuffer,acPIDscanTemplate, &Pconst, &Iconst, &Dconst);
         wind.SetTunings(Pconst,Iconst,Dconst);
	}
}

void sunset()
{
  iFireOnFlag = 1;
  bitSet(PORTD, FIRE_PIN);
}

void sunrise()
{
  iFireOnFlag = 0;
  bitClear(PORTD, FIRE_PIN);
}
