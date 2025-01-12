
#include <Servo.h>

Servo myservo; 
//LEFT
int IN1_L = 5;
int IN2_L = 6;
int IN3_L = 9;
int IN4_L = 10;

char incomingByte; // for incoming serial data
int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;
int pos_0 = 0;
int pos_1 =0;
int pos_2=0;
void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();
void servo_left_on();
void servo_left_off();
void servo_right_off();
void servo_right_on();
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(IN1_L, OUTPUT);
  pinMode(IN2_L, OUTPUT);
  pinMode(IN3_L, OUTPUT);
  pinMode(IN4_L, OUTPUT);
  // put your setup code here, to run once:
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
   myservo.write(pos_0); 
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }
  switch (incomingByte)
  {
    case 'S':
      {
        stopy();
        Serial.println("Stop\n");
        incomingByte = '*';
      }
      break;

    case 'F':

      { left();

        Serial.println("backward\n");
        incomingByte = '*';
      }
      break;

    case 'B':

      { right();
        // Serial.println("forward\n");
        incomingByte = '*';
      }
      break;

    case 'R':
      // turn right
      {
        forward();
        Serial.println("Rotate Right\n");
        incomingByte = '*';
      }
      break;
    case 'L':
      {
        backward();
        Serial.println("Rotate Left\n");
        incomingByte = '*';
      }
      break;
    case '1':

      { speed_left = 20;
        speed_right = 20;
        Serial.println("Speed 1\n");
        incomingByte = '*';
      }
      break;
    case '2':
      {
        speed_left = 40;
        speed_right = 40;
        Serial.println("Speed 2 \n");
        incomingByte = '*';
      }
      break;
    case '3':
      {
        speed_left = 60;
        speed_right = 60;
        Serial.println("Speed 3 \n");
        incomingByte = '*';
      }
      break;
    case '4':
      {
        speed_left = 80;
        speed_right = 80;
        Serial.println("Speed 4 \n");
        incomingByte = '*';
      }
      break;
    case '5':
      {
        speed_left = 100;
        speed_right = 100;
        Serial.println("Speed 5 \n");
        incomingByte = '*';
      }
      break;
    case '6':
      {
        speed_left = 120;
        speed_right = 120;
        Serial.println("Speed 6 \n");
        incomingByte = '*';
      }
      break;
    case '7':
      {
        speed_left = 140;
        speed_right = 140;
        Serial.println("Speed 7 \n");
        incomingByte = '*';
      }
      break;
    case '8':
      {
        speed_left = 160;
        speed_right = 160;
        Serial.println("Speed 8 \n");
        incomingByte = '*';
      }
      break;
    case '9':
      {
        speed_left = 200;
        speed_right = 200;
        Serial.println("Speed 9 \n");
        incomingByte = '*';
      }
      break;
    case 'q':
      {
        speed_left = 255;
        speed_right = 255;
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;



case 'G':
      {
       forward_right();
        Serial.println("Forward Right \n");
        incomingByte = '*';
      }
      break;
      
      
    case 'H':
      {
        forward_left();
        Serial.println("Backward Right\n");
        incomingByte = '*';
      }
      break;
      
    case 'I':
      {
        back_left();
        Serial.println("Backward Left \n");
        incomingByte = '*';
      }
      break;
    
    case 'J':
      {
        back_right();
        Serial.println("Forward Left\n");
        incomingByte = '*';
      }
      break;







      
      case 'w':
      {
        servo_right_on();
        Serial.println("Forward Left\n");
        incomingByte = '*';
      }
      break;
      case 'W':
      {
        servo_right_off();
        Serial.println("Forward Left\n");
        incomingByte = '*';
      }
      break;
      case 'u':
      {
        servo_left_on();
        Serial.println("Forward Left\n");
        incomingByte = '*';
      }
      break;
      case 'U':
      {
        servo_left_off();
        Serial.println("Forward Left\n");
        incomingByte = '*';
      }
      break;


      
  }

}
void right() {
  //left
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};
void left() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);

};
void forward_left() {
  //left
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);

};
void forward_right() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);

};
void back_right() {
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};
void back_left() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);



};
void forward() {
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);



};
void backward() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};

void stopy() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);


};
void servo_left_on(){
     myservo.write(pos_1); 

  
  };
void servo_left_off(){
     myservo.write(pos_0); 

  };
void servo_right_off(){
     myservo.write(pos_0); 

  };
void servo_right_on(){
     myservo.write(pos_2); 

  };
  
