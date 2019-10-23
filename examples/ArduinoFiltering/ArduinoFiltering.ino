#include "ButterworthLPF.h"
#include "HighpassFilter.h"

#define DT_US 10000
#define WN (float) (2 * M_PI * 0.5)

ButterworthLPF lpf1(1, 20, 100);
ButterworthLPF lpf2(2, 20, 100);
HighpassFilter hpf1(1, 20, 100);
HighpassFilter hpf2(2, 20, 100);

unsigned long timer;

unsigned int t;

const float dt = (DT_US / 1000000.0);

void setup() {

  Serial.begin(115200);
  while (!Serial);

  t = 0;
  timer = micros();
  
}

void loop() {

  if (micros() - timer >= DT_US) {

    float val = sin(WN*t*dt) + 0.001*random(-100, 100);

    Serial.print(val); Serial.print(",");
    Serial.print(lpf1.update(val)); Serial.print(",");
    Serial.print(lpf2.update(val)); Serial.print(",");
    Serial.print(hpf1.update(val)); Serial.print(",");
    Serial.println(hpf2.update(val));

    t++;
    
  
    timer += DT_US;
    
  }
  
}
