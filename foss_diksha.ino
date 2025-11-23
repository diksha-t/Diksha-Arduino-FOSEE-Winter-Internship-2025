#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_light.h>
#include <Servo.h>

MPU6050 mpu(Wire);
Adafruit_SSD1306 od(128, 64, &Wire);
Servo sv;

const int irPin = 2;
const int ledPin = 13;
bool irActiveLow = true; // set true if IR module gives LOW when object detected

void setup() {
  pinMode(irPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  sv.attach(9);

  Serial.begin(9600);
  Wire.begin();

  od.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  od.clearDisplay();
  od.display();

  mpu.begin();
}

void loop() {
  mpu.update();

  int raw = digitalRead(irPin);
  bool detected = irActiveLow ? (raw == LOW) : (raw == HIGH);

  digitalWrite(ledPin, detected ? HIGH : LOW);

  float ax = mpu.getAccX();
  float ay = mpu.getAccY();
  float az = mpu.getAccZ();

  int angle = map(ax * 50, -90, 90, 0, 180);
  angle = constrain(angle, 0, 180);
  sv.write(angle);

  Serial.print("IR:");
  Serial.print(detected ? 1 : 0);
  Serial.print(" RAW:");
  Serial.print(raw);
  Serial.print(" AX:");
  Serial.print(ax);
  Serial.print(" AY:");
  Serial.print(ay);
  Serial.print(" AZ:");
  Serial.print(az);
  Serial.print(" S:");
  Serial.println(angle);

  od.clearDisplay();
  od.setTextSize(1);
  od.setTextColor(SSD1306_WHITE);
  od.setCursor(0, 0);
  od.print("IR: "); od.println(detected ? 1 : 0);
  od.print("RAW: "); od.println(raw);
  od.print("AX: "); od.println(ax);
  od.print("AY: "); od.println(ay);
  od.print("AZ: "); od.println(az);
  od.print("S: "); od.println(angle);
  od.display();

  delay(60);
}