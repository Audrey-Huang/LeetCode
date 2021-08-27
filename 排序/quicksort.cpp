#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&nums,int low,int high){
    int temp=nums[low];
    while(low<high){
        while(low<high&&nums[high]>=temp) --high;
        nums[low]=nums[high];
        while(low<high&&nums[low]<=temp) ++low;
        nums[high]=nums[low];
    }
    nums[low]=temp;
    return low;
}

void quicksort(vector<int>&nums,int low,int high){
    if(low>=high) return;
    int pivot=partition(nums,low,high);
    quicksort(nums,low,pivot-1);
    quicksort(nums,pivot+1,high);
}

int main(){
    vector<int>nums={0,5,-1,-2,9};
    quicksort(nums,0,nums.size()-1);
    for(int a:nums){
        cout<<a<<" ";
    }
    return 0;
}