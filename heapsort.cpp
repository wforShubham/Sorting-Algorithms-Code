#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& nums, int n, int i) 
{
    int largest = i;
    while(true) 
    {
        int left = 2 * largest + 1;
        int right = 2 * largest + 2; 

        if(left < n && nums[left] > nums[largest]) 
        {
            largest = left;
        }

        if(right < n && nums[right] > nums[largest]) 
        {
            largest = right;
        }

        if(largest != i) 
        {
            swap(nums[i], nums[largest]);
            i = largest; 
        } 
        else 
        {
            break;
        }
    }
}


void heapsort(vector<int> &nums)
{
    int n = nums.size();

    for(int i=n/2-1;i>=0;i--)
    {
        Heapify(nums,n,i);
    }

    for(int i=n-1;i>0;i--)
    {
        swap(nums[0],nums[i]);
        Heapify(nums,i,0);
    }
}

int main()
{
    vector<int> nums = {1,5,3,7,8,4,6,2,0,5,22,6,55,9};

    heapsort(nums);

    for(auto &x:nums) cout<<x<<" ";

    return 0;

}