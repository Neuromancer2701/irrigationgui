/*
  PID.h - Library for flashing Morse code.
  Created by Seth M. King, Feburary 27, 2010.
*/

#ifndef PID_h
#define PID_h

#include "WProgram.h"

class PID
{
  public:
    PID(volatile unsigned long *pulTimer,float fSetPoint);
	void calulateDuty(float fControl);
	void UpdateIOPins(int iPort,int iPinPush, int iPinPull);
	float fProportional;
	float fIntegral;
	float fDerivative;
	
  private:
    volatile unsigned long *pulGlobalTimer;
	unsigned long ulPWMTimer;
	float fSetpoint;
	float fError;
	float fErrorOld;
	int   iDutyCycle;
};

#endif

