#ifndef MIGONG_H
#define MIGONG_H

#include<stdio.h>
#define M 8//定义迷宫的行数
#define N 8//定义迷宫的列数
#define MaxSize 100//定义栈的最大容量
extern int mg[M+2][N+2];

//定义一个Box结构体，存储方块的行数，列数还有方位
typedef struct {
    int i;//方块行号
    int j;//方块列号
    int di;//方块方位
} Box;

typedef struct {
    Box data[MaxSize];//存储方块的一个数组
    int top;//栈顶指针
} StType;//顺序栈类型



void InitStack(StType *st);
bool StackEmpty(StType *st);
void GetTop(StType *st, Box &e);
void Push(StType *st, Box e);
void Pop(StType *st, Box &e);
bool mgpath(int xi, int yi, int xe, int ye);

#endif // MIGONG_H
