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
    PID(unsigned long *pulTimer,float fSetPoint);
	void calulateDuty(int *piDuty, float fControl);
	void SetIOPins(int iPort,int iPinPush, int iPinPull);
	float fProportional;
	float fIntegral;
	float fDerivative;
	
  private:
    unsigned long *pulGlobalTimer;
	unsigned long ulPWMTimer;
	float fSetpoint;
	float fError;
	float fErrorOld;
	int   iDutyCycle;
};

#endif

