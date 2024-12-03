#include<bits/stdc++.h>
using namespace std;

class sorting{

private:
    
    // findpivot function to find pivot index in quick sort.
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

    // merge function to merge sorted part of the array.
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

    //Heapify function for heapify the array.
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

    // Quick sort.
    void qsort(vector<int> &nums,int low,int hig)
    {

        if(low<hig)
        {
            int partition = findpivot(nums,low,hig);

            qsort(nums,low,partition - 1);
            qsort(nums,partition+1,hig);
        }
    }

    // Merge sort.
    void Msort(vector<int> &nums,int s,int e)
    {
        if(s<e)
        {
            int mid = (s+e)>>1;
            Msort(nums,s,mid);
            Msort(nums,mid+1,e);
            merge(nums,s,mid,e);
        }
    }

public:
    
    // Iterative merge sort.
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

    //Merge sort.
    void mergesort(vector<int> &nums)
    {
        Msort(nums,0,nums.size()-1);
    }

    // Quick sort.
    void quicksort(vector<int> &nums)
    {
        qsort(nums,0,nums.size()-1);
    }

    // Heap sort.
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

    // Selection sort.
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

    // Insertion sort.
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


    // Counting sort.
    void countingsort(vector<int> &nums)
    {
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());

        int range = max_val - min_val + 1;

        vector<int> count(range, 0);

        for (int &num : nums) 
        {
            count[num - min_val]++;
        }

        for(int i = 1; i < range; i++) 
        {
            count[i] += count[i - 1];
        }

        vector<int> output(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) 
        {
            output[count[nums[i] - min_val] - 1] = nums[i];
            count[nums[i] - min_val]--;
        }

        nums = output;
    }


    // Bubble sort.
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

};

int main()
{
    sorting obj;

    vector<int> nums = {1, 5, 3, 7, 8, 4, 6, 2, 0, 5, 22, 6, -55, 9};

    //obj.mergesort(nums);
    //obj.bubblesort(nums);
    //obj.countingsort(nums);
    //obj.heapsort(nums);
    //obj.insertionsort(nums);
    //obj.iterativeMergeSort(nums);
    //obj.quicksort(nums);
    //obj.selectionsort(nums);

    for(const auto& x : nums) 
    {
        cout << x << " ";
    }
}