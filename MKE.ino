int pin_pylt = 2; 
int timeNecImpulse[34];
int increment = 0;
int inverseCode = 0;
int timer = 0;
int code = 0; 
int i = 0;
int j = 0;

void setup() {
pinMode(pin_pylt, INPUT);
Serial.begin(9600);
attachInterrupt(0,impulsNec,CHANGE);
}

void loop() {}

void impulsNec() {
if(digitalRead(pin_pylt) == HIGH){
timer = micros();
}

else{
timeNecImpulse[i] = micros() - timer;
if(timeNecImpulse[0] > 4100 && timeNecImpulse[0] < 4900){i++;}

if(i == 33){
increment = 1;
code = 0;

for(j = 17; j < 25; j++){
if(timeNecImpulse[j] > 1000){
code += increment;
} 
increment*=2; 
}

increment = 1;
inverseCode = 0; 

for(j = 25; j < 33; j++){

if(timeNecImpulse[j] < 1000){
inverseCode += increment;
}

increment*=2;
}
j = 0;

if(inverseCode == code){
ButtonCod(inverseCode);
} else Serial.println("ERROR");
i = 0;
}
}
}
void ButtonCod(int code){
switch(code){
case 69:Serial.println("1"); break;
case 70:Serial.println("2"); break;
case 71:Serial.println("3"); break;
case 72:Serial.println("4"); break;
case 73:Serial.println("5"); break;
case 74:Serial.println("6"); break;
case 75:Serial.println("7"); break;
case 76:Serial.println("8"); break;
case 77:Serial.println("9"); break;
case 25:Serial.println("0"); break;
case 22:Serial.println("*"); break;
case 13:Serial.println("#"); break;
case 24:Serial.println("Up"); break;
case 8:Serial.println("Left"); break;
case 90:Serial.println("Right"); break;
case 82:Serial.println("Down"); break;
case 28:Serial.println("OK"); break;

default:Serial.println("Wrong!");
}
}
