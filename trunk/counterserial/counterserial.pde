#include <PID.h>

unsigned long ulTimer = 0;


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


 
int iCharCounter;
int iCounter;
char cmd[3];
char acbuffer[32];
char acIncoming[64];
 
void protocol();
void sendData();         
void syncTime();		 
void updatePconstants();
void updateIconstants();
void updateDconstants();


  
  
void setup()
{
  // initialize the serial communication:
  Serial.begin(38400);
  iCounter = 0;
}

void loop() 
{
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
}
            		 
void  updatePconstants()
{
}
           		 

void updateIconstants()
{
}
            		 
void updateDconstants()
{
}
