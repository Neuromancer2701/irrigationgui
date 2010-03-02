#include <PID.h>

unsigned long ulTimer = 0;


PID plant1(&ulTimer, 30);
PID plant2(&ulTimer, 30);
PID plant3(&ulTimer, 30);
 
int iCharCounter;
int iCounter;
char cmd0, cmd1;
char acbuffer[32];
char acIncoming[64];
 
void protocol();
void parsePIDstring(char *psInput, int iLength);
  
  
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
     if( Serial.available() >= 2 ) 
   {  // command length is 2 bytes
     cmd0 = Serial.read();
     cmd1 = Serial.read();
   }

    sprintf(acbuffer, "GS%04d%04d%04d%02d%02d%02dDONE",iCounter, (iCounter * 2),(iCounter * 3),(iCounter/16),(iCounter/10),(iCounter/12));

  if(cmd0 == 'G' && cmd1 == 'S')
  {
   
    Serial.print(acbuffer);
    cmd0 = 0;
    cmd1 = 0;
  }
  else if(cmd0 == 'P')
  {

    iCharCounter = 0;
    while (iCharCounter != 28) 
    {
     acIncoming[iCharCounter] = Serial.read();
     iCharCounter++;
    }

    if(acIncoming[iCharCounter - 2]== 'D' && acIncoming[iCharCounter - 1] == 'O')
    {
      parsePIDstring(acIncoming, iCharCounter - 2);
      Serial.println("ack");
      sscanf();
    }
    cmd0 = 0;
    cmd1 = 0;    
  }
  else
  {
    cmd0 = 0;
    cmd1 = 0;     
  }
  
  
  delay(100);
    iCounter++;
    if(iCounter > 1000)
      iCounter = 0;
}

void parsePIDstring(char *psInput, int iLength)
{
  int iCount = 0;
  char acBuffer[32];
  
  while(iCount < iLength)
  {
    
    
    
    iCount++;
  }
}
