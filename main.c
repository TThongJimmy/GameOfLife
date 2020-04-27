#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // rand()

#define LENGTH 50 //长
#define WIDTH 50  //宽
#define ALIVE '*' //存活样式
#define DEAD ' '  //死亡样式

char map[LENGTH][WIDTH];
char tempMap[LENGTH][WIDTH];

// 初始化地图
void initMap(char *inputMap)
{
    // 初始化随机数
    srand((unsigned)time(NULL));

    char *p = inputMap;
    int x, y;
    for (x = 0; x < LENGTH; x++)
    {
        for (y = 0; y < WIDTH; y++)
        {
            // 使用指针对 map 数组每一位进行随机赋值生或死
            *p = (rand() % 2 ? ALIVE : DEAD);
            printf("%c", *p);
        }
        printf("\n");
    }
}

int main()
{
    initMap(map);
    return 0;
}