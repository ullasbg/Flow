uint8_t GPIO_Pin = D8;
int state;
int count=0;
float rainfall =0;
int rcount =0;

void setup() {
 Serial.begin(9600);
 pinMode(GPIO_Pin, INPUT);
// attachInterrupt(digitalPinToInterrupt(GPIO_Pin), IntCallback, FALLING);
}

void loop() {
  // Serial.print("Stamp(ms): ");
  state=(digitalRead(GPIO_Pin));
  Serial.print("Pin State");
  Serial.println(state);
  if (state == 0){
    while (state==0) {
      state=(digitalRead(GPIO_Pin));
      Serial.println(state);
      delayMicroseconds(100);
      if (count>15){
        state=1;
      }
      count=count+1;
      Serial.println(count);
    }
    if (count>15){
      Serial.println("Sensor Error");
      count=0;
    }
    else if (count<2){
     Serial.println("Debounce");
     count=0;
    }
    else if ((count>1) && (count <16)){
      Serial.println("Pulse detected *****************************");
      rcount =rcount +1;
      rainfall=count*0.254;
      Serial.print("Rainfall so far is = ");
      Serial.print(rainfall);
      Serial.println(" mm");
      count=0;
    }
  }
  else{
//    Serial.println("Waiting");
    delayMicroseconds(100);
    count=0;
  }
  
 //Serial.println(micros());
}
