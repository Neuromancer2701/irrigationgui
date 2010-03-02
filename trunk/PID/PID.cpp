/*
  PID.h - Library for flashing PID code.
  Created by Seth M. King, Feburary 27, 2010.
*/

#include "WProgram.h"
#include "PID.h"

PID::PID(unsigned long *pulTimer,float fSetPoint)
{
    ulTimer = *pulTimer;
	fSetpoint 	= fSetPoint;
	fProportional   = 1.0;
	fIntegral   = 1.0;
	fDerivative = 1.0;
	iDutyCycle  = 0;
	fError		= 0;
	fErrorOld	= 0;
}

void PID::setP(float fP)
{
   	fProportional   = fP;
}

void PID::setI(float fI)
{
 	fIntegral   = fI;
}

void PID::setD(float fD)
{ 
	fDerivative = fD;
}

void PID::calulateDuty(int *piDuty, float fControl)
{
	fError = fSetpoint - fControl;
	iDutyCycle  = (fProportional * fError)  + (fIntegral * (fError + fErrorOld )/2)  + (fDerivative * (fError - fErrorOld )/2);
	if(iDutyCycle > 100)
		iDutyCycle = 100;
	fErrorOld = fError;
	
	*piDuty = iDutyCycle;
}
