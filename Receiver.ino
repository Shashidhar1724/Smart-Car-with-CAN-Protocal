#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication (https://github.com/autowp/arduino-mcp2515/)
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd2(0x3F,16,2); // For second LCD display

struct can_frame canMsg;
 
MCP2515 mcp2515(10);                 // SPI CS Pin 10
 
 
void setup()
{
  Serial.begin(9600);                //Begins Serial Communication at 9600 baudrate
  SPI.begin();                       //Begins SPI communication
  lcd.init();
  lcd.clear();         
  lcd.backlight();                  // Make sure backlight is ON
  lcd.setCursor(0, 0);
  lcd.print("hi ");
  delay(3000);
  lcd.clear();
  lcd2.init();
  lcd2.clear();         
  lcd2.backlight();                  // Make sure backlight is ON
  lcd2.setCursor(0, 0);
  lcd2.print("hello ");
  delay(3000);
  lcd2.clear();
 
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();                  //Sets CAN at normal mode
}
 
 
void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    int h = canMsg.data[0];
    int t = canMsg.data[1];
    int g = canMsg.data[2];
    int l = canMsg.data[3];
    int f = canMsg.data[4];
    
 
    lcd.setCursor(0, 0);         //Display Temp & Humidity value received at 16x2 LCD
    lcd.print("Hum:");
    lcd.print(h);
    lcd.setCursor(8, 0);
    lcd.print("Temp:");
    lcd.print(t);
    lcd.setCursor(0, 1);        // Displays Value of air Quality 
    lcd.print("Air Quality:");
    lcd.print(g);
    delay(1000);
    lcd.clear();

    lcd2.setCursor(0, 0);     // Displays the Working of Car lights
    if( l == 0){
        
      lcd2.print("Lights off");
       
    }
    else{
      lcd2.print("Lights ON");
       
    }
      delay(1000);
      lcd.clear();
    lcd2.setCursor(0, 1);    // Displays the capacity of fuel
    lcd2.print("Fuel:");
    lcd2.setCursor(6, 1);
    if(f<=400){
      lcd2.print("Low...");
    }
    else if(f>400 && f<500){
      lcd2.print("#");
    } 
    else if(f>500 && f<600){
      lcd2.print("##");
    }
    else if(f>600 && f<700){
      lcd2.print("###");
    }
    else if(f>700 ){
      lcd2.print("####");
    }
    delay(1000);
      lcd.clear();  
  }
}
