#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool check(map<char, int> flag, map<char, int> temp)
{
    for (auto a : temp)
    {
        if (flag[a.first] < a.second)
        {
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t)
{
    int m = s.length(), n = t.length();
    if (m < n)
        return "";
    map<char, int> temp;
    map<char, int> flag;
    for (int i = 0; i < n; i++)
    {
        if (temp.find(t[i]) != temp.end())
        {
            temp[t[i]]++;
        }
        else
        {
            temp[t[i]] = 1;
        }
    }
    string ans = "";
    int size = INT_MAX;
    int left = 0;
    for (int i = 0; i < m; i++)
    {
        if (flag.find(s[i]) != temp.end())
        {
            flag[s[i]]++;
        }
        else
        {
            flag[s[i]] = 1;
        }
        while (check(flag, temp))
        {
            if (size > i - left + 1)
            {
                ans = s.substr(left, i - left + 1);
                size = i - left + 1;
            }
            if (flag[s[left]] > 1)
                flag[s[left]]--;
            else
                flag.erase(s[left]);
            left++;
        }
    }
    return ans;
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}

