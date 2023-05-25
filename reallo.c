#include "shell.h"

/**
 * _fillMemoryBlock - fills a block of memory with a constant byte
 * @block: pointer to memory area
 * @byte: the byte to fill the memory area with
 * @size: the number of bytes to be filled
 * Return: pointer to the memory area block
 */

char *_fillMemoryBlock(char *block, char byte, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		block[i] = byte;
	return (block);
}

/**
 * free_str_array - frees a block of memory that contains an array of str
 * @stringArray: The array of strings to be freed
 */

void free_str_array(char **stringArray)
{
	char **temp = stringArray;

	if (!stringArray)
		return;
	while (*stringArray)
		free(*stringArray++);
	free(temp);
}

/**
 * reallocMemBlock - function reallocates a block of memory.
 * @ptr: Pointer to the previous block of memory
 * @oldSize: The size of the previous block of memory in bytes
 * @newSize: The size of the new block of memory in bytes
 * Return: A pointer to the reallocated block of memory.
 */

void *reallocMemBlock(void *ptr, unsigned int oldSize, unsigned int newSize)
{
	char *newBlock;

	if (!ptr)
		return (malloc(newSize));
	if (!newSize)
		return (free(ptr), NULL);
	if (newSize == oldSize)
		return (ptr);

	newBlock = malloc(newSize);
	if (!newBlock)
		return (NULL);

	oldSize = oldSize < newSize ? oldSize : newSize;
	while (oldSize--)
		newBlock[oldSize] = ((char *)ptr)[oldSize];
	free(ptr);
	return (newBlock);
}
