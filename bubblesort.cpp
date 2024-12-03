#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &nums)
{
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        bool swaped = 1;
        for(int j=1;j<n-i;j++)
        {
            if(nums[j]<nums[j-1]) 
            {
                swap(nums[j],nums[j-1]);
                swaped = 0;
            }
        }

        if(swaped) break;
    }
}

int main() 
{
    vector<int> nums = {1, 5, 3, 7, 8, 4, 6, 2, 0, 5, 22, 6, 55, 9};

    bubblesort(nums);

    for(const auto& x : nums) 
    {
        cout << x << " ";
    }

    return 0;
}