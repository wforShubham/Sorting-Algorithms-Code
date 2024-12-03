#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums,int s,int e,int mid)
{
    vector<int> t(e-s+1);
    int k = 0;
    int i = s,j = mid+1;
    while(i<=mid && j<=e)
    {
        if(nums[i] < nums[j])
        {
            t[k++] = nums[i++];
        }
        else
        {
            t[k++] = nums[j++];
        }
    }

    while(i<=mid)
    {
        t[k++] = nums[i++];
    }

    while(j<=e)
    {
        t[k++] = nums[j++];
    }
    for(int l = 0;l<t.size();l++)
    {
        nums[l+s] = t[l];
    }
}
void Msort(vector<int> &nums,int s,int e)
{
    if(s<e)
    {
        int mid = (s+e)>>1;
        Msort(nums,s,mid);
        Msort(nums,mid+1,e);
        merge(nums,s,e,mid);
    }
}
int main()
{
    vector<int> nums = {1,5,3,7,8,4,6,2,0,5,22,6,55,9};

    Msort(nums,0,nums.size()-1);

    for(auto &x:nums) cout<<x<<" ";

    return 0;

}