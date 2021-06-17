// A Dynamic Programming based program to find 
// minimum number insertions needed to make a 
// string palindrome 
#include <bits/stdc++.h> 
using namespace std; 


// A DP function to find minimum 
// number of insertions 
int solve(string A) {
int l=0, r=A.length()-1;
int count = 0;
while(l < r){
    if(A[l] == A[r]){
        l++;
        r--;
    }else{
        if(l == 0) {
            count++;
            r--;
        }
        else {
            count += l;
            l = 0;
        }
        
    }
}

return count;
}

// Driver Code 
int main() 
{ 
	string s="aabbaaa";
    cout << solve(s)<<endl;
	return 0; 
} 

// This is code is contributed by rathbhupendra 
