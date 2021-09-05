/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include<cmath>
int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */

	if(h<=1){
        return 1;
    }
    int mod = pow(10,9)+7;
    long x = balancedBTs(h-1);
    long y = balancedBTs(h-2);
    
    long temp1 = 2*x*y;
    long temp2 = x*x;
    return (temp1+temp2)%mod;
}


/*
#include <iostream>
#include "Solution.h"
using namespace std;
#include <cmath>

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}

*/
