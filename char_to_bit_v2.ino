#include <SD.h>

File myFile;

int i;
int v[256];
char c[32];

void setup()
{
  Serial.end();
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  
  Serial.print("Program starts \n");
  
  if (!SD.begin(4)) {
    Serial.println("Initialization failed!");
    return;
  }
  
  /*
  if (SD.exists("prop2.txt")) {
    SD.remove("prop2.txt");
    Serial.println("File removed.\n");
  } else {
    Serial.println("No file to remove.\n");
  }
  
  myFile = SD.open("prop2.txt", FILE_WRITE);
  
  if (myFile) {
    
    myFile.print("hello");
    myFile.close();
  } else {
    Serial.print("Failed to open file test.txt");
  }
  */ 
  myFile = SD.open("prop2.txt", FILE_READ);
  if (myFile) {
    i = 0;
    while (myFile.available()) {  
      c[i] = myFile.read();
      i++;
    }
    
    c[i] = '\0';
    
    Serial.println("done printing");
    myFile.close();
  } else {
    Serial.print("Failed to open file test.txt");
  }
  
  int k = 0, j = 0;
  i = 0;
  
  while (c[i] != '\0') {
    
    for (j = 7; j >= 0; j--) {
      v[k] = bitRead(c[i], j);
      k++;
    }
    Serial.print("\n");
    i++;
  }
  
  for (i = 0; i < 40; i++) {
    Serial.print(v[i]);
  }
  
  // check:
  Serial.print("\n");
  i = 0;
  while (c[i] != '\0') {
    Serial.print(c[i], BIN);
    i++;
  }
  
}

void loop()
{
  // nothing to do
}
