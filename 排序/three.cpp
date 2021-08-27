#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums={0,0,0};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int m = nums.size();
    if (m < 3)
        return 0;
    if (nums[0] > 0)
        return 0;
    for (int i = 0; i <= m - 3; i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1;
        int r = m - 1;
        int target = nums[i] * -1;
        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                ans.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                l++;
                r--;
            }
            else if (nums[l] + nums[r] > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return 0;
}