#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
using namespace std;


//泛型编程
// 模板

//void swap(int& x1, int& x2)
//{
//	int x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//void swap(double& x1, double& x2)
//{
//	double x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	swap(a, b);
//	swap(c, d);
//
//	cout << a <<" "<< b << endl;
//	cout << c <<" "<< d << endl;
//
//	return 0;
//}



//模板   类模板    、  函数模板


//函数模板
//template<class T1,class T2>
//template<class T>    //tmplate<typename T>   ，模板参数列表  --参数类型
//
//void Swap(T& x1, T& x2)  //函数参数列表   --参数对象
//{
//	T x= x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	Swap(a, b);    //模板实例化  --生成对应的函数
//	Swap(c, d);
//
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//
//	return 0;
//}



//template<class T>
//
//T Add(const T& x1,const T& x2)
//{
//	return x1 + x2;
//}
//
//
//int main()
//{
//	int a = 10, b = 20;
//	double c = 1.2, d = 2.5;
//
//	cout << Add(a, b) << endl;;
//	cout<<Add(c, d)<<endl;
//
//	//cout<<Add(a,c)<<endl;//没有对应的函数模板
//	cout << Add((double)a, c) << endl;  //将a强转成double类型
//
//	//显示实例化
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, d) << endl;
//
//	return 0;
//}



//具体函数
int Add(int& x, int& y)
{
	return x + y;
}


//模板函数
template <class T>

T Add(const T& x, const T& y)
{
	return x + y;
}

int main()
{
	int a = 10, b = 20;
	double c = 1.2, d = 2.5;

	cout << Add(a, b) << endl;;
	cout<<Add(c, d)<<endl;

	return 0;
}

















