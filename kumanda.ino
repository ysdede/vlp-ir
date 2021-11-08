#include <Arduino.h>

#include <avr/sleep.h>
#include <avr/power.h>
#include <IRremote.h>

IRsend irsend;


int pin2 = 2;
const  int btnYukari =  4;
const  int btnAsagi =  5;
const  int btnCtrl =  6;
const  int btnSEt =  7;
const  int btnTahliye =  8;
const  int btndIS =  9;
const  int btnPriz =  10;
const  int btnIsik =  11;
const  int btnSaat =  12;

int ledPin = 13;

 int bosluk = 200;
 int kisa = 1000;
 int uzun = 1500;
 int basla = 2500;
 int bitis = 5000;

unsigned int SEt[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, bitis};
unsigned int Tahliye[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, bitis};
unsigned int dIS[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, bitis};
unsigned int Priz[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, bitis};
unsigned int Isik[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, bitis};
unsigned int Saat[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, bitis};
unsigned int Yukari[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, bitis};
unsigned int Asagi[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, bitis};
unsigned int Ctrl[] = {basla, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, kisa, bosluk, uzun, bosluk, kisa, bosluk, uzun, bosluk, uzun, bosluk, uzun, bosluk, bitis};



/***************************************************
 *  Name:        pin2Interrupt
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Service routine for pin2 interrupt  
 *
 ***************************************************/
void pin2Interrupt(void)
{
  /* This will bring us back from sleep. */
  
  /* We detach the interrupt to stop it from 
   * continuously firing while the interrupt pin
   * is low.
   */
}


/***************************************************
 *  Name:        enterSleep
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Enters the arduino into sleep mode.
 *
 ***************************************************/
void enterSleep(void)
{
  /* Setup pin2 as an interrupt and attach handler. */
  attachInterrupt(0, pin2Interrupt, LOW);
  delay(25); //100 idi
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  
  sleep_enable();
  
  sleep_mode();
  
  /* The program will continue from here. */
  
  /* First thing to do is disable sleep. */
  sleep_disable(); 
}


/***************************************************
 *  Name:        setup
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Setup for the Arduino.           
 *
 ***************************************************/
void setup()
{
  //Serial.begin(9600);
  
  /* Setup the pin direction. */
  pinMode(pin2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  pinMode(btnYukari, INPUT_PULLUP); //Yukarı
  pinMode(btnAsagi, INPUT_PULLUP); //Aşağı
  pinMode(btnCtrl, INPUT_PULLUP); //Ctrl
  pinMode(btnSEt, INPUT_PULLUP); //SEt
  pinMode(btnTahliye, INPUT_PULLUP); //Tahliye
  pinMode(btndIS, INPUT_PULLUP); //dIS
  pinMode(btnPriz, INPUT_PULLUP); //Priz
  pinMode(btnIsik, INPUT_PULLUP); //Isik
  pinMode(btnSaat, INPUT_PULLUP);  //Saat

  ////Serial.println("Initialisation complete.");
}

/***************************************************
 *  Name:        loop
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Main application loop.
 *
 ***************************************************/
 
void loop()
{
 detachInterrupt(0);

 int khz = 38; // 38kHz carrier frequency

/*
 digitalWrite(ledPin, HIGH);
 delay(300);
 digitalWrite(ledPin, LOW);
*/
 if (digitalRead(btnYukari) == LOW ) {
  //Serial.println("btnYukari");
  irsend.sendRaw(Yukari, sizeof(Yukari) / sizeof(Yukari[0]), khz);
 }

if (digitalRead(btnAsagi) == LOW ) {
  //Serial.println("btnAsagi");
  irsend.sendRaw(Asagi, sizeof(Asagi) / sizeof(Asagi[0]), khz);
 }

 if (digitalRead(btnCtrl) == LOW ) {
  //Serial.println("btnCtrl");
  irsend.sendRaw(Ctrl, sizeof(Ctrl) / sizeof(Ctrl[0]), khz);
 }

 if (digitalRead(btnSEt) == LOW ) {
  //Serial.println("btnSEt");
  irsend.sendRaw(SEt, sizeof(SEt) / sizeof(SEt[0]), khz);
 }

 if (digitalRead(btnTahliye) == LOW ) {
  //Serial.println("btnTahliye");
  irsend.sendRaw(Tahliye, sizeof(Tahliye) / sizeof(Tahliye[0]), khz);
 }

 if (digitalRead(btndIS) == LOW ) {
  //Serial.println("btndIS");
  irsend.sendRaw(dIS, sizeof(dIS) / sizeof(dIS[0]), khz);
 }

 if (digitalRead(btnPriz) == LOW ) {
  //Serial.println("btnPriz");
  irsend.sendRaw(Priz, sizeof(Priz) / sizeof(Priz[0]), khz);
 }

 if (digitalRead(btnIsik) == LOW ) {
  //Serial.println("btnIsik");
  irsend.sendRaw(Isik, sizeof(Isik) / sizeof(Isik[0]), khz);
 }
 
if (digitalRead(btnSaat) == LOW ) {
  //Serial.println("btnSaat");
  irsend.sendRaw(Saat, sizeof(Saat) / sizeof(Saat[0]), khz);
 }
 
 //Serial.println("Entering sleep");
 
 enterSleep();
}




