/*
	CSE 109: Spring 2018
	Dylan Spector
	drs320
	The C file for a linked-list object.
	Program #3
*/

#include"List.h"
#include"Node.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct List_t* makeList(struct List_t* it)
{
	it->size = 0;
	struct Node_t* newNode = (struct Node_t*)malloc(1 * sizeof(struct Node_t));
	newNode = makeNode1(newNode);
	it->headNode = newNode;
	return it;
}

struct List_t* freeList(struct List_t* it)
{
	struct Node_t* current = it->headNode;
	struct Node_t* next = getNext(it->headNode);

	if(size(it) == 0)
	{
		freeNode(current);
	}

	for(size_t i = 0; i < size(it); i++)
	{
		freeNode(current);
		current = next;
		next = getNext(current);
	}
    free(it);
    return NULL;
}

size_t size(struct List_t* it)
{
	return it->size;
}

struct Node_t* insert(struct List_t* it, int value)
{
    struct Node_t* current = it->headNode;
    struct Node_t* next = getNext(current);

	struct Node_t* newNode = (struct Node_t*)malloc(1 * sizeof(struct Node_t));
	newNode = makeNode2(newNode, value);

	if(size(it) == 0)
	{
		setData(current, getData(newNode));
		freeNode(newNode);
	}
	else
	{
		for(size_t i = 0; i < size(it); i++) // for every node in the list
    	{
    		if(next == NULL) // if current is the last node in the list
			{
				setNext(current, newNode);
			}
			current = next;
			next = getNext(current);
    	}
	}
	it->size++;
	return newNode;
}

size_t find(struct List_t* it, int value)
{
	size_t counter = 0;
	struct Node_t* current = it->headNode;
	for(size_t i = 0; i < size(it); i++) // ? size(it) or it->size
	{
		if(getData(current) == value)
		{
			counter++;
		}
		current = getNext(current);
	}
	return counter;
}

size_t traverse(struct List_t* it, char* string) // string is large enough
{
	if(it == NULL)
	{
		return 0;
	}
	struct Node_t* current = it->headNode;
	for(size_t i = 0; i < size(it); i++) // for every node in the list
	{
		if(i == size(it) - 1) // if the last node in the list
		{
			sprintf(string, "%s%d", string, getData(current));
		}
		else
		{
			sprintf(string, "%s%d, ", string, getData(current));
			current = getNext(current);
		}
	}
	return strlen(string);
}

size_t removeItem(struct List_t* it, int value)
{
	size_t numRemoved = 0;
	struct Node_t* previous = NULL;
	struct Node_t* current = it->headNode;
	struct Node_t* next = getNext(it->headNode);

	while(current != NULL)
	{
		if(getData(current) == value) // remove node
		{
			freeNode(current);
			it->size--;
            if(next == NULL) // If the current Node is the last in the list
            {
            	if(previous != NULL) // If not the only node in the list
				{
					setNext(previous, NULL);
          		}
			//	current = NULL; I think I can remove this!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }
			else if(previous == NULL) // If the current Node is the headNode
			{
				current = next; // it->headNode <-> current
				next = getNext(current);
			}
			else // If the current Node isn't the head or at the end
			{
				setNext(previous, next);
				current = next;
				next = getNext(next);
			}
			numRemoved++;
		}
		else
		{
			previous = current;
			current = next;
			next = getNext(current);
		}
	}
	return numRemoved;
}

char* traverse2(struct List_t* it)
{
	if(size(it) == 0)
	{
		return NULL;
	}

	char* string = (char *)calloc(1, ((12 * size(it))-2) * sizeof(char));
	traverse(it, string);
	return string;
}
