#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include"mystack.h"
#include<windows.h>
/* 等价于 #define MAXROW 10 */
constexpr auto MAXROW = 10;
constexpr auto MAXLINE = 10;
using namespace std;
/* 全局变量s */
Stack s;
/* 1代表墙，0代表通路，2代表走过的路 */
int maze[MAXROW][MAXLINE] =
{
	1,1,1,1,1,1,1,1,1,1,
	0,0,0,1,1,1,1,1,1,1,
	1,1,0,1,1,1,1,1,1,1,
	1,1,0,0,0,0,1,1,1,1,
	1,1,0,1,1,0,1,1,1,1,
	1,1,0,1,1,0,1,1,1,1,
	1,1,1,1,1,0,1,1,1,1,
	1,1,1,1,1,0,0,0,1,1,
	1,1,1,1,1,1,1,0,0,0,
	1,1,1,1,1,1,1,1,1,1,
};
/* 地形图遍历函数 */
void displayMaze()
{
	for (int i = 0; i < MAXROW; i++)
	{
		for (int j = 0; j < MAXLINE; j++)
		{
			/* *代表墙 */
			if (maze[i][j] == 1)printf("%2s", " *");
			/* $代表走过的路径 */
			else if (maze[i][j] == 2)printf("%2s", "$");
			/* ' '代表通路 */
			else printf("%2s", " ");
		}
		putchar(10);
	}
	printf("====================\n");
}
/* 刷新压栈函数 */
void visit(int x, int y)
{
	Point p = { x,y };
	push(&s, p);
}
int main()
{
	/* 通路的起点 */
	Point sp = { 1,0 };
	/* 通路的终点 */
	Point ep = { 8,9 };
	/* 初始化栈 */
	initStack(&s);
	/* 将起点压入栈中 */
	push(&s, sp);
	/* 定义一个标志变量 */
	int flag = 0;
	/* 如果栈不为空 */
	while (!isStackEmpty(&s))
	{
		/* 定义一个Point类型的变量t */
		Point t;
		/* 将栈弹出的节点暂存到t中 */
		t = pop(&s);
		/* 将栈某点弹出后，将该点填充为2，以防止重蹈覆辙 */
		maze[t._x][t._y] = 2;
		/* 清屏 */
		system("cls");
		/* 每次从栈中弹出一个节点，都将地形图打印一次，显示此时走到那一步了 */
		displayMaze();
		/* 为了使得现象更加直观，延时一下 */
		Sleep(1000);

		/* 下面的四个if条件用来判断边界用的 */
		/* 上 */   /* 判断==2？表示走过的路，==1？表示是否是墙 */
		if (t._x - 1 >= 0 && maze[t._x-1][t._y] != 1 && maze[t._x-1][t._y] != 2)
			visit(t._x-1,t._y);
		/* 下 */
		if (t._x + 1 <= 9 && maze[t._x + 1][t._y] != 1 && maze[t._x + 1][t._y] != 2)
			visit(t._x+1, t._y);
		/* 左 */
		if (t._y - 1 >= 0 && maze[t._x][t._y-1] != 1 && maze[t._x][t._y-1] != 2)
			visit(t._x, t._y-1);
		/* 右 */
		if (t._y + 1 <= 9 && maze[t._x][t._y + 1] != 1 && maze[t._x][t._y + 1] != 2)
			visit(t._x, t._y+1);

		if (t._x == ep._x && t._y == ep._y)
		{
			flag = 0;
			break;
		}
	}
	/* 如果确实是找到路径的终点了，就打印一句 */
	if (flag == 0)
		printf("find path");
	else
		printf("find no path");
	return 0;
}
