#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums, int s, int mid, int e) 
{
    vector<int> temp(e - s + 1);
    int i = s, j = mid + 1, k = 0;

    while(i <= mid && j <= e) 
    {
        if(nums[i] <= nums[j]) 
        {
            temp[k++] = nums[i++];
        } 
        else 
        {
            temp[k++] = nums[j++];
        }
    }

    while(i <= mid) 
    {
        temp[k++] = nums[i++];
    }

    while (j <= e) 
    {
        temp[k++] = nums[j++];
    }

    for(int l = 0; l < temp.size(); l++) 
    {
        nums[s + l] = temp[l];
    }
}

void iterativeMergeSort(vector<int>& nums) 
{
    int n = nums.size();

    for(int win = 1; win < n; win *= 2) 
    {
        for(int i = 0; i < n; i += 2 * win) 
        {
            int mid = i + win - 1;
            int e = min(i + 2 * win - 1, n - 1);

            if (mid < e) 
            { 
                merge(nums, i, mid, e);
            }
        }
    }
}

int main() {
    vector<int> nums = {1, 5, 3, 7, 8, 4, 6, 2, 0, 5, 22, 6, 55, 9};

    iterativeMergeSort(nums);

    for(const auto& x : nums) 
    {
        cout << x << " ";
    }

    return 0;
}
