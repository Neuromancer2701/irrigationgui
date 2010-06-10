/*
  PID.h - Library for flashing PID code.
  Created by Seth M. King, Feburary 27, 2010.
*/

#include "WProgram.h"
#include "PID.h"

PID::PID(unsigned long *pulTimer,float fSetPoint)
{
    pulGlobalTimer = pulTimer;
	fSetpoint 	= fSetPoint;
	fProportional   = 1.0;
	fIntegral   = 1.0;
	fDerivative = 1.0;
	iDutyCycle  = 0;
	fError		= 0;
	fErrorOld	= 0;
	ulPWMTimer = *pulGlobalTimer + iDutyCycle;
}

void PID::calulateDuty(float fControl)
{
	fError = fSetpoint - fControl;
	iDutyCycle  = (fProportional * fError)  + (fIntegral * (fError + fErrorOld )/2)  + (fDerivative * (fError - fErrorOld )/2);
	if(iDutyCycle > 100)
		iDutyCycle = 100;
		
	if(iDutyCycle < 0)
		iDutyCycle = 0;	
	
	fErrorOld = fError;
	
}

void PID::SetIOPins(int iPort, int iPinPush, int iPinPull) /* Only supporting two output pins in this first iteration Push is heating, pull is cooling*/
{
	int iTimer = *pulGlobalTimer;
	bool bPull = bitRead(iPort, iPinPull);
	
	if(iTimer >= ulPWMTimer && bPull)
	{
	 bitSet(iPort, iPinPush);
	 bitClear(iPort, iPinPull);
	}
	else if(iTimer >= iTimer + 100)
	{
	 bitClear(iPort, iPinPush);
	 bitSet(iPort, iPinPull);
	}

	
     ulPWMTimer = iTimer + iDutyCycle;
}
