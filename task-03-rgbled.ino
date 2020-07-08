/* Task-03
 * RGB LED
 */
int redPin = 2;
int greenPin = 3;
int bluePin = 7;

//uncomment this line if using a Common Cathode LED
#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  setColor(255, 0, 0);  // red
  delay(1500);
  setColor(0, 255, 0);  // green
  delay(1500);
  setColor(0, 0, 255);  // blue
  delay(1500);
  setColor(255, 255, 0);  // yellow
  delay(1500);  
  setColor(80, 0, 80);  // purple
  delay(1500);
  setColor(0, 255, 255);  // aqua
  delay(1500);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
