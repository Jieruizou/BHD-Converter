
#include <graphics.h>
#include <sys_edit.h>
//界面
void draw_main_picture();
//画记录页的界面
void draw_record_picture();
//创建输入框，进行初始化
void neweditBox(sys_edit *editBox, int x, int y, int width, int height, int length);

//获取鼠标信息
void getinfor_mainpicture();

//判断输入
int judge_correct(int com,int b);

//判断传来的方形按钮在不在（x,y）内
bool insideSquareButton(const SquareButton *button, int x, int y);
//绘制方形按钮
//色1
void drawSquareButton(const SquareButton *button);
//色2
void drawSquareButton_2(const SquareButton *button);
//选择后变化
void drawSquareButton_3(const SquareButton *button);

