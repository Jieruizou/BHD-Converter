#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define Z 20
//链表节点
struct Record {
	char n[Z];   //转换前的数字
	int bee;     //转换前的进制
	int aff;     //转换后的进制
	char m[Z];   //转换结果
	struct Record *next; //
};

//重命名节点
typedef struct Record Store;

//任意进制数转化成十进制数
int anytoD(char *n, int b);
//十进制转换成任意进制数
void Dtoany(int d, int a, char *m);

//往文件追加
int aptxt(char n[20],int b,int a,char m[20]);

//文件打印
void outputtext();
int judge_correct(char n[20] ,int b);

