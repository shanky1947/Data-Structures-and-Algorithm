/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/


#include <bits/stdc++.h>
using namespace std;


int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    
    int out[n+1];
    
    out[0] = 0;
    out[1] = arr[0];
    out[2] = max(arr[0],arr[1]);
    
    for(int i=3;i<=n;i++){
        out[i]= max(out[i-2]+arr[i-1],out[i-1]);
    }
    
   return out[n];
}



/*
other-

#include <bits/stdc++.h>
using namespace std;
int helper(int arr[], int n,int out[]){
    
    if(n<=0)
        return 0;
    if(out[n]!=-1)
        return out[n];
    
    int a = helper(arr+2,n-2,out)+arr[0];
    int b = helper(arr+1,n-1,out);
    // cout<<n<<" "<<max(a,b)<<endl;
    out[n] = max(a,b);
    return out[n];
}



int getMaxMoney(int arr[], int n){

    int* output = new int[n+1];
    for(int i=0;i<=n;i++){
        output[i]=-1;
    }
    return helper(arr,n,output);

}
*/