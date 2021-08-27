#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

void dfs(int index, string temp, string digits, map<char, string> phone, vector<string>&ans)
{
    if (index == digits.length())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < phone[digits[index]].length(); i++)
    {
        temp.push_back(phone[digits[index]][i]);
        dfs(index + 1, temp, digits, phone, ans);
        temp.pop_back();
    }
}

int main()
{
    string digits="23";
    map<char, string> phone;
    phone['2']="abc";
    phone['3']="def";
    phone['4']="ghi";
    phone['5']="jkl";
    phone['6']="mno";
    phone['7']="pqrs";
    phone['8']="tuv";
    phone['9']="wxyz";
    vector<string> ans;
    string temp = "";
    dfs(0, temp, digits, phone, ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}