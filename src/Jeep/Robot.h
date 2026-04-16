#pragma once

#include <stdint.h>
//#include "espy_roles.h"
//#include "espy_packets.h"

// ------------------------------------------------------------
// Jeep Role
// ------------------------------------------------------------
//static constexpr uint8_t JEEP_ROLE = ESPY_ROLE_JEEP;

// ------------------------------------------------------------
// Robot Lifecycle
// ------------------------------------------------------------

// Called once at startup.
// Initialize IO, motors, sensors, safety, etc.
void robot_init();

// Called every loop iteration.
// Read sensors, update state, send packets, run control logic.
void robot_update();

// Called when a packet arrives from the controller or other nodes.
//void robot_handle_packet(const EspyPacket& packet);

