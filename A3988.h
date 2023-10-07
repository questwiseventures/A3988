/*
 * Filename: A3988.h
 * Description: Arduino library for driving stepper motors driven by A3988
 *
 * Copyright (c) 2023 Questwise Ventures Corp
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef A3988_h
#define A3988_h

#include "Arduino.h"

class A3988 {
public:
    A3988(int pinI0x_A, int pinI1x_A, int pinPHASE_A, int pinI0x_B, int pinI1x_B, int pinPHASE_B); // Constructor for a single motor with two sets of I0, I1, and PHASE
    void begin(); // Initialization
	void setStepMode(int mode); //Set and Step Mode (Full / Half / Quarter)
	void setStepDir(int dir); //Set Step Direction (CW / CCW)
    void step(); 


private:
    int _pinI0x_A, _pinI1x_A, _pinPHASE_A;
    int _pinI0x_B, _pinI1x_B, _pinPHASE_B;
    int _currentStep;
	int _stepMode;
	int _stepDir;
};

#endif
