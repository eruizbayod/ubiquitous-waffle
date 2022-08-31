# ubiquitous-waffle

SMART HOME

Overview
For this project I decided to simulate a smart home hub, using different resistors that change their resistance depending on few factors, and when certain resistance / voltage is reached on the circuit the Controller Board will send voltage to other parts of the circuit to activate different tools connected to it.

The project has 4 main parts:

-	A Photoresistor or Photocell that change its temperature depending on the light detected on the environment. When certain resistance is reached or voltage is detected by the controller board, it will send voltage to two LED lights connected on the bottom of the breadboard. This part will simulate our smart lighting of the house, turning on/off the lights of the room.


-	A Thermistor resistor that acts as a thermometer, changing its resistance depending on the temperature. When the controller detects certain voltage, which means that the temperature detected by the thermistor is high, it will turn on a motor that will rotate a fan blade. This part is a simulation of a smart home activating the air conditioning / fan of the room.


-	Two buttons, that will allow the user to operate both LED lights and the Fan blade connected to the motor. Those buttons are connected from 5V straight to the lights and blade. This will allow the user to operate the system manually by using the buttons in case the sensors are not working properly.


-	A supersonic sensor that through sound waves detects if there is the presence of a body or an object on in front of it. If the sensor detects a body or object in between 2cm to 100cm, the circuit will operate, otherwise will send low voltage signals to the LED lights and the fan. This part simulates our smart home being operating only when someone is present on the room, otherwise will stay off.

The Circuit 
Parts
LED Lights x2
Button x2
Resistor x3
Thermistor x1
Photoresistor (Photocell) x1
Fan Blade x1
3-6V Motor
Female-to-Male dupont wire
USB Cable x1
Breadboard x1
UNO R3 Controller Board x1
Jumper wire pack x1
 
The Code

First on the setup, the pins of the controller board are set up as inputs or outputs:
void setup() {
  pinMode(8, OUTPUT);	#### LED LIGHTS
  pinMode(9, OUTPUT);	#### MOTOR
  pinMode(10, OUTPUT); 	#### TRIG FROM ULTRASONIC SENSOR
  pinMode(11, INPUT);		#### ECHO FROM ULTRASONIC SENSOR
}

On the main loop() we need to read 3 different signals:
-	Light signal from photoresistor:

  light = analogRead(0);	

-	Distance signal from supersonic sensor:

  digitalWrite(10, LOW); 
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);

  duration = pulseIn(11, HIGH);
  distance = (duration / 2) * 0.0344;     #### REFERENCE CODE: https://osoyoo.com/2018/08/28/ultrasonic-sensor-2/

-	Light signal from photoresistor:

  light = analogRead(0);	

-	Temperature signal from the thermistor:

temp = analogRead(1);

And send 2 different signals to the breadboard as outputs 8 & 9:
-	If supersonic sensor doesn’t detect any body or object:

  if (distance >= 100 || distance <= 2){            
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);

    }

-	If supersonic sensor detects body or object, depending on the signals read on thermistor and photocell:

  }else{                                    
    
    light = analogRead(0);      
    light = map(light, 0, 1023, 140, 0);    
    analogWrite(8, light);
    delay(100);  
    temp = analogRead(1);
  
    if(temp>580){                 
      digitalWrite(9, HIGH);
    }else{
      digitalWrite(9, LOW);
    }
    delay(500);
  }
 
POSSIBLE IMPROVEMENTS

As it is a smart home, I could keep on adding more features to the project. The main thing I would like to have added is a real time clock, to add more functionality to the project as the ultrasonic sensor does, for example switching the circuits or off overnight and turning them back on when the user desires to or adding a motor to represent the curtains of the room, closing or opening them at the times that the user wants, the possibilities are endless.

Also, to make the project more realistic, I would like to design a miniature model of an actual room (see Miniature room picture) where to place the sensors to give a better real-life approach to the project. This would give a better understanding of how the system operates.
