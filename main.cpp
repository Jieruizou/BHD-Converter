#include "head.h" 
#include "draaw.h"
#include "function.h"
#define Z 20
/*制转换工具*/

//———————————————————————————主函数————————————————————————————————————————————————————
int main() {
	draw_main_picture();
	getch();   //关闭图形界面
	closegraph();
	return 0;

}

bool insideSquareButton(const SquareButton *button, int x, int y) {
	return (x >= button->x) && (y >= button->y)
	       && (x < button->x + button->width)
	       && (y < button->y + button->height);//返回判断
}

void drawSquareButton(const SquareButton *button) {
	setfillcolor(EGERGB(0, 139, 139));
	bar(button->x, button->y, button->x + button->width, button->y + button->height);
}

void drawSquareButton_2(const SquareButton *button) {
	setfillcolor(EGERGB(0, 197, 205));
	bar(button->x, button->y, button->x + button->width, button->y + button->height);
}

void drawSquareButton_3(const SquareButton *button) {
	setfillcolor(EGERGB(47, 79, 79));
	bar(button->x + 4, button->y + 4, button->x - 3 + button->width - 3, button->y - 3 + button->height - 3);
}

int anytoD(char *n, int b) {
	int j = 0, r = 0, b_r = 0;
	int length = strlen(n);
	for (j = length - 1; j >= 0; j--) {
		if (n[j] >= 'A' && n[j] <= 'Z')
			r = n[j] - '0' - 7;
		else if (n[j] >= 'a' && n[j] <= 'z')
			r = n[j] - '0' - 39;
		else if (n[j] >= '0' && n[j] <= '9')
			r = n[j] - '0';
		b_r += r * ( pow(b, length - j - 1));
	}
	return b_r;
}

void Dtoany(int d, int a, char *m) {
	int len = 0, r;
	do {
		r = d % a;
		if (r >= 10)
			m[len++] = r - 10 + 'A'; //余数大于等于10时映射成字母
		else
			m[len++] = r + '0';    //余数小于10时映射成数字
		d /= a;
	} while (d != 0);
	m[len] = '\0';//
	char t;
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		t = m[i];
		m[i] = m[j];
		m[j] = t;
	}
}

int aptxt(char n[20],int b,int a,char m[20]) {
	int i;
	FILE *fp;
	//打开文件
    fp = fopen("1.txt", "a");
    //如果文件不存在
    if (fp == NULL)
    {
        //使用“写入”方式创建文件
        fp = fopen("1.txt", "w");
        fp = fopen("1.txt", "a");
    }
	int t = strlen(n);
	for(i=0; i<t;i++)
	fprintf(fp, "%c", n[i]);
	n[i]='\0';
	fprintf(fp, " ", n[i]);
	fprintf(fp, "%d ", b );
	fprintf(fp, "%d ", a );
	int k=strlen(m);
	for(i=0; i<k;i++)
	fprintf(fp, "%c", m[i]);
	m[i]='\0';
	fprintf(fp, " ", m[i]);
	fclose(fp);
	fp = NULL;
	return 0;
}

void outputtext() {
	FILE *fp;
	int c=0,size=0;	
	Store *p,*h1,*p1,*q1;
	h1 = (Store*)malloc(sizeof(Store));
	h1->next = NULL;
	q1 = h1; 
	fp = fopen("1.txt", "r");
	 setcolor(BLACK);
    setfontbkcolor(WHITE);  
	while(1){
		if(feof(fp)){
			break;
		}
		p1 =(Store*)malloc(sizeof(Store)); 
		fscanf(fp,"%s%d%d%s",&p1->n,&p1->bee,&p1->aff,&p1->m); 
		p1->next = q1->next;
		q1->next = p1;
		q1 = p1;
	}
	fclose(fp); 
	h1 = h1->next;
	 while(h1->next&&c<17){
	size+=19;
    xyprintf (55,95+size, "%s" ,h1->n); 
    xyprintf (165,95+size,"%d",h1->bee);
    xyprintf(245,95+size,"%d",h1->aff);
    xyprintf(325,95+size,"%s",h1->m);
	c++;
	h1 = h1->next;
}
}

int judge_correct(char n[20] ,int b){
   int j,r;
   	int length = strlen(n);
   for (j = length - 1; j >= 0; j--) {
		if (n[j] >= 'A' && n[j] <= 'Z')
			r = n[j] - '0' - 7;
		else if (n[j] >= 'a' && n[j] <= 'z')
			r = n[j] - '0' - 39;
		else if (n[j] >= '0' && n[j] <= '9')
			r = n[j] - '0';
   if(r>=b)
   return 0;
  
   }
 return 1;
}
void neweditBox(sys_edit *editBox, int x, int y, int width, int height, int length) {
	editBox->create(false);						//创建单行输入框
	editBox->move(x, y);						//设置位置
	editBox->size(width, height);	                    //设置尺寸
	editBox->setmaxlen(length);						//设置允许输入的字符数
	editBox->visible(true);                      //设置可见性
	editBox->setfocus();                          //焦点
	editBox->setreadonly(false);                  //设置可输入
}

void getinfor_mainpicture() {

	sys_edit editBox, editBox1, editBox2;   //申请输入框
	neweditBox(&editBox, 30, 95, 400, 30, 20);
	neweditBox(&editBox1, 30, 180, 400, 30, 2);
	neweditBox(&editBox2, 30, 265, 400, 30, 2);
	bool clickButton = false;
	bool clickButton1 = false;
	bool clickButton2 = false;
	bool clickButton3 = false;
	bool clickButton4 = false;
	bool clickButton5 = false;
	bool clickButton6 = false;
	bool clickButton7 = false;
	bool clickButton8 = false;
	bool clickButton9 = false;
	bool clickButton10 = false;
	bool clickReturn = false;
	bool judge =0;
	for (; is_run(); delay_fps(1000)) {
		int i = 0, t, b, a;
		char num[Z], mum[Z];
		char c[1], d[1];
		while (mousemsg()) {
			mouse_msg msg = {0};
			msg = getmouse();
			//判断鼠标左键点击
			if (msg.is_left() && msg.is_down()) {
				clickButton = insideSquareButton(&button, msg.x, msg.y);
				clickButton1 = insideSquareButton(&button1, msg.x, msg.y);
				clickButton2 = insideSquareButton(&button2, msg.x, msg.y);
				clickButton3 = insideSquareButton(&button3, msg.x, msg.y);
				clickButton4 = insideSquareButton(&button4, msg.x, msg.y);
				clickButton5 = insideSquareButton(&button5, msg.x, msg.y);
				clickButton6 = insideSquareButton(&button6, msg.x, msg.y);
				clickButton7 = insideSquareButton(&button7, msg.x, msg.y);
				clickButton8 = insideSquareButton(&button8, msg.x, msg.y);
				clickButton9 = insideSquareButton(&button9, msg.x, msg.y);
				clickButton10 = insideSquareButton(&button10, msg.x, msg.y);
				clickReturn = insideSquareButton(&Return, msg.x, msg.y);
			}
		}
		if (clickButton) {
			setfontbkcolor(WHITE);
			editBox.gettext(300, num);
			editBox1.gettext(20, c);
			sscanf(c, "%d", &b);
			t = anytoD(num, b);
			judge=judge_correct(num, b);
			if(judge)
			{
			editBox2.gettext(20, d);
			sscanf(d, "%d", &a);
			Dtoany(t, a, mum);
			xyprintf(35, 345, "%s", mum);
			aptxt(num,b,a,mum);
			}
			else{
				setfont(15, 0, "宋体");
		     outtextxy(100, 75, "请输入符合要求的数字");
		     editBox.settext("");
		     editBox1.settext("");
		     editBox2.settext("");
			}	
				clickButton = false;
		}
		if (clickButton1) {
			editBox.destroy();
			editBox1.destroy();
			editBox2.destroy();
			draw_main_picture();
		}
		if (clickButton2) {
			editBox.visible(false);
			editBox1.visible(false);
			editBox2.visible(false);
				cleardevice();
			draw_record_picture();
		}
		if (clickButton3) {
			editBox1.settext("");
			b = 2;
			drawSquareButton_3(&button3);
			drawSquareButton_2(&button4);
			drawSquareButton_2(&button5);
			drawSquareButton_2(&button6);
			editBox1.setreadonly(true);
		}
		if (clickButton4) {
			editBox1.settext("");
			b = 8;
			drawSquareButton_3(&button4);//标识选中
			drawSquareButton_2(&button3);//选择后清空其他选项
			drawSquareButton_2(&button5);
			drawSquareButton_2(&button6);
			editBox1.setreadonly(true);
		}
		if (clickButton5) {
			editBox1.settext("");
			b = 10;
			drawSquareButton_3(&button5);
			drawSquareButton_2(&button4);
			drawSquareButton_2(&button3);
			drawSquareButton_2(&button6);
			editBox1.setreadonly(true);
		}
		if (clickButton6) {
			editBox1.settext("");
			b = 16;
			drawSquareButton_3(&button6);
			drawSquareButton_2(&button4);
			drawSquareButton_2(&button5);
			drawSquareButton_2(&button3);
			editBox1.setreadonly(true);
		}
		if (clickButton7) {
			editBox2.settext("");
			a = 2;
			drawSquareButton_3(&button7);
			drawSquareButton_2(&button8);
			drawSquareButton_2(&button9);
			drawSquareButton_2(&button10);
			editBox2.setreadonly(true);
		}
		if (clickButton8) {
			editBox2.settext("");
			a = 8;
			drawSquareButton_3(&button8);
			drawSquareButton_2(&button7);
			drawSquareButton_2(&button9);
			drawSquareButton_2(&button10);
			editBox2.setreadonly(true);
		}
		if (clickButton9) {
			a = 10;
			drawSquareButton_3(&button9);
			drawSquareButton_2(&button8);
			drawSquareButton_2(&button7);
			drawSquareButton_2(&button10);
			editBox2.setreadonly(true);
		}
		if (clickButton10) {
			a = 16;
			drawSquareButton_3(&button10);
			drawSquareButton_2(&button8);
			drawSquareButton_2(&button9);
			drawSquareButton_2(&button7);
			editBox2.setreadonly(true);
		}
		if (clickReturn) {
			draw_main_picture();
		}
	}
}

void draw_main_picture() {
	cleardevice();
	setcaption("进制转换工具 .test");
	initgraph(480, 480);
	setbkcolor(EGERGB(0, 139, 139));
	setfont(32, 0, "楷体");
	setfillcolor(EGERGB(0, 139, 139));
	bar(0, 0, 480, 50);
	setcolor(WHITE);
	outtextxy(150, 10, "进制转换器");
	setfont(20, 0, "楷体");
	outtextxy(370, 20, "Jerryz");
	setcolor(BLACK);
	setbkcolor(WHITE);
	setfont(15, 0, "宋体");
	outtextxy(30, 75, "转换数字：");
	outtextxy(57, 134, "2进制");
	outtextxy(157, 134, "8进制");
	outtextxy(257, 134, "10进制");
	outtextxy(357, 134, "16进制");
	outtextxy(57, 220, "2进制");
	outtextxy(157, 220, "8进制");
	outtextxy(257, 220, "10进制");
	outtextxy(357, 220, "16进制");
	outtextxy(30, 160, "转化前进制：");
	outtextxy(30, 245, "转化后进制：");
	outtextxy(30, 320, "转化结果：");
	setcolor(EGERGB(54, 54, 54));
	line(30, 340, 30, 365);
	line(30, 340, 430, 340);
	line(430, 340, 430, 365);
	line(30, 365, 430, 365);
	setfont(24, 0, "楷体");
	setfontbkcolor(EGERGB(0, 139, 139));
	setcolor(WHITE);
	drawSquareButton(&button);
	drawSquareButton(&button1);
	drawSquareButton(&button2);
	drawSquareButton_2(&button3);
	drawSquareButton_2(&button4);
	drawSquareButton_2(&button5);
	drawSquareButton_2(&button6);
	drawSquareButton_2(&button7);
	drawSquareButton_2(&button8);
	drawSquareButton_2(&button9);
	drawSquareButton_2(&button10);
	outtextxy(55, 408, "确定");
	outtextxy(205, 408, "清空");
	outtextxy(347, 408, "记录");
	setfontbkcolor(LIGHTGRAY);
	setfont(15, 0, "宋体");
	setcolor(BLACK);
	getinfor_mainpicture();
}

void draw_record_picture() {

	initgraph(480, 480);
	setfillcolor(EGERGB(0, 139, 139));
	bar(40,75,440,110);	
	setfont(22, 0, "楷体");
	outputtext();
	setcolor(EGERGB(54, 54, 54));//左上（40,75）右上（440,75）左下（40，440）（右下（440，440）
	line(40, 75, 40, 440);
	line(40, 440, 440, 440);
	line(440, 440, 440, 75);
	line(40, 75, 440, 75);
	line(160,75,160,440);
	line(240,75,240,440);
	line(320,75,320,440);
	line(40,110,440,110);
	drawSquareButton(&Return);
	setcolor(WHITE);
	setfontbkcolor(EGERGB(0, 139, 139));
	outtextxy(367, 28, "返回");
	setfont(19, 0, "楷体");
	outtextxy(54, 85, "转换数字");
	outtextxy(170, 85, "前进制");
    outtextxy(250, 85, "后进制");
    outtextxy(330, 85, "转换后数字");
}



