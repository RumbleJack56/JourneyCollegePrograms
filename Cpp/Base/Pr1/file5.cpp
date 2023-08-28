//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int min,max,s;
        min = max = arr[0];
        s=0;
        int p[2]={0,0};
        for (int k=0; k<n;++k){
            s+=arr[k];

            if (max < s){ max = s; p[1]=k;}

            if (min > s){ min = s; p[0]=k;}

        }
        
        
        return max-min;
    }
};

//{ Driver Code Starts.

int main()
{   int m[9] =  {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution ob;
    cout << ob.maxSubarraySum(m, 9) << endl;
    // int t,n;
    
    // cin>>t; //input testcases
    // while(t--) //while testcases exist
    // {
        
    //     cin>>n; //input size of array
        
    //     int a[n];
        
    //     for(int i=0;i<n;i++)
    //         cin>>a[i]; //inputting elements of array
            
    //     Solution ob;
        
    //     cout << ob.maxSubarraySum(a, n) << endl;
    // }
}

// } Driver Code Ends