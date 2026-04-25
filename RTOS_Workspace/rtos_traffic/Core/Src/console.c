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


static command_msg_t cmd_buffer[CMD_QUEUE_SIZE];
static simple_queue_t cmdQueue;

static const char * CONSOLE_QUEUE_ERROR_MSG = "Application Queue Full\n";

extern UART_HandleTypeDef huart2;
volatile bool g_traffic_enable;
volatile uint32_t g_red_duration;
volatile uint32_t g_green_duration;
volatile uint32_t g_yellow_duration;

int console_init(void)
{
    bool b_return_status = true;
    char banner[128];

    queue_init(&cmdQueue, cmd_buffer, sizeof(command_msg_t), CMD_QUEUE_SIZE);

    snprintf(banner, sizeof(banner),
             "\n"
             "====== RTOS EXAMPLE ======\n"
             "======== v%d.%d =========\n"
             "=========================\n",
             APP_VERSION_MAJOR,
             APP_VERSION_MINOR);

    if (HAL_OK != HAL_UART_Transmit(&huart2, (uint8_t *)banner, strlen(banner), CONSOLE_UART_TX_TIMEOUT))
    {
        b_return_status = false;
    }

    return b_return_status;
}

void receive_command(void const * argument)
{
    char c_temp_buffer[26] = {0};
    uint8_t c_current_char;
    int32_t pos = 0;

    for(;;)
    {
        if (HAL_UART_Receive(&huart2, &c_current_char, 1, CONSOLE_UART_RX_TIMEOUT) == HAL_OK)
        {
            if (c_current_char != '\r' && c_current_char != '\n')
            {
                c_temp_buffer[pos++] = c_current_char;
            }
            else
            {
                c_temp_buffer[pos] = '\0';
                process_command(c_temp_buffer);
                pos = 0;
            }
        }

        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

void process_command(char *command)
{
    char *token;
    command_msg_t msg;

    msg.type = CMD_UNKNOWN;
    msg.param = 0;

    token = strtok(command, " ");
    if (token == NULL) return;

    if (strcmp(token, "system") == 0)
    {
        char *arg = strtok(NULL, " ");
        if (arg != NULL)
        {
            if (strcmp(arg, "on") == 0)
            {
                msg.type = CMD_SYSTEM_ON;
            }
            else if (strcmp(arg, "off") == 0)
            {
                msg.type = CMD_SYSTEM_OFF;
            }
            else
            {
                msg.type = CMD_UNKNOWN;
            }
        }
    }
    else if (strcmp(token, "red") == 0)
    {
        msg.type = CMD_RED;
        msg.param = atoi(strtok(NULL, " "));
    }
    else if (strcmp(token, "red") == 0)
    {
        msg.type = CMD_RED;
        msg.param = atoi(strtok(NULL, " "));
    }
    else if (strcmp(token, "green") == 0)
    {
        msg.type = CMD_GREEN;
        msg.param = atoi(strtok(NULL, " "));
    }
    else if (strcmp(token, "yellow") == 0)
    {
        msg.type = CMD_YELLOW;
        msg.param = atoi(strtok(NULL, " "));
    }
    else if (strcmp(token, "temp") == 0)
    {
        msg.type = CMD_TEMP;
    }
    else if (strcmp(token, "log") == 0)
    {
        msg.type = CMD_LOG;
    }
    else
    {
        msg.type = CMD_UNKNOWN;
    }

    if (!queue_push(&cmdQueue, &msg))
    {
        HAL_UART_Transmit(&huart2,
                          (uint8_t *)CONSOLE_QUEUE_ERROR_MSG,
                          strlen(CONSOLE_QUEUE_ERROR_MSG),
                          CONSOLE_UART_TX_TIMEOUT);
    }
}

static void uart_send_str(const char *s)
{
    if (s == NULL)
        return;

    HAL_UART_Transmit(&huart2, (uint8_t *)s, strlen(s), CONSOLE_UART_TX_TIMEOUT);
}

void respond_command(void const * argument)
{
    (void)argument;
    command_msg_t msg;
    char out[64];

    for (;;)
    {
        if (queue_pop(&cmdQueue, &msg))
        {
            switch ((command_type_t)msg.type)
            {
                case CMD_SYSTEM_ON:
                    g_traffic_enable = true;
                    snprintf(out, sizeof(out), "System: ON\r\n");
                    uart_send_str(out);
                    break;

                case CMD_SYSTEM_OFF:
                    g_traffic_enable = false;
                    snprintf(out, sizeof(out), "System: OFF\r\n");
                    uart_send_str(out);
                    break;

                case CMD_RED:
                    if (msg.param <= 0)
                    {
                        snprintf(out, sizeof(out), "RED: invalid param %d\r\n", msg.param);
                    }
                    else
                    {
                        g_red_duration = msg.param;
                        snprintf(out, sizeof(out), "RED: %d\r\n", msg.param);
                    }
                    uart_send_str(out);
                    break;

                case CMD_GREEN:
                    if (msg.param <= 0)
                    {
                        snprintf(out, sizeof(out), "GREEN: invalid param %d\r\n", msg.param);
                    }
                    else
                    {
                        g_green_duration = msg.param;
                        snprintf(out, sizeof(out), "GREEN %d\r\n", msg.param);
                    }
                    uart_send_str(out);
                    break;

                case CMD_YELLOW:
                    if (msg.param <= 0)
                    {
                        snprintf(out, sizeof(out), "YELLOW: invalid param %d\r\n", msg.param);
                    }
                    else
                    {
                        g_yellow_duration = msg.param;
                        snprintf(out, sizeof(out), "YELLOW %d\r\n", msg.param);
                    }
                    uart_send_str(out);
                    break;

                default:
                	snprintf(out, sizeof(out), "ERROR: UNKNOWN CMD\r\n");
					uart_send_str(out);
                	break;
            }
        }

              vTaskDelay(pdMS_TO_TICKS(10));
    }
}
