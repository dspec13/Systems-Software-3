/*
	CSE 109: Spring 2018
	Dylan Spector
	drs320
	The header file for a linked-list object.
	Program #3
*/

#ifndef LIST_H
#define LIST_H

#include"Node.h"
#include<stdio.h>

struct List_t
{
	size_t size;
	struct Node_t* headNode;
};

struct List_t* makeList(struct List_t* it);
struct List_t* freeList(struct List_t* it);
size_t size(struct List_t* it);
struct Node_t* insert(struct List_t* it, int value);
size_t find(struct List_t* it, int value);
size_t traverse(struct List_t* it, char* string);
size_t removeItem(struct List_t* it, int value);
char* traverse2(struct List_t* it);

#endif
