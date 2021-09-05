/*
Coin Tower
Send Feedback
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus

*/

string solve(int n, int x, int y)
{
	// Write your code here .
    
    int dp[n+1];
    
    dp[1] = 1;
    dp[x] = 1;
    dp[y] = 1;
    for(int i=2;i<=n;i++){
        if(i==x ||i==y){
         continue;
        }
           
        int b = -2,c = -2;
        int a = dp[i-1]^1;
        if(i-x>0)
            b = dp[i-x]^1;
        if(i-y>0)
            c = dp[i-y]^1;
        
        dp[i] = max(a,max(b,c));
        //cout<<dp[i]<<endl;
    }
    if(dp[n]==1){
        return "Beerus";
    }else{
        return "Whis";
    }


}

/*
#include<bits/stdc++.h>
using namespace std;
string solve(int n, int x, int y)
{
	int *output=new int[n+1];
    output[0]=0;
    output[1]=1;
    for(int i=2;i<=n;i++){
        int tx=INT_MIN,ty=INT_MIN;
        if(i-x>=0)
            tx=output[i-x] ^ 1;
        if(i-y>=0)
            ty=output[i-y] ^ 1;
        int tz=output[i-1] ^ 1;
        output[i]=max(tz,max(tx,ty));
    }
    //for(int i=0;i<=n;i++)
        //cout<<output[i]<<endl;
    if(output[n]==0)
        return "Whis";
    else
        return "Beerus";
}
*/

