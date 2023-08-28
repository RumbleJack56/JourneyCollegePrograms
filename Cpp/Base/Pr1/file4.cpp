//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
        // Flag is to denote that the center of the number will be incremented
        int flag = 1;
        
        //We increment the center of the number just in case if copying the first half on the
        //other side reduces the palindrome size

       
        //check if palindrome creation will reduce size or not
        //if it does not reduce size, flag is set to zero and no increments are done
        for (int x=0; x<(int)((n+1)/2);++x){
            if (num[x] < num[n-x-1]){
                flag=2;
            }
            else if (num[x] > num[n-x-1]){
                flag=0;
            }
	        num[n-x-1] = num[x];
        
        }

        vector<int> v;
        for (int i=0; i<n; ++i){
            v.push_back(num[i]);
        }
        


        //EXCEPTION HANDLING
        if (flag==1 && v[0]==9){
            n+=1;
            v.emplace(v.begin(),0);
            v[v.end()]=0
        }
        
        //checks whether the palindrome is odd or even (bitwise)
        if (n&1==1){
            
            //odd case for r=0 it will increment and checks are made if value is exceeding 10, then it
            //increments the next and previous values, till the remainder dies
	        int r=0;
	        int mid = (n-1)/2;
	        while (flag>0){
	            
	            //center case is done once, rest all cases in pairs
	            if (r>0){
    	            num[mid - r]= (num[mid - r] + 1)%10 ; 
                    num[mid + r]= (num[mid + r] + 1)%10 ;
	            }
                else{
                    num[mid - r]= (num[mid - r] + 1)%10 ;
                }
                
                //if remainder dies, then flag is zero and breaks loop, else r increments and carries the value
                if (num[mid - r]==0){
                    r+=1;
                }
                else{
                    flag=0;
                }
	        }
        }
	    else{
	        //even palindrome case 
	        
	        //here all pairs are made so no center exception, increments are made like before
	        int r=0;
	        int mid= n/2;
	        while (flag>0){
	            //same code as before
	            num[mid-1-r] = (num[mid-1-r] + 1)%10 ;
	            num[mid+r] = (num[mid+r] + 1)%10 ;
                if (num[mid-1-r]==0){
                    r+=1;
                }
                else{
                    flag=0;
                }
	        }
	    }
        //convert array into vector
        return v;


}
};

//python equivalent
/*class Solution:
	def generateNextPalindrome(self,num, n ) :
	    flag = 1
	    for x in range(int((n+1)/2)):
	        if num[x] < num[n-x-1]: flag=1
	        elif num[x] > num[n-x-1]: flag=0
	        num[n-x-1] = num[x]
	    if n&0b1==1:
	        r=0
	        mid = int((n-1)/2)
	        while flag>0:
	            if r>0:
    	            num[mid - r]= (num[mid - r] + 1)%10
                    num[mid + r]= (num[mid + r] + 1)%10
                else:
                    num[mid - r]= (num[mid - r] + 1)%10
                if (num[mid - r]==0):
                    r+=1
                else:
                    flag=0
	    else:
	        r=0
	        mid=int(n/2)
	        while flag>0:
	            num[mid-1-r] = (num[mid-1-r] + 1)%10
	            num[mid+r] = (num[mid+r] + 1)%10
                if (num[mid-1-r]==0):
                    r+=1
                else:
                    flag=0
        return num
*/




//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends