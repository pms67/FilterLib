# FilterLib
FilterLib is a collection of digital filters (highpass, lowpass, etc.) written in **C**. The aim is to provide **quick and easy implementations of common filters**, without needing to rewrite the same code over and over again.
Specific filter types can be incorporated in code using a single include statement and filter parameters  (such as cut-off frequency and sampling frequency) are easily set using the class constructor.

## Repository Structure
Source files (.cpp and .h) are located in the *src* folder. An example implementation for Arduino is located in the *examples* folder.


## Example Usage



```cpp
#include "ButterworthLPF.h"

#define PI 3.14159265359

// Sample time of simulation (in microseconds)
#define SAMPLE_TIME_US 10000

// Set filter parameters
#define LPF_ORDER 1
#define LPF_CUTOFF_FREQ 10 
#define LPF_SAMPLE_FREQ 100

// Create low-pass filter object
ButterworthLPF lpf(LPF_ORDER, LPF_CUTOFF_FREQ, LPF_SAMPLE_FREQ);

// Simulated signal parameters
#define BASE_FREQ 5.0
#define NOISE_PWR 0.000001

float dt;
unsigned long counter;
unsigned long timer;

void setup() {

  // Initialise serial port
  Serial.begin(115200);
  while (!Serial);

  // Calculate sample time in seconds
  dt = (float) SAMPLE_TIME_US / 1000000.0;

  // Reset counter
  counter = 0;

  // Initialise timer
  timer = micros();

}

void loop() {

  if (micros() - timer >= SAMPLE_TIME_US) {

    // Generate next sample of sinusoid with additive random noise
    float measurement = sin(2 * PI * BASE_FREQ * dt * counter) + NOISE_PWR * random(-1000, 1000);

    // Filter measurement
    float filtered = lpf.update(measurement);

    // Print measurement and filtered value
    Serial.print(measurement); Serial.print(","); Serial.println(filtered);

    counter++;
    timer += SAMPLE_TIME_US;

  }

}
```

## Contributing

Contributions to additional filter types and classes are very welcome.

## License
[MIT](https://choosealicense.com/licenses/mit/)