#include<iostream>
#include<vector>
using namespace std;

void dfs(int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> &candidates, int target)
{
    if (index == candidates.size())
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    dfs(index + 1, temp, ans, candidates, target);
    if (target - candidates[index] > 0)
    {
        temp.push_back(candidates[index]);
        dfs(index, temp, ans, candidates, target - candidates[index]);
        temp.pop_back();
    }
}
int main()
{
    vector<int>candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    int target=7;
    vector<vector< int > > ans;
    vector<int> temp;
    dfs(0, temp, ans, candidates, target);
    return 0;
}