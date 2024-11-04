#include "Migong.h"

int main() {
    if (!mgpath(1, 1, M, N))//起点为（1，1）终点为（M，N）
        printf("该迷宫无解");
    return 0;
}
