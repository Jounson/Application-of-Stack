#pragma once
#ifndef _MYSTACK_H_
#define _MYSTACK_H_

/* 栈的链式存储，链表节点的数据结构 */
typedef struct _Point
{
	int _x;
	int _y;
}Point;
/* 栈的链式存储，链表节点的数据结构 */
typedef struct _Node
{
	Point data;
	struct _Node* next;
}Node;
typedef struct _Stack
{
	Node* top;
}Stack;
void initStack(Stack*);
bool isStackFull(Stack* s);
bool isStackEmpty(Stack* s);
void push(Stack* s, Point ch);
Point pop(Stack* s);
void clearStack(Stack* s);
void resetStack(Stack* s);


#endif