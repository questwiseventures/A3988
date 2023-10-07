#include "A3988.h"

#define PIN_I01 16
#define PIN_I11 14
#define PIN_PHASE_1 10
#define PIN_I02 A0
#define PIN_I12 A1
#define PIN_PHASE_2 15


A3988 motor1(PIN_I01, PIN_I11, PIN_PHASE_1, PIN_I02, PIN_I12, PIN_PHASE_2);

void setup() {
    motor1.begin();
    motor1.setStepMode(2);
    motor1.setStepDir(0);
        
}

void loop() {
    motor1.step();
    delay(10); // Delay for visibility
}
