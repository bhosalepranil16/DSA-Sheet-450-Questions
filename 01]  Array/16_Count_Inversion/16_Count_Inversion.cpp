#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long int countAndMerge(long long int arr[], long long int l, long long int m, long long int r) {
    
    long long int n1 = m - l + 1, n2 = r - m;
    long long int L[n1], R[n2];
    
    for(int i=0;i<n1;i++)
        L[i] = arr[l + i];
        
    for(int i=0;i<n2;i++)
        R[i] = arr[m + 1 + i];
    
    long long int i = 0, j = 0, k = l;
    long long int res = 0;    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            res = res + (n1 - i);
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    return res;
}


long long int countInversion(long long int arr[], long long int l, long long int r) {
    long long int res = 0;
    if(l < r) {
        long long int m = l + (r - l) / 2;
        res += countInversion(arr, l, m);
        res += countInversion(arr, m+1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return countInversion(arr, 0, N-1);
    
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends