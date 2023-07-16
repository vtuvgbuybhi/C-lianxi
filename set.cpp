#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<functional>
using namespace std;

//void test_set()
//{
//	//set<int> s;
//	//s.insert(4);
//	//s.insert(5); 
//	//s.insert(2);
//
//	//set<int> s = { 1,2,3,4 };
//
//	int a[] = { 1,5,8,6,4,9 };
//	//set<int> s(a, a + sizeof(a) / sizeof(a[0]));
//
//	set<int,greater<int>> s(a, a + sizeof(a) / sizeof(a[0]));
//
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	cout << s.count(5) << endl;
//	cout<<s.count(0)<<endl;
//
//
//	//s.erase(5);
//	//for (auto e : s)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//set<int>::iterator pos = s.find(4);
//	//s.erase(pos);
//	//for (auto e : s)
//	//{
//	//	cout << e << " ";
//	//}
//
//}

//void test_set1()
//{
//	set<int> s = {10 ,50 , 80 ,30 ,60 ,70 ,55 ,65 ,90};
//	set<int>::iterator itlow, itup;
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto ret = s.equal_range(30);
//	cout << "[ " << *ret.first << " " << *ret.second <<"]"<< endl;
//
//
//	//itlow = s.lower_bound(35);
//	//itup = s.upper_bound(70);
//	//cout <<"itlow:"<< * itlow << endl;
//	//cout << "itup :" << *itup << endl;
//
//}

//void test_set2()
//{
//	map<string, string> dict;
//	//pair<string, string> kv1("string", "×Ö·û´®");
//	//dict.insert(kv1);
//
//	dict.insert(pair<string, string>("test", "²âÊÔ"));
//	dict.insert(pair<string, string>("sort", "ÅÅĞò"));
//	dict.insert(pair<string, string>("string", "×Ö·û´®"));
//
//	dict.insert(make_pair("left", "×ó±ß"));
//
//	map<string, string>::iterator it = dict.begin();
//	//while (it != dict.end())
//	//{
//	//	cout <<  (*it).first <<" "<<(*it).second<< endl;
//	//	it++;
//	//}
//	//while (it != dict.end())
//	//{
//	//	cout << it->first << " " << it->second << endl;
//	//	it++;
//	//}
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << " " << kv.second << endl;
//	}
//
//
//	cout << endl;
//
//}

//void test_set2()
//{
//	string arr[] = { "Æ»¹û","Î÷¹Ï","Æ»¹û","Î÷¹Ï","Æ»¹û","Æ»¹û","Î÷¹Ï","Æ»¹û","Ïã½¶","Æ»¹û","Ïã½¶" };
//	map<string, int> countMap;
//	for (auto& str : arr)
//	{
//		map<string, int>::iterator it = countMap.find(str);
//		if (it != countMap.end())
//		{
//			//(*it).second++;
//
//			it->second++;
//		}
//		else
//		{
//			countMap.insert(make_pair(str, 1));
//		}
//	}
//
//	map<string, int>::iterator it = countMap.begin();
//	while (it != countMap.end())
//	{
//		cout << it->first << ": " << it->second << endl;
//		it++;
//	}
//	cout << endl;
//
//}


//void test_set2()
//{
//	string arr[] = { "Æ»¹û","Î÷¹Ï","Æ»¹û","Î÷¹Ï","Æ»¹û","Æ»¹û","Î÷¹Ï","Æ»¹û","Ïã½¶","Æ»¹û","Ïã½¶" };
//	map<string, int> countMap;
//	for (auto& str : arr)
//	{
//		countMap[str]++;
//	}
//
//	map<string, int>::iterator it = countMap.begin();
//	while (it != countMap.end())
//	{
//		cout << it->first << ": " << it->second << endl;
//		it++;
//	}
//
//	//map<string, string> dict;
//	//dict.insert(make_pair("sort", "ÅÅĞò"));
//	//dict["insert"];
//	//dict["insert"] = "²åÈë";
//	//dict["left"] = "Ïò×ó";
//	//cout << endl;
//
//}
//
//int main()
//{
//	test_set2();
//	return 0;
//}











