#include<iostream>
#include<vector>
using namespace std;

void dfs(int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> &candidates, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int j = index; j < candidates.size() && target - candidates[j] >= 0; j++)
    {
        if (j > index && candidates[j] == candidates[j - 1])
        {
            continue;
        }
        temp.push_back(candidates[j]);
        dfs(j + 1, temp, ans, candidates, target - candidates[j]);
        temp.pop_back();
    }
}
int main()
{
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(0, temp, ans, candidates, target);
    return 0;
}