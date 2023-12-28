

//motor driver pins
#define in1 2
#define in2 3
#define in3 4
#define in4 5

#define enA 6
#define enB 7

char t;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);   //Led

  Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
    digitalWrite(enA, 70);
    digitalWrite(enB, 70);
    digitalWrite(in1, LOW);//FORWARD
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
    digitalWrite(enA, 70);
    digitalWrite(enB, 70);
    digitalWrite(in1, HIGH);//REVERSE
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(enA, 70);
  digitalWrite(enB, 85);
  digitalWrite(in1, LOW); //right
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(enA, 70);
  digitalWrite(enB, 85);
  digitalWrite(in1, HIGH); //right
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

else if(t == 'S'){      //STOP (all motors stop)
    digitalWrite(in1, LOW);//stop
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
delay(100);
}