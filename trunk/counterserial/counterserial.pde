#include <PID.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <MsTimer2.h>

#define SUNSET  19  // Variable is the hour of sunset 19 = 7 o'clock
#define SUNRISE 7	// Same as above
#define EARTH_HOT_PIN  0
#define EARTH_COLD_PIN 1
#define WIND_HOT_PIN   2
#define WIND_COLD_PIN  3
#define FIRE_PIN       4
#define WATER_PIN      5

#define READ_EARTH_PIN  0
#define READ_WIND_PIN   1
#define READ_FIRE_PIN   2
#define READ_WATER_PIN  3


/* Temporary variable from germination station code */
#define coldco 		-0.711
#define medco 		-0.432
#define hotco 		-0.368
#define Vc  		0.0049      // 5V/1024bits




char cFirstChar;
char cCommand;
int iSetAlarms_g;
volatile unsigned long ulTimer = 0;
float fEarthTemp = 0;
float fWindTemp  = 0;
int iEarthRaw = 0;
int iWindRaw  = 0;
int iFireRaw  = 0;
int iWaterRaw = 0;


/* Classes,Struct Enums*/
PID earth(&ulTimer, 30);
PID wind(&ulTimer, 30);

enum command 
{
  data = 1,
  sync = 2,
  pconstant = 3,
  iconstant = 4,
  dconstant = 5,
  checktime = 6
};

/* Functions */
int calculateTemp(int iBits);
void protocol();
void sendData();         
void syncTime();		 
void updatePconstants();
void updateIconstants();
void updateDconstants();
void sunset();
void sunrise();
void sendCurrentTime();

void OneMsCounter(void)
{
 ulTimer++;
}




    
void setup()
{
   // initialize the serial communication:
   Serial.begin(38400);
}



void loop() 
{
  iEarthRaw = analogRead(READ_EARTH_PIN);
  iWindRaw  = analogRead(READ_WIND_PIN);
  iFireRaw = analogRead(READ_FIRE_PIN);
  iWaterRaw  = analogRead(READ_WATER_PIN);
  
 
  if(iSetAlarms_g)
  {
    MsTimer2::set(1, OneMsCounter); // 1ms period
    MsTimer2::start();
    Alarm.alarmRepeat(SUNRISE,0,0, sunrise);
    Alarm.alarmRepeat(SUNSET,0,0,sunset);
    iSetAlarms_g = 0;
    //Serial.print("Alarms set!!!!");
  }
  
  earth.calulateDuty(fEarthTemp);
  wind.calulateDuty(fWindTemp);

  earth.UpdateIOPins(PORTD, EARTH_HOT_PIN , EARTH_COLD_PIN);
  wind.UpdateIOPins(PORTD, WIND_HOT_PIN, WIND_COLD_PIN);
  
  protocol();

}



void protocol()
{
  int iParseFlag = 0;
          
  	cFirstChar = Serial.peek();
	if( Serial.available() >= 2 && cFirstChar == 'G')  // command length is 2 bytes
	{  
  
         cFirstChar = Serial.read();
         cCommand   = Serial.read();         
         
         //Serial.print("Got GS\n CMD: ");
         //Serial.println(cCommand);
         
         switch(cCommand - '0')
         {
          case data:
          sendData();
          break;
            		 
          case sync:
          syncTime();
          break;
            		 
          case pconstant:
          updatePconstants();
          break;
           		 
          case iconstant:
          updateIconstants();
          break;
            		 
          case dconstant:
          updateDconstants();
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
 int iCounter = 17;
 
 
 sprintf(acBuffer, "GS%04d%04d%04d%02d%02d%02dDONE",iCounter, (iCounter * 2),(iCounter * 3),(iCounter/16),(iCounter/10),(iCounter/12));
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
            		 
void  updatePconstants()
{
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acBuffer[32];
	int iError = 0;
	
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
          Serial.print("P Const error");
	}
	else
	{

	}
}
           		 

void updateIconstants()
{
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acBuffer[32];
	int iError = 0;
	
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
          Serial.print("I Const error");
	}
	else
	{
		
	}
}
            		 
void updateDconstants()
{
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acBuffer[32];
	int iError = 0;
	
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
    	  Serial.print("D Const error");
	}
	else
	{

	}
}

void sunset()
{
  bitSet(PORTD, FIRE_PIN);
}

void sunrise()
{
  bitClear(PORTD, FIRE_PIN);
}


int calculateTemp(int iBits)
{
  int temp  = 0;
  int volts = 0;
  
  volts = int (iBits * Vc * 100);

  if(volts > 466)
  {
    temp = 999;
  }
  else if(volts > 418 && volts <= 466)
  {
    temp = volts*coldco + 347;
  }
  else if(volts > 336 && volts <= 418)
  {
    temp = volts*medco + 230;
  }
  else if(volts > 234 && volts <= 336)
  {
    temp = volts*hotco + 208;
  }
  else
  {
    temp = 999;
  }

  return temp;
}

