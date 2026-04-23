/*
 * Traffic.c
 *
 *  Created on: 23-Apr-2026
 *      Author: HP
 */

#include <stdbool.h>
#include "main.h"
#include "cmsis_os.h"
#include "Traffic.h"

#define TOGGLE_INTERVAL		300

Led_Status_t g_taffic_light_state = UNDEFINED_STATE;
volatile bool g_traffic_enable = false;
volatile uint32_t g_red_duration = 0;
