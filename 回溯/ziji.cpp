#include<iostream>
#include<vector>
using namespace std;
void dfs(int index, vector<int> temp, vector<vector<int>> &ans, vector<int> nums)
{
    if (index == nums.size())
    {
        ans.push_back(temp);
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
        return;
    }
    dfs(index + 1, temp, ans, nums);
    temp.push_back(nums[index]);
    dfs(index + 1, temp, ans, nums);
    temp.pop_back();
}
int main()
{
    vector<int>nums={1,2,2};
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(0, temp, ans, nums);
    return 0;
}