#include <Adafruit_SSD1306.h> // Biblioteca do display

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C // Endereço
Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT); // Inicia o objeto do display

int pot1Val = 0; // Valor do potênciomentro 1
int pot2Val = 0; // Valor do potênciomentro 2

void setup() {
  	Serial.begin(9600);	 // Inicia o serial

  	screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); // Inicia o display
  
	screen.display();
  	delay(2000); // Pause for 2 seconds
	screen.clearDisplay(); // Limpa o buffer do display
}


void loop() {
  	char dado;							    

  	if(Serial.available() > 0){		 	// Lê a serial		
	    dado = Serial.read();					
		if (dado == 'A') {				// Lê valor do pot1
			pot1Val = Serial.parseInt();
		}
		if (dado == 'B') {				// Lê valor do pot2
			pot2Val = Serial.parseInt();
		}
		//Serial.println(String("Pot 1: ") + pot1Val + String(" Pot 2: ") + pot2Val);
  	}

	screen.clearDisplay();				// Limpa o buffer do display
	
	screen.setTextSize(1);				// Muda o tamanho do texto
	screen.setTextColor(SSD1306_WHITE);	// Muda a cor do texto
	screen.setCursor(0, 0);				// Move o cursor (onde o texto começa a aparecer)
	
	screen.print("Pot1: ");				// Mostra o pot1
	screen.println(pot1Val);
	screen.print("Pot2: ");				// Mostra o pot2
	screen.println(pot2Val);
	
	screen.display();					// Aplica os comandos de desenho no display
}