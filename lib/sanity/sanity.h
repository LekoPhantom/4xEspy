#pragma once

/**  Sanity check functions for the ESP32-C3. These are used to verify that the serial communication is working correctly.
Put your header declarations here. You can also put them in other header files and include them here.
*/
// Initializes the serial communication and prints a message indicating that the serial connection is working, tagged with the provided string.
void sanity_serial(const char* tag);
// Prints detailed information about the board, including chip model, flash size, CPU frequency, SDK version, and MAC address.
void sanity_board_info(const char* tag);
//
void sanity_espnow(const char* tag);
