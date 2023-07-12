//all that writes to SD use the function writeToSD, overloaded to take text, int or byte.
void writeToSD(char[] text, char[] file) {  //writeToSD for text
  TBD
}
void writeToSD(int number, char[] file) {  //writeToSD for int
  TBD
}
void writeToSD(byte text char[] file) {  //writeToSD for bytes
  TBD
}


void writeStateToSD(byte byteState) {
  int intState = byteState
    writeToSD(intState, "NON SO LA POSIZIONE");
}

void writeTimeToSD(char[] text, long int time) {
  TBD
}

writeAccToSD(int accX, int accY, int accZ) {
  TBD
}

writeAngToSD(int angX, int angY, int angZ) {
  TBD
}

writeBarToSD(int bar) {
  TBD
}

writeTempToSD(int temp) {
  TBD
}