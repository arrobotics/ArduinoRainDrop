#include <Servo.h>

#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 

Servo tap_servo;

int buzzer = 4;
int sensor_pin = 2;
int tap_servo_pin =3;
int val;

void setup(){
  Serial.begin(9600);
  delay(100);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  delay(500);
  display.clearDisplay();
  display.setCursor(25, 20);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Rain Detector");
  display.setCursor(25, 40);
  display.setTextSize(1);
  display.print("Initializing");

  display.display();
  
  pinMode(sensor_pin,INPUT);
  pinMode(buzzer,OUTPUT);
  tap_servo.attach(tap_servo_pin);
  delay(3000);
  display.clearDisplay();
}

void loop(){
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  
  val = digitalRead(sensor_pin);

  if (val==0)
  {
     display.clearDisplay();
    tap_servo.write(0);
    digitalWrite(buzzer,HIGH);
    display.setCursor(10, 0);
    display.print("Rain");
    display.setCursor(0, 30);
    display.print(" Detected ");
    display.display();
     delay(3000);
     
  }
  else 
  {
    display.clearDisplay();
    tap_servo.write(180);
     digitalWrite(buzzer,LOW);
    display.setCursor(5, 0);
    display.print("Rain not ");
    display.setCursor(0, 30);
    display.print(" Detected ");
    display.display();
    delay(3000);
    
    }
}
