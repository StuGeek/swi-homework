#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNACK_MAX_LENGTH 20
#define SNACK_HEAD 'H'
#define SNACK_BODY 'X'
#define BLANK_CELL ' '
#define SNACK_FOOD '$'
#define WALL_CELL '*'
#define HEAD_X snakeX[snakeLength - 1] //记录贪吃蛇头部的横坐标
#define HEAD_Y snakeY[snakeLength - 1] //记录贪吃蛇头部的纵坐标
#define BOOL int
#define TRUE 1
#define FALSE 0

//记录坐标位置，用来生成食物
typedef struct{
	int x_index;
	int y_index;
} Index;

/*
主函数中要使用的控制贪吃蛇的移动的函数，
具体实现由向四个方向移动的函数、
判断游戏状态的函数、
改变地图函数和结束游戏函数组成
*/
void snakeMove(int, int);

//向四个方向移动的函数，具体实现包括一个贪吃蛇身体移动函数
void moveTop();
void moveDown();
void moveLeft();
void moveRight();
//贪吃蛇身体移动函数，里面包括一个记录原先贪吃蛇的尾部位置的函数
void bodyMove();
//记录贪吃蛇原先的尾部的位置的函数
void recordTail();

//判断游戏状态的函数，包括判断是否碰到身体、墙、食物的函数和碰到食物后增加贪吃蛇身体长度的函数
BOOL judgeGameSituation();
//判断是否碰到身体、墙、食物的函数
BOOL isHitTheBody();
BOOL isHitTheWall();
BOOL isHitTheFood();
//碰到食物后增加贪吃蛇身体长度的函数
void increaseTheBodyLength();

//贪吃蛇移动了后，改变地图的函数，里面包括一个生成食物的函数
void changeTheMap();
//生成食物的函数，里面包括一个找到可以放食物位置坐标的函数
void put_money(void);
//随机生成的找到可以放食物位置坐标的函数，当坐标位置的样式为' '，才会返回这个坐标
Index find_BLANK_CELL();

//结束游戏的函数
void gameover(void);

//主函数中用到输出地图函数
void output(void);

char map[12][12] = 
    {"************",
    "*XXXXH     *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************"};

int snakeX[SNACK_MAX_LENGTH] = {1, 2, 3, 4, 5};
int snakeY[SNACK_MAX_LENGTH] = {1, 1, 1, 1, 1};
int tailX = 1;
int tailY = 1;
int snakeLength = 5;
BOOL isEatTheFood = FALSE; //记录贪吃蛇一次的移动之后，有没有吃到食物

/*
控制贪吃蛇的移动的函数
具体实现由向四个方向移动的函数、
判断游戏状态的函数、
改变地图函数和
结束游戏函数组成
*/

void snakeMove(int dx, int dy){
    //根据在x坐标和y坐标移动的距离确定是向上下左右哪个方向移动，分别用四个移动方向函数实现
	if (dx == 0 && dy == 1) moveTop();
	else if (dx == 0 && dy == -1) moveDown();
	else if (dx == 1 && dy == 0) moveRight();
	else if (dx == -1 && dy == 0) moveLeft();
    //判断此时游戏的状态，如果可以进行，那么改变地图的样式，否则结束游戏
    if (judgeGameSituation()) changeTheMap();
    else gameover();
}

/*
具体实现贪吃蛇向四个方向移动的函数
不管向哪个方向移动，贪吃蛇的身体肯定都会移动，用一个函数实现
贪吃蛇的头部的坐标数值对应改变
*/

//向上移动，贪吃蛇的身体移动，贪吃蛇的头部的横坐标不变，纵坐标减一
void moveTop(){
    bodyMove();
    HEAD_Y -= 1;
}

//向下移动，贪吃蛇的身体移动，贪吃蛇的头部的横坐标不变，纵坐标加一
void moveDown(){
    bodyMove();
    HEAD_Y += 1;
}

//向左移动，贪吃蛇的身体移动，贪吃蛇的头部的纵坐标不变，横坐标减一
void moveLeft(){
    bodyMove();
    HEAD_X -= 1;
}

//向右移动，贪吃蛇的身体移动，贪吃蛇的头部的纵坐标不变，横坐标加一
void moveRight(){
    bodyMove();
    HEAD_X += 1;
}

/*
具体实现贪吃蛇的身体移动的函数，其中要记录移动前贪吃蛇尾部的坐标，方便改变地图。
将贪吃蛇的横坐标数组和纵坐标数组从0到倒数第二个都向后移一位，表示贪吃蛇的身体移动
*/

void bodyMove(){
    recordTail();
    for (int i = 0; i < snakeLength - 1; ++i){
        snakeX[i] = snakeX[i + 1];
        snakeY[i] = snakeY[i + 1];
    }
}

/*
具体实现记录贪吃蛇身体移动前尾部的坐标的函数
*/

void recordTail(){
    tailX = snakeX[0];
    tailY = snakeY[0];
}

/*
判断游戏状态的函数，包括判断是否碰到身体、墙、食物的函数和碰到食物后增加贪吃蛇身体长度的函数
*/

BOOL judgeGameSituation(){
    //如果碰到身体或墙，游戏结束
    if (isHitTheBody() || isHitTheWall()) return FALSE;
    //如果碰到食物
    if(isHitTheFood()){
        //增加贪吃蛇身体的长度的函数
        increaseTheBodyLength();
        //如果贪吃蛇身体的长度等于最大长度，游戏结束
        if (snakeLength == SNACK_MAX_LENGTH) return FALSE;
        //否则继续游戏
        else return TRUE;
    }
    //其它情况那么继续游戏
    return TRUE;
}

/*
具体判断贪吃蛇碰到的样式的函数
*/

//如果贪吃蛇头部的坐标的样式是'X'，那么碰到身体
BOOL isHitTheBody(){
	return map[HEAD_Y][HEAD_X] == SNACK_BODY;
}

//如果贪吃蛇头部的坐标的样式是'*'，那么碰到墙
BOOL isHitTheWall(){
	return map[HEAD_Y][HEAD_X] == WALL_CELL;
}

//如果贪吃蛇头部的坐标的样式是'$'，那么碰到食物
BOOL isHitTheFood(){
	if (map[HEAD_Y][HEAD_X] == SNACK_FOOD){
        isEatTheFood = TRUE;
        return TRUE;
    }
    else return FALSE;
}

/*
贪吃蛇身体的长度加一，贪吃蛇的横纵坐标都向后移一位，尾部坐标为原先记录的尾部的坐标
*/
void increaseTheBodyLength(){
    snakeLength++;
    for(int i = snakeLength - 1; i > 0; --i){
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    snakeX[0] = tailX;
    snakeY[0] = tailY;
}

/*
改变地图的函数，贪吃蛇移动了后，新的贪吃蛇头部的坐标的样式为'H'，
原来的头部的坐标的样式为'X'，
如果没吃到食物，原来的尾部的坐标的样式为' '，否则不变，并生成食物，完成地图的改变
*/

void changeTheMap(){
    map[snakeY[snakeLength - 2]][snakeX[snakeLength - 2]] = SNACK_BODY;
    map[HEAD_Y][HEAD_X] = SNACK_HEAD;
    if (!isEatTheFood){
        map[tailY][tailX] = BLANK_CELL;
    }
    else{
        put_money();
        isEatTheFood = FALSE;
    }
}

/*
生成食物的函数，里面包括一个找到可以放食物位置坐标的函数
*/
void put_money(){
	Index index = find_BLANK_CELL();
	int x_index = index.x_index;
    int y_index = index.y_index;
    map[y_index][x_index] = SNACK_FOOD;
}

/*
随机生成的找到可以放食物位置坐标的函数，当坐标位置的样式为' '，才会返回这个坐标
*/
Index find_BLANK_CELL(){
	srand((unsigned) time(NULL));
	int x_index, y_index;
	do{
		x_index = rand() % 10 + 1;
        y_index = rand() % 10 + 1;
	} 
	while(map[y_index][x_index] != BLANK_CELL);
	Index index = {x_index, y_index};
	return index;
}

/*
结束游戏的函数，如果贪吃蛇的长度等于最大长度，游戏胜利，否则失败，显示得分
*/
void gameover(){
    if (snakeLength == SNACK_MAX_LENGTH){
        printf("\nYou win! Your score is %d\n", (snakeLength - 5) * 10);
    }
    else{
        printf("\nGame over! Your score is %d\n", (snakeLength - 5) * 10);
    }
    exit(0);
}

/*
打印地图函数，将原来的界面清空之后，输出新的地图
*/
void output(){
	system("cls");
    for (int i = 0; i < 12; ++i){
        for (int j = 0; j < 12; ++j){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Please input wasd to move:");
}

int main(){
    char c;
    put_money();
    output();
    //根据不同的输入向不同的方向移动
    while((c = getchar()) != EOF){
        switch (c){
            case 'A': 
            case 'a': snakeMove(-1, 0); break;
            case 'D':
            case 'd': snakeMove(1, 0); break;
            case 'S':
            case 's': snakeMove(0, -1); break;
            case 'W':
            case 'w': snakeMove(0, 1); break;
        }
        fflush(stdin);
        output();
    }
}