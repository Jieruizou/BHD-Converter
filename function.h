#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define Z 20
//����ڵ�
struct Record {
	char n[Z];   //ת��ǰ������
	int bee;     //ת��ǰ�Ľ���
	int aff;     //ת����Ľ���
	char m[Z];   //ת�����
	struct Record *next; //
};

//�������ڵ�
typedef struct Record Store;

//���������ת����ʮ������
int anytoD(char *n, int b);
//ʮ����ת�������������
void Dtoany(int d, int a, char *m);

//���ļ�׷��
int aptxt(char n[20],int b,int a,char m[20]);

//�ļ���ӡ
void outputtext();
int judge_correct(char n[20] ,int b);

