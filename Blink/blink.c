/*
 * blink.c
 *
 *  Created on: Sep 7, 2022
 *      Author: admin
 */
#include <string.h>
#include "blink.h"

void blink_init(blink_t *blink, GPIO_TypeDef *Port, uint16_t Pin, uint32_t interval)
{
	memset(blink, 0, sizeof(blink_t));
	blink->Port = Port;
	blink->Pin = Pin;
	blink->interval = interval;
}

void blink_process(blink_t *blink)
{
	if(HAL_GetTick() - blink->tick > blink->interval)
	{
	  blink->state = !blink->state;
	  HAL_GPIO_WritePin(blink->Port, blink->Pin, blink->state);
	  blink->tick = HAL_GetTick();
	}
}
