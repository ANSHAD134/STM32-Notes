/*
 * console.h
 *
 *  Created on: 24-Apr-2026
 *      Author: HP
 */

#ifndef INC_CONSOLE_H_
#define INC_CONSOLE_H_

#define CONSOLE_UART_TX_TIMEOUT 100
#define CONSOLE_UART_RX_TIMEOUT 10

typedef enum
{
    CMD_SYSTEM_ON,
    CMD_SYSTEM_OFF,
    CMD_RED,
    CMD_GREEN,
    CMD_YELLOW,
    CMD_TEMP,
    CMD_LOG,
    CMD_UNKNOWN
} command_type_t;

typedef struct
{
    command_type_t type;
    uint32_t param;   		// used for red/green/yellow
} command_msg_t;

void console_init(void);
void receive_command(void const * argument);
void respond_command(void const * argument);
void process_command(char *command);

#endif /* INC_CONSOLE_H_ */
