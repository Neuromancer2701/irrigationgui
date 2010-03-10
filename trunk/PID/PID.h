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
    void setP(float fP);
    void setI(float fI);
	void setD(float fD);
	void calulateDuty(int *piDuty, float fControl);
	float fProportional;
	float fIntegral;
	float fDerivative;
	
  private:
    unsigned long ulTimer;
	float fSetpoint;
	float fError;
	float fErrorOld;
	int   iDutyCycle;
};

#endif

