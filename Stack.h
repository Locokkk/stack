#pragma once


#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int STDataType;
struct Stack
{
	STDataType* _array;
	int _top;
	int _capacity;
};

typedef struct Stack Stack;

void StackInit(Stack *ps);
void StackDestory(Stack *ps);
void StackPush(Stack *ps, STDataType x);
void StackPop(Stack *ps);
STDataType StackTop(Stack *ps);
size_t StackSize(Stack *ps);
bool StackEmpty(Stack *ps);

void StackInit(Stack *ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack *ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;

}

void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0 ? 4 : ps->_capacity * 2);
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		assert(ps->_array);
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack *ps)
{
	assert(ps&&ps->_top > 0);
	ps->_top--;
}
STDataType StackTop(Stack *ps)
{
	assert(ps&&ps->_top > 0);
	return ps->_array[ps->_top - 1];
}
bool StackEmpty(Stack *ps)
{
	assert(ps);
	return ps->_top == 0;
}
size_t StackSize(Stack *ps)
{
	assert(ps);
	return ps->_top;
}

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	StackDestory(&s);
}

