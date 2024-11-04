#ifndef MIGONG_H
#define MIGONG_H

#include<stdio.h>
#define M 8//�����Թ�������
#define N 8//�����Թ�������
#define MaxSize 100//����ջ���������
extern int mg[M+2][N+2];

//����һ��Box�ṹ�壬�洢������������������з�λ
typedef struct {
    int i;//�����к�
    int j;//�����к�
    int di;//���鷽λ
} Box;

typedef struct {
    Box data[MaxSize];//�洢�����һ������
    int top;//ջ��ָ��
} StType;//˳��ջ����



void InitStack(StType *st);
bool StackEmpty(StType *st);
void GetTop(StType *st, Box &e);
void Push(StType *st, Box e);
void Pop(StType *st, Box &e);
bool mgpath(int xi, int yi, int xe, int ye);

#endif // MIGONG_H
