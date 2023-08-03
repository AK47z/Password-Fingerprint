#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
byte r[4]={2,3,4,5};
byte c[4]={6,7,8,9};
char k[4][4]{{'1','2','3','A'},
             {'4','5','6','B'},
             {'7','8','9','C'},
             {'*','0','#','D'}};  
LiquidCrystal_I2C l1 (32,16,2);
Keypad k1(makeKeymap(k),r,c,4,4);
char p;
char pass[5]={'1','5','9','0','D'};
char key[5]={};
 byte l=0;
byte w=0;
byte s; 
void setup()
{l1.init();
 l1.backlight();
l1.print("Enter password");
 l1.setCursor(0,1);
pinMode(13,INPUT_PULLUP);
 pinMode(12,INPUT_PULLUP);
 pinMode(11,INPUT_PULLUP);
 pinMode(A0,INPUT_PULLUP);

}

void loop()
{p=k1.getKey();
 if(p){
 
   l1.print('*');

   key[l]=p;
 l++;
   if (l==5)
   {for(int i=0;i<=4;i++)
   { if(key[i]==pass[i]) w=1; 
    else w=0;}
    if(w){
      l1.clear();
      l1.print("correct");
    }
    else{   l1.clear();
      l1.print("wrong");}
  delay(1000);
   l1.clear();
    l1.print("enter your fing");
    l1.setCursor(0,1);
    s=1;
    while(s){
      if(!digitalRead(13)) {l1.print("ID 1");delay(1000); s=0;}
      else if(!digitalRead(12)) {l1.print("ID 2"); delay(1000); s=0;}
      else if(!digitalRead(11)) {l1.print("ID 3"); delay(1000); s=0;}
      else if(!digitalRead(A0)) {l1.print("ID 4"); delay(1000); s=0;}
    }
    l1.clear();  
   l=0;
   l1.print("Enter password");
 l1.setCursor(0,1);
   
   }
 
   
 
 
 
 }
 
}