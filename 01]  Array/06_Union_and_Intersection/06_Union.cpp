//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a, a+n);
        sort(b, b+m);
        
        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {
            
            if(i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            
            if(j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }
            
            if(a[i] < b[j]) {
                i++;
                k++;
            } else if(a[i] > b[j]) {
                j++;
                k++;
            } else {
                k++;
                i++;
                j++;
            }
        }
        
        while(i < n) {
            if(i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            i++;
            k++;
        }
        
        while(j < m) {
            if(j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }
            j++;
            k++;
        }
        
        return k;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends