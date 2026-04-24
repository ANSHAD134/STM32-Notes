/*
 * Simple_Queue.c
 *
 *  Created on: 23-Apr-2026
 *      Author: HP
 */

#include <string.h>
#include "Simple_Queue.h"

void queue_init(simple_queue_t *q, void *buffer, uint32_t item_size, uint32_t capacity)
{
	q->buffer = (uint8_t *)buffer;
	q->item_size = item_size;
	q->capacity = capacity;
	q->head = 0;
	q->tail = 0;
	q->count = 0;

	q->mutex = xSemaphoreCreateMutex();
}

int queue_is_full(simple_queue_t *q)
{
	return (q->count == q->capacity);
}

int queue_is_empty(simple_queue_t *q)
{
	return (q->count == 0);
}

int queue_push(simple_queue_t *q, const void *item)
{
	bool result = false;

	if(xSemaphoreTake(q->mutex, portMAX_DELAY) == pdTRUE)
	{
		if(!queue_is_full(q))
		{
			memcpy(&q->buffer(q->tail * q->item_size), item, q->item_size);
			q->tail = (q->tail + 1) % q->capacity;
			q->count++;
			result = true;
		}

		xSemaphoreGive(q->mutex);
	}
	return result;
}

int queue_pop(simple_queue_t *q, void *out)
{
	bool result = false;

	if(xSemaphoreTake(q->mutex, portMAX_DELAY) == pdTRUE)
	{
		if(!queue_is_empty(q))
		{
			memcpy(out, &q->buffer(q->head * q->item_size), item, q->item_size);
			q->head = (q->tail + 1) % q->capacity;
			q->count--;
			result = true;
		}

		xSemaphoreGive(q->mutex);
	}
	return result;
}
