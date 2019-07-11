#include"pch.h"
#include"mystack.h"
#include<stdlib.h>

void initStack(Stack* s)
{
	s->top = (Node*)malloc(sizeof(Node));
	s->top->next = NULL;
}
bool isStackFull(Stack* s) { return 0; }
bool isStackEmpty(Stack* s)
{
	return s->top->next == NULL;
}
/* 压栈操作函数，向栈中压入节点 */
void push(Stack* s, Point ch)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = ch;
	cur->next = s->top->next;
	s->top->next = cur;
}
/* 出栈函数，将节点弹出 */
Point pop(Stack* s)
{
	/* 初始化一个的作用是记录一下 */
	Node* t = s->top->next;
	/* 既要释放t，又要返回其中的数据，所以定义一个变量ch来暂存一下，用于返回 */
	Point ch = t->data;
	/* 将节点弹出后，把链表再连起来 */
	s->top->next = t->next;
	/* 释放掉出栈的节点 */
	free(t);
	/* 弹出的节点，将节点的数据返回 */
	return ch;
}
/* 清空栈或者销毁栈的函数 */
void clearStack(Stack* s)
{
	/* 节点全部压出 */
	resetStack(s);
	/* 此时，将节点全部压出，释放掉头指针 */
	free(s->top);
}
/* 将栈恢复到初始状态，一个节点也没有 */
void resetStack(Stack* s)
{
	/* 只要链表不为空，就将节点压出 */
	while (!isStackEmpty(s))
	{
		pop(s);
	}
}