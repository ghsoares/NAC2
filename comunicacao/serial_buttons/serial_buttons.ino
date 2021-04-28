int buttonPin1 = 2;         // Pino do botão 1
int buttonPin2 = 3;         // Pino do botão 2
int ledPin = 13;            // Pino do led

void setup() {
  pinMode(ledPin, OUTPUT);            // Inicia o pino do led como output   
  pinMode(buttonPin1, INPUT_PULLUP);  // Inicia o pino do botão 1 como input_pullup
  pinMode(buttonPin2, INPUT_PULLUP);  // Inicia o pino do botão 2 como input_pullup
  Serial.begin(9600);				          // Inicia o Serial
}

void loop() {
  int buttonStatus1 = digitalRead(buttonPin1);  // Lê o estado do botão 1
  int buttonStatus2 = digitalRead(buttonPin2);  // Lê o estado do botão 2

  if (buttonStatus1 == LOW){              // Botão 1 foi pressionado
    	int potVal = analogRead(A0);   // Lê o valor do pot1
    	Serial.println("A");                // Manda o dado do pot1
    	Serial.println(potVal);
    	delay(500);                         // Delay de meio segundo
  }

  if (buttonStatus2 == LOW){              // Botão 2 foi pressionado
    int potVal = analogRead(A1);     // Lê o valor do pot2                  
  	Serial.println("B");                  // Manda o dado do pot2
  	Serial.println(potVal);
  	delay(500);                           // Delay de meio segundo
  }
}
