/*
 * circular_buffer.c
 *
 *  Created on: 7 de jun de 2018
 *      Author: otavio
 */

#include "circular_buffer.h"

void CircularBuffer_Init(uint8_t *buff, circular_list_t *list, uint32_t count){
	list->buffer = buff;

	list->readP = buff;
	list->writeP = buff;

	list->listEnd = (buff + (sizeof(uint8_t) * count));
	list->itemCount = 0;
}

uint8_t CircularBuffer_Read(circular_list_t *buffer){
	uint8_t result = *buffer->readP;

	buffer->itemCount--;
	buffer->readP++;
	if(buffer->readP == buffer->listEnd)
		buffer->readP = buffer->buffer;

	return result;
}

uint32_t CircularBuffer_ReadList(circular_list_t *buffer, uint8_t *values){
	uint32_t items = buffer->itemCount;

	for(uint32_t idx = 0; idx < items; idx++){
		values[idx] = *buffer->readP;

		buffer->itemCount--;
		buffer->readP++;
		if(buffer->readP == buffer->listEnd)
			buffer->readP = buffer->buffer;
	}

	return items;
}

void CircularBuffer_Write(circular_list_t *buffer, uint8_t value){
	(*buffer->writeP) = value;

	buffer->itemCount++;
	buffer->writeP++;
	if(buffer->writeP == buffer->listEnd)
		buffer->writeP = buffer->buffer;
}

void CircularBuffer_WriteList(circular_list_t *buffer, uint8_t *values, uint32_t length){
	for(uint32_t idx = 0; idx < length; idx++){
		(*buffer->writeP) = values[idx];

		buffer->itemCount++;
		buffer->writeP++;
		if(buffer->writeP == buffer->listEnd)
			buffer->writeP = buffer->buffer;
	}
}
