#include <IRremote.h>
#include <IRremoteInt.h>

    //#include <IRremote.h>
    
    IRsend irsend;
    
    const int COMMAND_LENGTH = 27;
    
   unsigned char daikin[COMMAND_LENGTH]     = { 
    0x11,0xDA,0x17,0x18,0x04,0x00,0x1E,0x11,
    //0    1    2   3    4    5     6   7
    0xDA,0x17,0x18,0x00,0x53,0x00,0x20,0x00,
    //8    9   10   11   12    13   14   15
    0x00,0x0E,0x36,0x00,0x20,0xF1,0x00,0xC0,0x00,0x00,0xE3 };
    //16  17    18  19   20    21   22  23   24   25   26


  #define ledPin 3      // the number of the LED pin
  #define switchPin 2   // the number of the button pin
  int status=1;

void setup() {
  // put your setup code here, to run once:
  
  // set the digital pin as output:
    pinMode(ledPin, OUTPUT);     
    pinMode(switchPin, INPUT); // Set the switch pin as input
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(switchPin) == LOW){
    status=1;
  }
  
  if (status==1){
    
  if(digitalRead(switchPin) == HIGH){
       
        for(int x=3;x>=3;x--){
        digitalWrite(ledPin, LOW);
        irsend.sendDaikin(daikin, 7,0); 
        delay(29);
        irsend.sendDaikin(daikin, 15,7); 
        delay(500);
        digitalWrite(ledPin, HIGH);
    }

    status=0;
  }
 }

}
 
