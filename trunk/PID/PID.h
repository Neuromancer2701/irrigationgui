/*
  PID.h - Library for flashing Morse code.
  Created by Seth M. King, Feburary 27, 2010.
*/

#ifndef PID_h
#define PID_h

#include "WProgram.h"

class Morse
{
  public:
    PID(unsigned long *pulTimer,float fSetPoint);
    void setP(float fP);
    void setI(float fI);
	void setD(float fD);
	void calulateDuty(int *piDuty, float fControl);
  private:
    unsigned long ulTimer;
	float fSetpoint;
	float fProportional;
	float fIntegral;
	float fDerivative;
	float fError;
	float fErrorOld;
	int   iDutyCycle;
};

#endif

