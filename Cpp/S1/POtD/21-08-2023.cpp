<<<<<<< HEAD
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int counter=0;
        int n=matrix.size();
        int m=matrix[0].size();

        for (int y=0; y<n;++y){
            for (int x=0; x<m; ++x){
                if (matrix[x][y]==1){
                    int left = ;
                    int right = x==n-1 ? n-1 : x+1;
                    int up = y==0 ? 0 :y-1;
                    int down = y==n-1 ? n-1 : y+1;
                    int zeros = 0;
                    for (int a=left;a<=right;++a){
                        for (int b=up;b<=down;++b){
                            if (matrix[a][b]==0){zeros++;}
                        }
                    }
                    if (zeros%2==0){++counter;}
                }
            }
        }
        return counter;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
=======
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int counter=0;
        int n=matrix.size();
        int m=matrix[0].size();

        for (int y=0; y<n;++y){
            for (int x=0; x<m; ++x){
                if (matrix[x][y]==1){
                    int left = ;
                    int right = x==n-1 ? n-1 : x+1;
                    int up = y==0 ? 0 :y-1;
                    int down = y==n-1 ? n-1 : y+1;
                    int zeros = 0;
                    for (int a=left;a<=right;++a){
                        for (int b=up;b<=down;++b){
                            if (matrix[a][b]==0){zeros++;}
                        }
                    }
                    if (zeros%2==0){++counter;}
                }
            }
        }
        return counter;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
>>>>>>> 673eca3828584dd9cb320f13ffcee4031144e733
// } Driver Code Ends