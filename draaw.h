
#include <graphics.h>
#include <sys_edit.h>
//����
void draw_main_picture();
//����¼ҳ�Ľ���
void draw_record_picture();
//��������򣬽��г�ʼ��
void neweditBox(sys_edit *editBox, int x, int y, int width, int height, int length);

//��ȡ�����Ϣ
void getinfor_mainpicture();

//�ж�����
int judge_correct(int com,int b);

//�жϴ����ķ��ΰ�ť�ڲ��ڣ�x,y����
bool insideSquareButton(const SquareButton *button, int x, int y);
//���Ʒ��ΰ�ť
//ɫ1
void drawSquareButton(const SquareButton *button);
//ɫ2
void drawSquareButton_2(const SquareButton *button);
//ѡ���仯
void drawSquareButton_3(const SquareButton *button);

