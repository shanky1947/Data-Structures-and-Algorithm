/*
Code : No. of balanced BTs using DP
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 10^7
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

int binaryTreesOfHeightH(int h) {
    // Write your code here
int *arr = new int[h+1];
    arr[1]=1;
    arr[0]=1;
    int mod=(int)(pow(10,9))+7; 
    long int x,y;
    for(int i=2;i<=h;i++){
         x = arr[i-1];
    	 y = arr[i-2];

        int temp2=(x*x)%mod;
         int temp1=(2*x*y)%mod;
         arr[i]=(temp1+temp2)%mod;

    }
	return arr[h];
}

/*
#include <iostream>
#include <cmath>
using namespace std;
#include "solution.h"

int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}

*/
