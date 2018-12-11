#ifndef COUNT_H
#define COUNT_H

#include "stdio.h"
// 输入输出定义
double  cal(double a, double b, int op)      // op: 0:+,1:-,2:*,3:/
{
	switch (op)                        // +-x/ 运算
	{
	case 0:  return(a + b);
	case 1:  return(a - b);
	case 2:  return(a*b);
	}
	if (b == 0.0)                       //  分母为0
		return(999.0);
	else
		return(a / b);
}
bool    isEqual(double d1, double d2)     // 两个浮点数是否近似相等
{
	double d = d1 - d2;
	if (d<0)
		d = -d;                        // 求绝对值
	return(d <= 0.001);
}
void   D24(int v0, int v1, int v2, int v3)          // 穷举法求24点
{
	char op[4] = { '+', '-', '*', '/' };             //  +:0  -:1 *:2  /:3

	int v[4];                                 // 输入四整数
	v[0] = v0; v[1] = v1;
	v[2] = v2; v[3] = v3;
	//-----------四重循环开始穷举四个数字的位置: 4!=24 种--------------------------
	int count = 0;                              // 计数成功次数
	for (int i1 = 0; i1<4; i1++)
	for (int i2 = 0; i2<4; i2++)                 // 四重循环对四个数穷举
	if (i2 != i1)
	for (int i3 = 0; i3<4; i3++)
	if (i3 != i2 && i3 != i1)
	for (int i4 = 0; i4<4; i4++)
	if (i4 != i3 && i4 != i2 && i4 != i1)
	{
		//-----------三重循环开始穷举三个运算符: 4X4X4=64 种---------------------------
		for (int f1 = 0; f1<4; f1++)      // 三重循环对运算符穷举
		for (int f2 = 0; f2<4; f2++)
		for (int f3 = 0; f3<4; f3++)  // 运算符 f1,f2,f3
		{                       // 对运算优先级直接列举(5种)
			//-----------未用循环，直接穷举三个运算符的优先级: 3!-1=5种--------------------
			double t1, t2, t3;      // 存放计算的中间值
			// 第1种情况  ((a 。b)。c)。d  ：
			t1 = cal(v[i1], v[i2], f1);
			t2 = cal(t1, v[i3], f2);
			t3 = cal(t2, v[i4], f3);
			if (isEqual(t3, 24))    // 运算后是否为24
			{
				char *fs = "((%d%c%d)%c%d)%c%d=24\n";
				printf(fs, v[i1], op[f1], v[i2], op[f2], v[i3], op[f3], v[i4]);
				count++;
			}
			// 第2种情况(a 。b)。(c。 d) 开始计算 ：
			t1 = cal(v[i1], v[i2], f1);
			t2 = cal(v[i3], v[i4], f3);
			t3 = cal(t1, t2, f2);
			if (isEqual(t3, 24))      // 运算后是否为24
			{
				char *fs = "(%d%c%d)%c(%d%c%d)=24\n";
				printf(fs, v[i1], op[f1], v[i2], op[f2], v[i3], op[f3], v[i4]);
				count++;
			}
			// 第3种情况 (a。(b。c))。d  开始计算 ：
			t1 = cal(v[i2], v[i3], f2);
			t2 = cal(v[i1], t1, f1);
			t3 = cal(t2, v[i4], f3);
			if (isEqual(t3, 24))    // 运算后是否为24
			{
				char *fs = "(%d%c(%d%c%d))%c%d=24\n";
				printf(fs, v[i1], op[f1], v[i2], op[f2], v[i3], op[f3], v[i4]);
				count++;
			}
			// 第4种情况  a。((b。c)。d ) 开始计算：
			t1 = cal(v[i2], v[i3], f2);
			t2 = cal(t1, v[i4], f3);
			t3 = cal(v[i1], t2, f1);
			if (isEqual(t3, 24))    // 运算后是否为24
			{
				char *fs = "%d%c((%d%c%d)%c%d)=24\n";
				printf(fs, v[i1], op[f1], v[i2], op[f2], v[i3], op[f3], v[i4]);
				count++;
			}
			// 第5种情况 a。(b。(c。d)) 开始计算：
			t1 = cal(v[i3], v[i4], f3);
			t2 = cal(v[i2], t1, f2);
			t3 = cal(v[i1], t2, f1);
			if (isEqual(t3, 24))    // 运算后是否为24
			{
				char *fs = "%d%c(%d%c(%d%c%d))=24\n";
				printf(fs, v[i1], op[f1], v[i2], op[f2], v[i3], op[f3], v[i4]);
				count++;
			}
		}
	}
	//-------------- 穷举结束： 共 24*64*5=7680 种表达式 ---------------------------
	if (count == 0)
		printf("\\n%d,%d,%d,%d 不能算出24.", v0, v1, v2, v3);
	else
		printf("\\n共找到算式 %d 条.", count);
}

#endif
/*
void main()
{
	int v0 = 3, v1 = 10, v2 = 4, v3 = 13;
	printf("输入四个整数: ");
	// scanf("%d %d %d %d",&v0,&v1,&v2,&v3);
	D24(v0, v1, v2, v3);

}*/