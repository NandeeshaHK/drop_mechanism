

#include<Servo.h>
int pin = 2;  // the digital input pin connected to the Pixhawk's AUX1 output
int pin2 = 4; // the digital input pin connected to the Pixhawk's AUX4 output, AUX4 because AUX didn't worked on PX4 on Team 3 drone
int pin3 = 7; // the digital input pin connected to the Pixhawk's AUX3 output
unsigned long pwm;
unsigned long pwm2;
unsigned long pwm3;// variables to store the pulse width

//use this servo vars for future code, it is referenced with the output pwm of Arduino nano
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
// done var is for to make sure if once the bottle is dropped, no longer servo will be used
boolean done[5] = {false, false, false, false, false};

void move_servo(Servo &myservo) {
  Serial.println("bottle drop initiated");
  myservo.attach(9); // attach the servo to pin 9
  // for loop to repeat the repeatative actions
  for(int i=0;i<2;i++)
  {
  myservo.writeMicroseconds(1800); // move to 1500us position
  delay(1000); // wait for servo to reach position

  myservo.writeMicroseconds(1000); // move to 1250us position
  delay(1000);
  }
  //Final actions
  myservo.writeMicroseconds(1800); // move back to 1500us position
  delay(200);


  myservo.detach(); // detach the servo to free up the pin
}

void setup() {
  servo1.attach(5); // Attach the servos to their respective pins
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  servo5.attach(11);
  pinMode(pin, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  Serial.begin(9600); // initialize serial communication for debugging
}

void loop() {
  pwm = pulseIn(pin, HIGH); // measure the width of the PWM pulse
  Serial.print("Pulse width1: ");
  Serial.println(pwm); // print the pulse width for debugging

  pwm2 = pulseIn(pin2, HIGH); // measure the width of the PWM pulse
  Serial.print("Pulse width2: ");
  Serial.println(pwm2); // print the pulse width for debugging
  
  pwm3 = pulseIn(pin3, HIGH); // measure the width of the PWM pulse
  Serial.print("Pulse width3: ");
  Serial.println(pwm3); // print the pulse width for debugging

  
  if(pwm<=1530&&pwm>=1470&&pwm2<=1530&&pwm2>=1470&&pwm3<=1530&&pwm3>=1470)
  { //this part is to make sure pixhawk sends the default signal
    Serial.println("Pixhawk connected successfully");
    //it is reduce outputs on serial monitor
    delay(200);
  }
  else if(pwm<=2030&&pwm>=1970&&done[0]!=true)
  { 
    //write a code below for first servo drop or call a function 
    move_servo(servo1);
    Serial.print("First bottle dropped ");
    done[0]=true;
  }
  else if(pwm>=970&&pwm<=1030&&done[1]!=true)
  { 
    //write a code below for second servo drop or call a function 
    move_servo(servo2);
    Serial.print("second bottle dropped ");
    done[1]=true;
  }
  else if(pwm2<=2030&&pwm2>=1970&&done[2]!=true)
  { 
    //write a code below for third servo drop or call a function 
    move_servo(servo3);
    Serial.print("Third bottle dropped ");
    done[2]=true;
  }
  else if(pwm2<=1030&&pwm2>=970&&done[3]!=true)
  { 
    //write a code below for fourth servo drop or call a function 
    move_servo(servo4);
    Serial.print("Fourth bottle dropped ");
    done[3]=true;
  }
  else if(pwm3<=2030&&pwm3>=1970&&done[4]!=true)
  { 
    //write a code below for fifth servo drop or call a function 
    move_servo(servo5);
    Serial.print("Fifth bottle dropped ");
    done[4]=true;
  }
  
  
  
  delay(100); // wait for a short period before taking the next measurement
}
