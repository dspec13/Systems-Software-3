/*
	CSE 109: Spring 2018
	Dylan Spector
	drs320
	The C file for the NOde obj in a Linked List.
	Program #3
*/

#include"Node.h"
#include<stdio.h>
#include<stdlib.h>

struct Node_t* makeNode1(struct Node_t* it)
{
	it->value = 0;
	it->next = NULL;
	return it;
}

struct Node_t* makeNode2(struct Node_t* it, int value)
{
	it->value = value;
	it->next = NULL;
	return it;
}

struct Node_t* makeNode4(struct Node_t* it, int value, struct Node_t* next)
{
	it->value = value;
	it->next = next;
	return it;
}

struct Node_t* freeNode(struct Node_t* it)
{
	free(it);
	return NULL;
}

int setData(struct Node_t* it, int value)
{
	if(it == NULL)
	{
		return -1;
	}
	return it->value = value;
}

struct Node_t* setNext(struct Node_t* it, struct Node_t* next)
{
    if(it == NULL)
    {
        return NULL;
    }
    return it->next = next;
}

int getData(struct Node_t* it)
{
    if(it == NULL)
    {
        return -1;
    }
    return it->value;

}

struct Node_t* getNext(struct Node_t* it)
{
    if(it == NULL)
    {
        return NULL;
    }
    return it->next;
}
