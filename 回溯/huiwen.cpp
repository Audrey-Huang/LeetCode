#include<iostream>
#include<vector>
using namespace std;
vector<vector<string>>ans;
vector<string>temp;
void dfs(int i, string s, vector<vector<bool>> dp)
{
    if (i == s.length())
    {
        ans.push_back(temp);
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        if (dp[i][j])
        {
            temp.push_back(s.substr(i, j - i + 1));
            dfs(j + 1, s, dp);
            temp.pop_back();
        }
    }
}
int main()
{
    string s;
    cin>>s;
    int m = s.length();
    vector<vector<bool>> dp(m, vector<bool>(m, false));
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = i; j < m; j++)
        {
            if (i == j)
                dp[i][j] = true;
            else if (j - i == 1 && s[i] == s[j])
                dp[i][j] = true;
            else if (j - i > 1 && s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
        }
    }
    dfs(0, s, dp);
    return 0;
}