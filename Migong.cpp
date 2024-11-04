#include "Migong.h"

int mg[M+2][N+2] = {
    {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,1,0,0,1},{1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};//���ﶨ����һ���Թ����飬1��ʾ�ϰ���0��ʾ����ͨ��

void InitStack(StType *st) {
    st->top = -1;
}//��ʼ��ջ
bool StackEmpty(StType *st) {
    return st->top == -1;
}//�ж�ջ�Ƿ�Ϊ��

void GetTop(StType *st, Box &e) {
    if (!StackEmpty(st)) {
        e = st->data[st->top];
    }
}//��ȡջ��Ԫ��

void Push(StType *st, Box e) {
    if (st->top < MaxSize - 1) {
        st->data[++st->top] = e;
    }
}//��ջ��ѹ��һ��Ԫ��

void Pop(StType *st, Box &e) {
    if (!StackEmpty(st)) {
        e = st->data[st->top--];
    }
}//��ջ��ȡ��һ��Ԫ��


//�Թ���������xi yi xe ye �ֱ��ʾ�����յ�
bool mgpath(int xi, int yi, int xe, int ye) {
    Box path[MaxSize], e;//path�Ǵ洢·�������飬e��ʾ��ǰ�ķ���
    int i, j, i1, j1, k, di;
    bool find;//����Ƿ�����ҵ�·��
    StType *st = new StType;
    InitStack(st);//��ʼ��ջ
    e.i = xi; e.j = yi; e.di = -1;//��㸳ֵ��e
    Push(st, e);
    mg[xi][yi] = -1;//�������Ѿ�����
    while (!StackEmpty(st)) {
        GetTop(st, e);
        i = e.i; j = e.j; di = e.di;
        //�ҵ��յ�
        if (i == xe && j == ye) {
            printf("һ���Թ�·�����£�\n");
            k = 0;//��ʼ��
            while (!StackEmpty(st)) {
                Pop(st, e);//����e
                path[k++] = e;
            }
            while (k > 0) {
                printf("\t(%d,%d)", path[k-1].i, path[k-1].j);
                if ((k+1) % 5 == 0)
                    printf("\n");
                k--;
            }
            printf("\n");
            return true;
        }
        find = false;
        //ʧ��
        while (di < 4 && !find) {
            di++;
            switch (di) {
                case 0: i1 = i - 1; j1 = j; break;//��
                case 1: i1 = i; j1 = j + 1; break;//��
                case 2: i1 = i + 1; j1 = j; break;//��
                case 3: i1 = i; j1 = j - 1; break;//��
            }
            if (mg[i1][j1] == 0) find = true;
        }
        //����
        if (find) {
            st->data[st->top].di = di;
            e.i = i1; e.j = j1; e.di = -1;
            Push(st, e);//����ջ
            mg[i1][j1] = -1;//���
        } else {
            Pop(st, e);
            mg[e.i][e.j] = 0;
        }
    }
    return false;
}
