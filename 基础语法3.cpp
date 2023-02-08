#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//引用

//int main()
//{
//	int a = 10;
//
//	//引用
//	int& b = a;
//
//	//取地址
//	int* p = &a;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	//引用 ：	引用没有开辟新空间，就是对原来空间取一个新名称叫做b
//	int& b = a;
//
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//
//	//引用在定义时必须初始化  --> 必须指定清楚
//	//int& b = a;
//	//int& b;指向不清楚
//
//
//	//一个变量可以有多个引用
//	int a = 10;
//	int& b = a;
//	int& c = a;
//
//	return 0;
//}


//int main()
//{
//	//引用一旦引用一个实体，再不能引用其它实体
//	int a = 10;
//	int& b = a;
//
//	int c = 20;
//
//	b = c;
//	//是把c赋值给了b
//
//	return 0;
//}



//引用的用法

//void swap(int* px, int* py)  //传地址
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//void swap(int& px, int& py)  //传引用
//{
//	int tmp = px;
//	px = py;
//	py = tmp;
//}
//
////void swap(int x, int y)   //传值
////{
////	int tmp = x;
////	x = y;
////	y = tmp;
////}
//
//
////以上三个构成函数重载
////但是swap（x,y）；调用时存在歧义，也不知道调用传值还是传引用
//
////类似这个，他们构成重载，但是存在歧义
////  void func();
////  void func(int x=0,int y=0);
//
//
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x,&y);
//	swap(x, y);
//	return 0;
//}



//引用做返回值


//传值返回

//int Add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//
////c的值存放在寄存器（充当临时变量）中(当函数栈帧销毁时，将值返回给ret)
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

//临时变量存放在哪里呢？
//1.如果c比较小（4or8）(寄存器也差不多这么大)，一般寄存器充当临时变量
//2.如果c比较大，临时变量存放在调用Add函数的栈帧中



//传引用返回

//int& Add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//
////直接返回c的引用，不会返回c的拷贝
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

//以上代码的问题
//1.存在非法访问，因为Add(1,2)的返回值的c的引用，所以当函数栈帧销毁了以后，回去访问c的值
//2.如果Add函数栈帧销毁，清理空间，那么取c的值时候取到的就是随机值，给ret就是随机值，这个取决于编译器




//常引用
//int main()
//{
//	//权限放大  -->不可以的
//	//const int a = 10;  //只能读
//	//int& b = a;       //可读可写
//
//	//权限不变
//	//const int a = 10;
//	//const int& b = a;
//
//	////权限变小
//	//int a = 10;
//	//const int& b = a;
//
//	//return 0;
//}



//引用的价值  --> 1.做参数（提高效率）

#define N 100

struct Stack
{
	int a[N];
	int top;
};

void Func1(struct Stack st)
{

}

void Func2(struct Stack* st)
{

}

void Func3(struct Stack& st)
{

}


int main()
{
	struct Stack st;

	struct Stack* ps = &st;

	int a = 4;
	int* p = &a;

	char b = 'a';
	char* c = &b;

	printf("%d  %d  %d ", sizeof(ps),sizeof(p),sizeof(c));

	Func1(st);//传参消耗404个字节

	Func2(&st);//传惨消耗4个字节

	Func3(st);//不消耗空间

	return 0;
}





