// this code is to control 5 servos, signal given by pixhawk

#include<Servo.h>
int pin = 2; // the digital input pin connected to the Pixhawk's AUX output
unsigned long pwm; // variable to store the pulse width

//use this servo vars for future code, it is referenced with the output pwm of Arduino nano
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
// done var is for to make sure if once the bottle is dropped, no longer servo will be used
boolean done[5] = {false, false, false, false, false};



void setup() {
  servo1.attach(5); // Attach the servos to their respective pins
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  servo5.attach(11);
  pinMode(pin, INPUT);
  Serial.begin(9600); // initialize serial communication for debugging
}

void loop() {
  pwm = pulseIn(pin, HIGH); // measure the width of the PWM pulse
  Serial.print("Pulse width: ");
  Serial.println(pulseWidth); // print the pulse width for debugging
  if(pwm==1000)
  { //this part is to make sure pixhawk sends the default signal
    Serial.print("Pixhawk connected successfully");
    //it is reduce outputs on serial monitor
    delay(200);
  }
  else if(pwm==1200&&done[0]!=true)
  { 
    //write a code below for first servo drop or call a function 
    
    Serial.print("First bottle dropped ");
    done[0]=true;
  }
  else if(pwm==1400&&done[1]!=true)
  { 
    //write a code below for second servo drop or call a function 
    
    Serial.print("second bottle dropped ");
    done[1]=true;
  }
  else if(pwm==1600&&done[2]!=true)
  { 
    //write a code below for third servo drop or call a function 
    
    Serial.print("Third bottle dropped ");
    done[2]=true;
  }
  else if(pwm==1800&&done[3]!=true)
  { 
    //write a code below for fourth servo drop or call a function 
    
    Serial.print("Fourth bottle dropped ");
    done[3]=true;
  }
  else if(pwm==2000&&done[4]!=true)
  { 
    //write a code below for fifth servo drop or call a function 
    
    Serial.print("Fifth bottle dropped ");
    done[4]=true;
  }
  
  
  
  delay(100); // wait for a short period before taking the next measurement
}
