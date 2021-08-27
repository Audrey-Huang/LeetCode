#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums={1,3,2};
    int m = nums.size();
    int flag = 0;
    for (int i = m - 1; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                for (int k = j + 1; k <= i; k++)
                {
                    nums[k] = nums[k - 1];
                }
                nums[j] = temp;
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
        sort(nums.begin(), nums.end());
}