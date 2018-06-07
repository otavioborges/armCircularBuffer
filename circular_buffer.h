/*
 * circular_buffer.h
 *
 *  Created on: 7 de jun de 2018
 *      Author: otavio
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdint.h>

typedef struct{
	uint8_t *buffer;
	uint8_t *readP;
	uint8_t *writeP;

	uint8_t *listEnd;
	uint32_t itemCount;
} circular_list_t;

void CircularBuffer_Init(uint8_t *buffer, circular_list_t *list, uint32_t count);
uint8_t CircularBuffer_Read(circular_list_t *buffer);
void CircularBuffer_Write(circular_list_t *buffer, uint8_t value);
void CircularBuffer_WriteList(circular_list_t *buffer, uint8_t *values, uint32_t length);

#endif /* CIRCULAR_BUFFER_H_ */
