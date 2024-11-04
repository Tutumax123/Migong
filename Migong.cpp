#include "Migong.h"

int mg[M+2][N+2] = {
    {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,1,0,0,1},{1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};//这里定义了一个迷宫数组，1表示障碍，0表示可以通行

void InitStack(StType *st) {
    st->top = -1;
}//初始化栈
bool StackEmpty(StType *st) {
    return st->top == -1;
}//判断栈是否为空

void GetTop(StType *st, Box &e) {
    if (!StackEmpty(st)) {
        e = st->data[st->top];
    }
}//获取栈顶元素

void Push(StType *st, Box e) {
    if (st->top < MaxSize - 1) {
        st->data[++st->top] = e;
    }
}//向栈中压入一个元素

void Pop(StType *st, Box &e) {
    if (!StackEmpty(st)) {
        e = st->data[st->top--];
    }
}//从栈中取出一个元素


//迷宫搜索函数xi yi xe ye 分别表示起点和终点
bool mgpath(int xi, int yi, int xe, int ye) {
    Box path[MaxSize], e;//path是存储路径的数组，e表示当前的方块
    int i, j, i1, j1, k, di;
    bool find;//标记是否可以找到路径
    StType *st = new StType;
    InitStack(st);//初始化栈
    e.i = xi; e.j = yi; e.di = -1;//起点赋值给e
    Push(st, e);
    mg[xi][yi] = -1;//标记起点已经访问
    while (!StackEmpty(st)) {
        GetTop(st, e);
        i = e.i; j = e.j; di = e.di;
        //找到终点
        if (i == xe && j == ye) {
            printf("一条迷宫路径如下：\n");
            k = 0;//初始化
            while (!StackEmpty(st)) {
                Pop(st, e);//弹出e
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
        //失败
        while (di < 4 && !find) {
            di++;
            switch (di) {
                case 0: i1 = i - 1; j1 = j; break;//上
                case 1: i1 = i; j1 = j + 1; break;//右
                case 2: i1 = i + 1; j1 = j; break;//下
                case 3: i1 = i; j1 = j - 1; break;//左
            }
            if (mg[i1][j1] == 0) find = true;
        }
        //可行
        if (find) {
            st->data[st->top].di = di;
            e.i = i1; e.j = j1; e.di = -1;
            Push(st, e);//存入栈
            mg[i1][j1] = -1;//标记
        } else {
            Pop(st, e);
            mg[e.i][e.j] = 0;
        }
    }
    return false;
}
