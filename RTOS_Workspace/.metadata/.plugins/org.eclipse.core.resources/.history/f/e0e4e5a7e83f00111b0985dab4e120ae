/*
 * console.c
 *
 *  Created on: 24-Apr-2026
 *      Author: HP
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "stm32f4xx_hal.h"
#include "Simple_Queue.h"
#include "Version.h"
#include "Task.h"
#include "console.h"

#define CMD_QUEUE_SIZE	10



volatile bool g_traffic_enable;
volatile uint32_t g_red_duration;
volatile uint32_t g_green_duration;
volatile uint32_t g_yellow_duration;
