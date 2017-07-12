/*
 MIDI Sequencer

 */
int a;
int del = 200;

void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
}

void loop() {
    for(int i=0;i<6;i++) {
     int randNumber = random(3);
     while(a == randNumber) {
      randNumber=random(3);
      }
     a = randNumber;
     changeVelocity(0x20);
     int myPins[] = {0x30,0x32,0x34,0x35};
     //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
     noteOn(0X90, myPins[randNumber], 0x45);
     delay(20);
     changeVelocity(0x02);
      noteOn(0X90, (myPins[randNumber]), 0x10);
     delay(del);
     }
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void changeVelocity(int velocity){
  noteOn(0XB0, 0X29, velocity);
 }
