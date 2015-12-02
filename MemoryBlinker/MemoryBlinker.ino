/*
 * Iterate through memory
 * and blink the on-board LED depending on
 * whether the byte at the current address
 * is greater than or less than half the scale
 * between 0 and 255. In practice, this makes the LED
 * look like it is blinking randomly.
 *
 * Normally, dereferencing NULL will crash your program.
 * This is different on an Arduino since there's nothing
 * in the archetecture to trigger a segfault.
 */

/*
 * Pointer to a constant byte. This is our
 * cursor, we will start it at NULL and iterate through
 * memory. Note that only ever read values from this pointer,
 * I do not wish to write to an arbitrary memory address and risk
 * bricking my Arduino board.
 */
byte const * current_byte;

void setup() {
    Serial.begin(9600);
    current_byte = NULL;
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    // Print "addresss: value"
    Serial.print((uint32_t) current_byte);
    Serial.print(": ");
    Serial.println(*current_byte);

    //If the value is large, turn the LED on, else leave it off
    if (*current_byte > 127)
        digitalWrite(PIN_LED, HIGH);
    else
        digitalWrite(PIN_LED, LOW);
    delay(100);

    //Go to the next byte in memory
    current_byte++;
}
