    // include the library code:
    #include <LiquidCrystal.h> //header file for LCD display
    #include<Servo.h>  //Header for Servo motor
    int rainvalue;
    int rainsensor;
    int ldr=A0;
    int Value = 0;
    int tempPin=A1;
    int positionCounter;
    Servo servo1;
     float temp;

    const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // LCD display pin  configuration

    void setup() {
     servo1.attach(9);  //PWM pin for Servo 
      lcd.begin(16, 2);  //the LCD display configuration
      Serial.begin(9600);  // serial begin to use the serial monitor

    }

    void loop()
    {
      rainvalue= analogRead(rainsensor);  // to read the rain sensor value
      rainvalue=map(rainvalue,0,1023,0,255); // mapping the rain value to 0 to 255
      Value=analogRead(A0);
      Value = map(Value,0,1023,0,255);
      Serial.print("ldr--");
      Serial.print(Value);
      Serial.println();
      temp=analogRead(tempPin);  // temperature reading here i have used LM35 sensor
      temp=(temp*500)/1023;  //to find the celcius
      lcd.setCursor(0,1);
      lcd.print("temperature is =");
      Serial.print("temperature is =");
      lcd.print(temp);
      Serial.print(temp);
      if((temp>=40)||(Value>=50))
      {
        servo1.write(90);
        lcd.setCursor(0,0);
        lcd.print("opening window");
        Serial.println("--opening window");
      }
      else if((temp<=39)||(Value<=50)||(rainvalue<=60))
      {
        servo1.write(0);
        lcd.setCursor(0,0);
        lcd.print("closeing window");
        Serial.println("--closeing window");
      }
      for(positionCounter=0;positionCounter<50;positionCounter++)
      {
        lcd.scrollDisplayLeft(); // to scroll the display
      delay(150);
      }

      // delay at the end of the full loop:
      delay(1000);

    }
