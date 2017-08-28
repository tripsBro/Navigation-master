// demo to show the use of libraryMove-master.

#include <Move.h>

Move robot(2,3,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Enter the mode ofMove. Press m for mannual, a for automatic:");
while (Serial.available()!=0);

if (Serial.available()>0)
{
  
  char mode =Serial.read();
  if (mode=='m')
  {
   Move robot(2,3,4,5,6,7,'M');
    }
  else if (mode == 'a') 
  {
    Serial.println("Entering in auto mode");
   Move robot(2,3,4,5,6,7);
    }
  else 
  {
    Serial.println("Entering in auto mode");
   Move robot(2,3,4,5,6,7);
  }
  }
Serial.println("How to use:");
Serial.println("Press: 1 for forward\t 2: backward\t 3: left\t 4: right\t 5: sharpLeft\t 6: sharpRight\t 7: Decrease leftSpeed\t 8: Increase leftSpeed\t 9: Decrease rightSpeed\t 8: Increase rightSpeed");

}


void loop() {
 // Demo 

if (Serial.available()>0)
{
  
  int a=Serial.parseInt();
  switch (a)
  {
    case 1:
     {

      robot.forward();
       }
      break;
     case 2:
     {

      robot.backward();
            
      }
      break;
     case 3:
     {
 
      robot.left();
      
      }
      break;
     case 4:
     {

      robot.right();
      
      }
      break;
     case 5:
     {

      robot.sharpLeft();
     
      }
       break;
     case 6:
     {

      robot.sharpRight();
      
      }
      break;
      case 10:
     {
      robot.brake();
      
      }
      break;
     default:
     Serial.print(a);
     Serial.println(" is a wrong choice!");
    }
  
  }

}
