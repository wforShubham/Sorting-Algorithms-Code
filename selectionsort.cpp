#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &nums)
{
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i] > nums[j]) swap(nums[i],nums[j]);
        }
    }
}

int main()
{
    vector<int> nums = {1,5,3,7,8,4,6,2,0,5,22,6,55,9};

    selectionsort(nums);

    for(auto &x:nums) cout<<x<<" ";

    return 0;

}