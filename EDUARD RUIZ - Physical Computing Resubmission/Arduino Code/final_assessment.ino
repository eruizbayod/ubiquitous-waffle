int temp = 0;
int light = 0;


void setup() {
  
  ////////Serial.begin(9600);
  pinMode(8, OUTPUT);    //////// LED LIGHTS
  pinMode(9, OUTPUT);    //////// FAN MOTOR
  
  pinMode(11, INPUT);    //////// TRIG FROM ULTRASONIC SENSOR   
  pinMode(10, OUTPUT);   //////// ECHO FROMT ULTRASONIC SENSOR

}

void loop() {
  
  
  float duration, distance;             //////////////// REFERENCE CODE: https://osoyoo.com/2018/08/28/ultrasonic-sensor-2/
  
  digitalWrite(10, LOW);                //////////////// SENSOR SENDS SOUND WAVES WITH A DELAY OF 2-10ms
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);

  duration = pulseIn(11, HIGH);
  distance = (duration / 2) * 0.0344;


  if (distance >= 100 || distance <= 2){            ///////////// IF NO BODY / OBJECT IS DETECTED, DONT OPERATE OUTPUTS 9 AND 8
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);

    
  }else{                                    ///////////// IF BODY / OBJECT DETECTED, OPERATE
    
    light = analogRead(0);      ///////// A0 input to read voltage on thermistor circuit
    light = map(light, 0, 1023, 140, 0);    
    /////////analogWrite(8, light);
    delay(100);
  
    temp = analogRead(1);
    ////////Serial.print("Temperature Analog reading = ");
    ////////Serial.println(temp);
  
    if(temp>580){                 /////////// IF TEMPERATURE IS HIGH, SEND HIGH SIGNAL TO FAN BLADE MOTOR
      digitalWrite(9, HIGH);
    }else{
      digitalWrite(9, LOW);
    }
  }
    /////Serial.print("Distance = ");
    ////Serial.print(distance);
    //////Serial.println(" cm");
    delay(500);

}
  
  
  
