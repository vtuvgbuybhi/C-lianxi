#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include<iostream>
using namespace std;


//int main()
//{
//	//�ַ�����С�ıȽ�
//	string s1("hello");
//	cout << (s1 < string("kkkk")) << endl;
//	return 0;
//}


//int main()
//{
//	//�ַ���ת����
//	string s1("1213");
//	int val = stoi(s1);
//	cout << val << endl;
//
//	//����ת�ַ���
//	int k = 233;
//	string s2 = to_string(k);
//
//	return 0;
//}



//��֤���Ĵ�
class Solution {
public:
    bool isLetterorNumber(char c)
    {
        if (c >= '1' && c <= '9')
        {
            return true;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            return true;
        }
        else if (c >= 'a' && c <= 'z')
        {
            return true;
        }
        else
            return false;
    }
    bool isPalindrome(string s) 
    {
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isLetterorNumber(s[begin]))
            {
                begin++;
            }
            while (begin < end && !isLetterorNumber(s[end]))
            {
                end--;
            }
            if (tolower(s[begin]) != tolower(s[end]))
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution s1;
    s1.isPalindrome("0P");

    return 0;
}


















































