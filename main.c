#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // rand()

#define MAX_X 50  //长
#define MAX_Y 50  //宽
#define ALIVE '*' //存活样式
#define DEAD ' '  //死亡样式

char map[MAX_X][MAX_Y];
char tempMap[MAX_X][MAX_Y];

// 初始化地图
void initMap(char *inputMap)
{
    // 初始化随机数
    srand((unsigned)time(NULL));

    char *p = inputMap;
    int x, y;
    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            // 使用指针对 map 数组每一位进行随机赋值生或死
            *p = (rand() % 2 ? ALIVE : DEAD);
            printf("%c", *p);
            p++;
        }
        printf("\n");
    }
}

// 计算周围有多少个生命
int countLive(int x, int y)
{
    int num = 0;
    int i, j;

    // 防止越界读取数组元素
    // 当 x 在边界的时候，只从同列开始读取
    for ((x == 0) ? (i = 0) : (i = -1); i <= ((x == MAX_X) ? 0 : 1); i++)
    {
        for ((y == 0) ? (j = 0) : (j = -1); j <= ((j == MAX_Y) ? 0 : 1); j++)
        {
            // 跳过自己
            if (i == 0 && j == 0)
                continue;
            if (map[x + i][y + j] == ALIVE)
                num++;
        }
    }

    return num;
}

int main()
{
    initMap(map);
    printf("\n\n%d\n", countLive(0, 0));
    return 0;
}