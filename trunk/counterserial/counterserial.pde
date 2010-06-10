
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


char cmd[3];
int iSetAlarms_g;
unsigned long ulTimer = 0;


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
void protocol();
void sendData();         
void syncTime();		 
void updatePconstants();
void updateIconstants();
void updateDconstants();
void sunset();
void sunrise();
void MsCounter();


  
  
void setup()
{
  // initialize the serial communication:
  Serial.begin(38400);
  MsTimer2::set(1, MsCounter); // 1ms period
  MsTimer2::start();
  iSetAlarms_g = 0;
}

void loop() 
{
 float fEarthTemp = 0;
 float fWindTemp = 0;
  if(iSetAlarms_g)
  {
    Alarm.alarmRepeat(SUNRISE,0,0, sunrise);
	Alarm.alarmRepeat(SUNSET,0,0,sunset);
	iSetAlarms_g = 0;
  }
  
  earth.calulateDuty(fEarthTemp);
  wind.calulateDuty(fWindTemp);

  earth.SetIOPins(PORTD, EARTH_HOT_PIN , EARTH_COLD_PIN);
  wind.SetIOPins(PORTD, WIND_HOT_PIN, WIND_COLD_PIN);
  
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
          
          case default:
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
	
	if(!iError)
	{
		tTime = (time_t) atol(acTime);
		setTime(tTime);
		iSetAlarms_g = 1;
		Serial.print("Synced");
	}
	else
	{
		Serial.print("Protocol Sync error");
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
	
	if(!iError)
	{

	}
	else
	{
		Serial.print("P Const error");
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
	
	if(!iError)
	{

	}
	else
	{
		Serial.print("I Const error");
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
	
	if(!iError)
	{

	}
	else
	{
		Serial.print("D Const error");
	}
}


extern "C"	void MsCounter()
{
	ulTimer++;
}


void sunset()
{

}

void sunrise()
{

}