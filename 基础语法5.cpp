#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;


//auto
//int main()
//{
//	const int x = 10;
//
//	//自动识别x 的类型  --> 同时会去掉x的常量属性
//	auto y = x;
//	y = 5;
//	x = 10;//出问题  x是常量
//
//	cout << typeid(y).name() << endl;
//	cout << y << endl;
//
//	return 0;
//}


//int main()
//{
//	//int i = 0;
//
//	//auto 是不能单独定义  ，必须给值
//	//auto x;
//
//	//auto 不能单独定义--> 引出了auto不能作为形参
//
//	return 0;
//}

//auto 不能单独定义--> 引出了auto不能作为形参
//void TestAuto(auto x)
//{
//
//}

//int main()
//{
//	//auto 也不能这样定义数组
//	auto a[] = { 1,2,3 };
//	return 0;
//}


//语法糖  --> 范围for
//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//
//	//C/C++遍历数组
//	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//	//{
//	//	cout << array[i] << " ";
//	//}
//	//cout << endl;
//	////C++11  --范围for
//
//	//for (auto e : array)//自动依次取数组里每一个元素赋值给e  （自动判断结束）
//	//{
//	//	cout << e << " ";
//	//}
//
//
//	//范围for，把数组中的每个数+1
//
//	//引用
//	//for (auto& x : array)
//	//{
//	//	x++;
//	//}
//
//	//for (auto x : array)
//	//{
//	//	cout << x << " ";
//	//}
//	return 0;
//}













































