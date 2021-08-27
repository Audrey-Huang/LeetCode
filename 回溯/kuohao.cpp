#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<string> generateParenthesis(int n)
{
    if (n == 1)
        return {"()"};
    vector<vector<string> > dp(n + 1);
    dp[0] = {""};
    dp[1] = {"()"};
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (string p : dp[j])
            {
                for (string q : dp[i - j - 1])
                {
                    string temp = "(" + p + ")" + q;
                    dp[i].push_back(temp);
                }
            }
        }
    }
    return dp[n];
}

int main(){
    generateParenthesis(2);
    return 0;
}