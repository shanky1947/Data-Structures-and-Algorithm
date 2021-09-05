/*
Longest subset zero sum
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
NOTE: You have to return the length of longest subarray .
Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces
Output Format
 Line 1 : Length of longest subarray 
Constraints:
0 <= N <= 10^8
Sample Input :
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output :
5
*/

#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
	unordered_map<int,int> m;
    int sum=0,max=0;
    if(size==1 && arr[0]==0)
        return 1;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        if(m.count(sum)==0)
            m[sum]=i;
        else{
            int count=i-m[sum];
            if(count>max)
                max=count;
        }
    }
    return max;
}


/*
#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
    if(n==1){
        if(arr[0]==0){
            return 1;
        }
    }
  unordered_map<int,int> s;
    int sum=0;
    int mlength=0;
    for(int i=0;i<n;i++){
        int length=0;
        sum+=arr[i];
        
        if(s.count(sum)>0){
            length = abs(s[sum]-i);
        }
        else{
            s[sum]=i;
        }
        //cout<<sum<<endl;
        if(length>mlength)
            mlength=length;      
    }
    return mlength;
	
}
*/

/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}



*/