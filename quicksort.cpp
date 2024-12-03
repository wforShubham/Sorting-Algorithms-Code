#include<bits/stdc++.h>
using namespace std;

int findpivot(vector<int> &nums,int low,int hig)
{
    int pivot = nums[hig];

    int i = low;

    for(int j=low;j<hig;j++)
    {
        if(nums[j] <= pivot)
        {
            swap(nums[i],nums[j]);
            i++;
        }
    }

    swap(nums[i],nums[hig]);

    return i;

}
void qsort(vector<int> &nums,int low,int hig)
{

    if(low<hig)
    {
        int partition = findpivot(nums,low,hig);

        qsort(nums,low,partition - 1);
        qsort(nums,partition+1,hig);
    }
}
int main()
{
    vector<int> nums = {1,5,3,7,8,4,6,2,0,5,22,6,55,9};

    qsort(nums,0,nums.size()-1);

    for(auto &x:nums) cout<<x<<" ";

    return 0;

}