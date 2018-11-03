uint8_t GPIO_Pin = D8;
int count =0;
float rainfall =0;
long interval=0;

void setup() {
 Serial.begin(9600);
 attachInterrupt(digitalPinToInterrupt(GPIO_Pin), IntCallback, FALLING);
}

void loop() {
  Serial.println("Waiting");
  delay(3000); 
}

void IntCallback(){
 Serial.print("Inside ISR");
 if ((millis()-interval)>100){
  interval=millis();
  Serial.println(millis());
  count =count +1;
  rainfall=count*0.254;
  Serial.print("Rainfall so far is = ");
  Serial.print(rainfall);
  Serial.println(" mm");
  
 }
 
}
