/*
 * Keyboard library usage found here: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
 * Bounce library used for debouncing found here: https://playground.arduino.cc/Code/Bounce
 * This is done with reference to the Pro Micro and the default Arduino libraries
 * You will need to consult with different libraries if using different boards
 * 
 * Thank you Digital Media Experience Labs at Ryerson for helping sponsoring this tutorial, 
 * Thank you Thnikk (https://twitter.com/thnikk?lang=en) for helping me create the first prototype
 * Thank you all who have expressed interest in building this keyboard
 * 
 */

#include<Keyboard.h>
#include<Bounce2.h>

#define NUM_KEYS 8 // Number of buttons

#define KEY_1 'z'     // Macros go here; characters use quotation marks, modifiers use the ASCII table in the website below
#define KEY_2 'x'     // Change them here for your convenience
#define KEY_3 'c'     // Modifiers found at: https://www.arduino.cc/en/Reference/KeyboardModifiers
#define KEY_4 'w'     // Pressing multiple buttons at a time requires edits at the loop() sections of the code
#define KEY_5 'a'
#define KEY_6 's'
#define KEY_7 'd'
#define KEY_8 177

const int key[NUM_KEYS] = {/* Enter the pin numbers of your buttons here, separated by a comma */};        
int i = 0;

Bounce button[NUM_KEYS];

void setup() {

  // Start debouncing the switches
  for (i = 0; i < NUM_KEYS; i++) {
    button[i] = Bounce();                                     
    button[i].attach(key[i], INPUT_PULLUP); 
    button[i].interval(5);
  }

  // Start your keyboard functionality
  Keyboard.begin();

  // Start serial, to check for your keypresses
  Serial.begin(115200);
  Serial.println("Welcome to Keypad 1.0");
  Serial.println("Scanning buttons now...");
}

void loop() {
  for ( i = 0; i < NUM_KEYS; i++) {
    // Update the button states 
    button[i].update();
  }

/*
 * Button #1 - We start checking for keypresses
 * Repeat for the rest of the buttons
 */
  if (button[0].fell()){
    // Press and hold the buttons you want pressed
    Keyboard.press(KEY_1);

    /* If you would like to press more than one keyboard button at a time,
     * repeat Keyboard.press() for the extra set of buttons (up to six due to USB limitations) 
     * 
     * Like: 
     * Keyboard.press(KEY_1); 
     * Keyboard.press(KEY_2); 
     * Keyboard.press(KEY_3); 
     * ... 
     * Keyboard.press(KEY_6);
     */
    
  }
  if (button[0].rose()){
    // Release the same buttons you just pressed
    Keyboard.release(KEY_1);

   /* If you pressed more than one button, you have to release the rest of them
    * Repeat Keyboard.press() for the set of buttons pressed earlier (up to six due to USB limitations)
    *
    * Like:
    *
    * Keyboard.release(KEY_1);
    * Keyboard.release(KEY_2);
    * Keyboard.release(KEY_3);
    * ...
    * Keyboard.release(KEY_6);
    */
  }

/*
 * Button #2 - The second button, do the same as the first
 */
  if (button[1].fell()){
    // Press and hold the buttons you want pressed
    Keyboard.press(KEY_2);
  }
  if (button[1].rose()){
    Keyboard.release(KEY_2);
  }

  // ...
  // ...
  // Keep doing the above until you do all eight
 
}




