#define _CRT_SECURE_NO_WARNINGS

#include<ostream>
#include<vector>
using namespace std;


//杨辉三角
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


//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/letter-combinations-of-a-phone-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。




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





