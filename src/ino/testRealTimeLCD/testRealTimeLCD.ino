


// Libraries --------------------------------------------------------------------------
#include <elapsedMillis.h>     // Precise Timer Control using Self Incremented Timers
#include <LiquidCrystal.h>     // LCD Control

// Constants --------------------------------------------------------------------------
#define EMPTY_LINE "                " // String with 16 black spaces

// Variable ---------------------------------------------------------------------------

// LDC Configuration
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);   // Pins Used by LCD
char lcdLineTop[16];
char lcdLineBotton[16];

// Time Management Variables
elapsedMillis timerGlobal;                          ///< Self Incremented Timer
const int FREQUENCY_LOOP = 2;                       ///< Loop Frequency (Hz)
const int STEP_TIME_LOOP = 1000/FREQUENCY_LOOP;     ///< Loop Time Step (ms)

// Debug Related Variables
const byte PIN_DEBUG = 13;

// Core Functions ---------------------------------------------------------------------

/**
 * Setup Function - Run Once Before Everything
 */
void setup() {
   // LCD Hardware Setup
   lcd.begin(16, 2); // LDC Display with 16 columns and 2 lines
   lcd.clear();
   lcd.setCursor(0, 0);

   // Erase LCD Helper Variables
   strcpy(lcdLineTop,EMPTY_LINE);
   strcpy(lcdLineBotton,EMPTY_LINE);

   // Debug PIN Setup
   pinMode(PIN_DEBUG, OUTPUT);
}

/**
 * Main Loop Function - Run Syncronous Tasks
 */
void loop() {
  /*
   * Control Frequency time ( Ensure Frequency of 1/STEP_TIME_LOOP )
   * -> Ensure Realtime control: DO NOT put anything outside the if block
   */
  if( timerGlobal > STEP_TIME_LOOP )
  {
    timerGlobal = 0; // Reset Timer (always first!)

    // Msg
    strcpy(lcdLineTop,"--Hello-World!--");
    strcpy(lcdLineBotton,"                ");

    // Print LCD
    lcd.setCursor(0,0);
    lcd.print(lcdLineTop);
    lcd.setCursor(0,1);
    lcd.print(lcdLineBotton);
    
    // Toggle PIN for External Instant Time Period Measure using Osciloscope
    digitalWrite(PIN_DEBUG, !digitalRead(PIN_DEBUG));
  }
}

// Other Functions ----------------------------------------------------------------------
