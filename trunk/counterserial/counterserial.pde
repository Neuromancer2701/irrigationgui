
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


char cmd[3];
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
  dconstant = 5
};

/* Functions */
float calculateTemp(int iRaw);
void protocol();
void sendData();         
void syncTime();		 
void updatePconstants();
void updateIconstants();
void updateDconstants();
void sunset();
void sunrise();
void OneMsCounter(void)
{
 ulTimer++;
}




    
void setup()
{
   // initialize the serial communication:
   Serial.begin(38400);
   MsTimer2::set(1, OneMsCounter); // 1ms period
   MsTimer2::start();
   iSetAlarms_g = 1;
}



void loop() 
{
  iEarthRaw = analogRead(READ_EARTH_PIN);
  iWindRaw  = analogRead(READ_WIND_PIN);
  iFireRaw = analogRead(READ_FIRE_PIN);
  iWaterRaw  = analogRead(READ_WATER_PIN);
  
 
  if(iSetAlarms_g)
  {
    Alarm.alarmRepeat(SUNRISE,0,0, sunrise);
    Alarm.alarmRepeat(SUNSET,0,0,sunset);
    iSetAlarms_g = 0;
  }
  
  earth.calulateDuty(fEarthTemp);
  wind.calulateDuty(fWindTemp);

  earth.UpdateIOPins(PORTD, EARTH_HOT_PIN , EARTH_COLD_PIN);
  wind.UpdateIOPins(PORTD, WIND_HOT_PIN, WIND_COLD_PIN);
  
  protocol();

}



void protocol()
{
	if( Serial.available() >= 3 ) 
	{  // command length is 2 bytes
	 cmd[0] = Serial.read();
	 cmd[1] = Serial.read();
	 cmd[2] = Serial.read();
	}

  

	if(cmd[0] == 'G' && cmd[1] == 'S')
	{
         switch(cmd[2])
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
          
          default:
          //unknown command
          break;
          }
	  cmd[0] = 0;
          cmd[1] = 0;
          cmd[2] = 0;	
	}

}


void sendData()
{
 char acBuffer[64];
 int iCounter = 17;
 
 
 sprintf(acBuffer, "GS%04d%04d%04d%02d%02d%02dDONE",iCounter, (iCounter * 2),(iCounter * 3),(iCounter/16),(iCounter/10),(iCounter/12));
 Serial.print(acBuffer);  
}
            		 
          
void syncTime()
{
	unsigned char ucByte = 0;
	int iCounter = 0;
	char acTime[32];
	int iError = 0;
	time_t tTime = 0;
	
	while(ucByte != '\n')
	{
		ucByte = Serial.read();
		acTime[iCounter] = ucByte;
		iCounter++;
		if(iCounter >=32)
			iError  = 1; //Warning did not get terminating character
			break;
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
	  Serial.print("Synced");
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

float calculateTemp(int iRaw)
{
  
}

