#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &nums)
{
    int n = nums.size();
    
    for(int i=1;i<n;i++)
    {
        int val = nums[i];
        int j = i-1;

        while(j>=0 && nums[j]>val)
        {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = val;
    }
}

int main() 
{
    vector<int> nums = {1, 5, 3, 7, 8, 4, 6, 2, 0, 5, 22, 6, 55, 9};

    insertionsort(nums);

    for(const auto& x : nums) 
    {
        cout << x << " ";
    }

    return 0;
}