#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> &nums={-1,2,1,-4};
    int target=1;
    int m = nums.size();
    int ans = 0;
    int cal = INT_MAX;
    for (int i = 0; i <= m - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1;
        int r = m - 1;
        while (l < r)
        {
            int temp = nums[i] + nums[l] + nums[r];
            if (temp == target)
                return target;
            if (abs(target - temp) < cal)
            {
                cal = abs(target - temp);
                ans = temp;
            }
            if (temp > target)
            {
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                r--;
            }
            else
            {
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                l++;
            }
        }
    }
    return ans;
}