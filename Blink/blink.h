/*
 * blink.h
 *
 *  Created on: Sep 7, 2022
 *      Author: admin
 */

#ifndef BLINK_H_
#define BLINK_H_

#include <stm32f4xx_hal.h>

typedef struct{
	uint8_t state;
	uint32_t tick;
	GPIO_TypeDef *Port;
	uint16_t Pin;
	uint32_t interval;
}blink_t;

void blink_init(blink_t *blink, GPIO_TypeDef *Port, uint16_t Pin, uint32_t interval);
void blink_process(blink_t *blink);

#endif /* BLINK_H_ */
