/*
Matrix Chain Multiplication
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[] 
Output Format :
Line 1 : Minimum number of multiplication needed
Constraints :
1 <= n <= 100
Sample Input 1 :
3
10 15 20 25
Sample Output :
8000
Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 800
*/
#include<bits/stdc++.h>
// int help(int* p, int si, int ei,int**out){
//     if(si==ei || si==ei-1){
//         return 0;
//     }
    
//     if(out[si][ei]!=-1){
//         return out[si][ei];
//     }
    
//     for(int k = si+1; k<=ei-1;k++){
//         int a = help(p,si,k,out) + help(p,k,ei,out) + p[si]*p[k]*p[ei];
//         if(a<min){
//             min=a;
//         }
//     }
//     out[si][ei] = min;
//     return min;
    
// }


int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
	int out[n+1][n+1];
    
    for(int i=n;i>=0;i--){
        for(int j=0;j<=n;j++){
            if(i==j || i==j-1){
                out[i][j] = 0;
                continue;
            }
            int min =INT_MAX;
            for(int k=i+1;k<=j-1;k++){
                int a = out[i][k] + out[k][j] + p[i]*p[k]*p[j];
                if(a<min){
        			min=a;
                }
            }
            out[i][j] = min;
        }
    }
    
	return out[0][n];

}

/*
other-
#include<bits/stdc++.h>
int help(int* p, int si, int ei,int**out){
    if(si==ei || si==ei-1){
        return 0;
    }
    
    if(out[si][ei]!=-1){
        return out[si][ei];
    }
    int min =INT_MAX;
    for(int k = si+1; k<=ei-1;k++){
        int a = help(p,si,k,out) + help(p,k,ei,out) + p[si]*p[k]*p[ei];
        if(a<min){
            min=a;
        }
    }
    out[si][ei] = min;
    return min;
    
}


int mcm(int* p, int n){


    int **out = new int*[n+1];
    for(int i =0;i<=n;i++){
        out[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            out[i][j]=-1;
        }
    }

	return help(p,0,n,out);

}

*/