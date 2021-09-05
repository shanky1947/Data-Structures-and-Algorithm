/*
All possible ways
Send Feedback
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)
Output Format :
Count
Constraints :
1 <= a <= 10^5
1 <= b <= 50
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
*/
#include<bits/stdc++.h>
int help(int x, int n, int si, int ei){
    if(x==0){
        return 1;
    }
    if(x<0)
        return 0;
    if(si==ei){
        if(pow(si,n)==x){
             return 1;
        }
        return 0;        
    }
    
    int value=x-pow(si,n);
    if(value<0){
        return help(x,n, si+1,ei);
  
    }
        
    int a = help(x,n, si+1,ei);
    int b = help(value,n,si+1,ei);
    return a+b;
    
    
}


int allWays(int x, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    float a = 1.0/n;
    int b = pow(x,a);
    // cout<<b<<endl;
    return help(x,n,1,b);
    
}

/*
other-

#include<bits/stdc++.h>
int help(int x, int n, int si, int ei){
    if(x==0){
        return 1;
    }
    if(si==ei){
        if(pow(si,n)==x){
             return 1;
        }
        return 0;        
    }
    
    int value=x-pow(si,n);
    if(value<0){
        return help(x,n, si+1,ei);
  
    }
        
    int a = help(x,n, si+1,ei);
    int b = help(value,n,si+1,ei);
    return a+b;
    
    
}


int allWays(int x, int n) {

    float a = 1.0/n;
    int b = pow(x,a);
    // cout<<b<<endl;
    return help(x,n,1,b);
    
}

*/