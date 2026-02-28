/*
 * RA6M1.h
 *
 *  Created on: 28-Feb-2026
 *      Author: HP
 */

#ifndef INC_RA6M1_H_
#define INC_RA6M1_H_

#define __vo		volatile

/*
 * Memory Base Addresses
 */
#define PERIPH_BASEADDR					40100000U
#define PERIPH_BUS_1					40000000U
#define PERIPH_BUS_3					40040000U
#define PERIPH_BUS_4					40060000U
#define PERIPH_BUS_5					40080000U

/*
 * Peripheral register definition structure for I/O ports
 */

typedef struct
{
	__vo uint32_t	PCNTR1;						// Port Control Register 1
	__vo uint32_t	PCNTR2;						// Port Control Register 2
	__vo uint32_t	PCNTR3;						// Port Control Register 3
	__vo uint32_t	PCNTR4;						// Port Control Register 4
	__vo uint32_t	PmnPFS;						// Port mn Pin Function Select Register
	__vo uint32_t	PWPR;						// Write-Protect Register
}GPIO_Regdef_t;



#endif /* INC_RA6M1_H_ */
