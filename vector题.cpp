#define _CRT_SECURE_NO_WARNINGS

#include<ostream>
#include<vector>
using namespace std;


//�������
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//        for (int i = 0; i < numRows; i++)
//        {
//            vv[i].resize(i + 1);
//            vv[i][0] = vv[i][vv[i].size() - 1] = 1;
//        }
//        for (int i = 0; i < vv.size(); i++)
//        {
//            for (size_t j = 0; j < vv[i].size(); j++)
//            {
//                if (vv[i][j] == 0)
//                {
//                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//                }
//            }
//        }
//        return vv;
//    }
//
//};


//����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
//
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/letter-combinations-of-a-phone-number
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������




//class Solution {
//    string arr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//public:
//    void _letterCombinations(const string& digits, size_t i, string combinStr,vector<string>& strV)
//    {
//        if (i == digits.size())
//        {
//            strV.push_back(combinStr);
//            return;
//        }
//        string str = arr[digits[i] - '0'];
//        for (size_t j = 0; j < str.size(); j++)
//        {
//            _letterCombinations(digits, i+1, combinStr + str[j], strV);
//        }
//    }
//    vector<string> letterCombinations(string digits) 
//    {
//        string combinStr;
//        vector<string> strV;
//        if (digits.empty())
//        {
//            return strV;
//        }
//        _letterCombinations(digits, 0, combinStr, strV);
//        return strV;
//    }
//};
//
//int main()
//{
//    Solution t;
//    
//    t.letterCombinations("456");
//
//    return 0;
//}





