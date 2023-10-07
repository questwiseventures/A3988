/*
 * Filename: A3988.cpp
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


#include "Arduino.h"
#include "A3988.h"

A3988::A3988(int pinI0x_A, int pinI1x_A, int pinPHASE_A, int pinI0x_B, int pinI1x_B, int pinPHASE_B) {
    _pinI0x_A = pinI0x_A;
    _pinI1x_A = pinI1x_A;
    _pinPHASE_A = pinPHASE_A;
    _pinI0x_B = pinI0x_B;
    _pinI1x_B = pinI1x_B;
    _pinPHASE_B = pinPHASE_B;
    _currentStep = 1;
	_stepDir = 0; //0: CW (Default)
				  //1: CCW
	
	_stepMode = 0;  // 0: FULL Step Mode (Default)
					// 1: Half Step Mode
					// 2: Quarter Step Mode
}

void A3988::begin() {
    pinMode(_pinI0x_A, OUTPUT);
    pinMode(_pinI1x_A, OUTPUT);
    pinMode(_pinPHASE_A, OUTPUT);
    pinMode(_pinI0x_B, OUTPUT);
    pinMode(_pinI1x_B, OUTPUT);
    pinMode(_pinPHASE_B, OUTPUT);
}

void A3988::setStepMode(int mode) {
    _stepMode = mode;
	_currentStep = 1;
}

void A3988::setStepDir(int dir) {
    _stepDir = dir;
	_currentStep = 1;
}


void A3988::step() {
	
	//Full Stepping
	if(_stepMode==0){
		
		switch (_currentStep) {
			case 1:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 2:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;
			case 3:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;
			case 4:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
		}
		
		if(_stepDir==0){
			_currentStep++;
			if (_currentStep > 4) _currentStep = 1;
		}
		else if(_stepDir==1){
			_currentStep--;
			if (_currentStep < 1) _currentStep = 4;			
		}

	}
	//Half Stepping
	else if(_stepMode==1){
		switch (_currentStep) {
			case 1:
				digitalWrite(_pinI0x_A, HIGH);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, HIGH); //Or LOW
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 2:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 3:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, HIGH);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, HIGH); //or LOW
				break;
			case 4:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;
			case 5:
				digitalWrite(_pinI0x_A, HIGH);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, HIGH); //or LOW
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;				
			case 6:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;	
			case 7:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, HIGH);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, HIGH); //or LOW
				break;							
			case 8:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;					
		}
		
		if(_stepDir==0){
			_currentStep++;
			if (_currentStep > 8) _currentStep = 1;	
		}
		else if(_stepDir==1){
			_currentStep--;
			if (_currentStep < 1) _currentStep = 8;			
		}

		
	
		
	}
	//Quarter Stepping
	else if(_stepMode==2){
		
		switch (_currentStep) {
			case 1:
				digitalWrite(_pinI0x_A, HIGH);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, HIGH); //Or LOW
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 2:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 3:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 4:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, LOW);
				break;
			case 5:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, HIGH);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, HIGH); //or LOW
				break;			
			case 6:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, HIGH);
				break;	
			case 7:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;							
			case 8:
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, HIGH);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;				
			case 9:			
				digitalWrite(_pinI0x_A, HIGH);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, HIGH); //or LOW
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;				
			case 10:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;				
			case 11:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, HIGH);
				break;					
			case 12:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, HIGH);
				break;				
			case 13:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, HIGH);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, HIGH); //or LOW
				break;				
			case 14:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, HIGH);
				digitalWrite(_pinPHASE_B, LOW);
				break;			
			case 15:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, LOW);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;				
			case 16:			
				digitalWrite(_pinI0x_A, LOW);
				digitalWrite(_pinI1x_A, HIGH);
				digitalWrite(_pinPHASE_A, LOW);
				digitalWrite(_pinI0x_B, LOW);
				digitalWrite(_pinI1x_B, LOW);
				digitalWrite(_pinPHASE_B, LOW);
				break;				
				
		}
		
		if(_stepDir==0){
			_currentStep++;
			if (_currentStep > 16) _currentStep = 1;	
		}
		else if(_stepDir==1){
			_currentStep--;
			if (_currentStep < 1) _currentStep = 16;			
		}		
		
		
	}	
	
}

