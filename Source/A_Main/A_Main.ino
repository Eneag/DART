#include "I_Constants.h"
bool state = 0;

long int liftoffTime;  // time of liftoff
long int apogeeTime;   // time of apogee




void setup() {
  //forse qua facciamo il discorso di vedere se si è resettato mid volo


  // state:
  // 0: detect liftoff
  // 1: flight
  // 2: prarachute ejection
  // 3: descent
  // 4: landed
}

void loop() {
  //sensors:
  
  float accX, accY, accZ;  // acelerometers
  float angX, angY, angZ;  // angular velocities
  float bar;               // barometer
  double temp;             // termometer

  if (state == 1 || state == 2 || state == 3) {  //legge i dati e li scrive su SD

    //read sensors
    accX = readAcc('X');
    accY = readAcc('Y');
    accZ = readAcc('Z');

    angX = readAng('X');
    angY = readAng('Y');
    angZ = readAng('Z');

    bar = readBar();
    temp = readTemp();

    writeSensorsToSD(accX, accY, accZ, angX, angY, angZ,bar,temp);  //two ways to do it, every 10Hz: either write only the 10th acc and ang or salve them all in an array and write all
  }



  if (state == 0) {  // DETECT LIFTOFF

    if (isEngaged() == true) {

      if (liftoffIsDetected() == true) {
        state = 1;
        liftoffTime = millis();
        writeStateAndTimeToSD(state,liftoffTime);
      }
    }
  }


  if (state == 1) {  // FLIGHT

    flightControl();

    if (apogeeIsDetected() == true) {  //keeps flying until accelerometers notice decrease in speed OR after 7 seconds have passed since liftoffTime OR altimeters register predicted height
      state = 2;
      apogeeTime = millis();
      writeStateAndTimeToSD(state,apogeeTime);
    }
  }


  if (state == 2) {  // PARACHTUE EJECTION

    ejectParachute();  //opens nosecone

    if (parachuteIsEjected() == true) {  //keeps nose open until accelerometers notice decrease in speed OR after 4 seconds have passed since apogeeTime
      state = 3;
      writeStateAndTimeToSD(state,millis());
    }
  }



  if (state == 3) {  // DESCENT

    if (hasLanded() == true) { //hasLanded decides if it has landed by accelerometers, or after 30 seconds from apogee
      state = 4;
      landingTime == millis();
      writeStateAndTimeToSD(state,millis());
    }
  }

  if (state == 4) {    // LANDED
    screamPosition();  // buzzer screams to help locate the rocket until button pressed
  }
}
