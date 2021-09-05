/*
Pairs with difference K
Send Feedback
You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
0 <= n <= 10^4
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4

*/
#include<unordered_map>
void printPairs(int *input, int n, int k) {
	// Write your code here
    unordered_map<int,int> arr;
	for(int i=0;i<n;i++){
        if(arr.count(input[i])==0)
            arr[input[i]]=1;
        else
            arr[input[i]]++;
    }
    
    if(k==0){
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                cout<<input[i]<<" "<<input[j]<<endl;
    	return;
    }
    for(int i=0;i<n;i++){
        int alt=(input[i]+k);
        if(arr.count(alt)>0){
            int totalcount=arr[alt]*arr[input[i]];
            //cout<<totalcount<<endl;
         	while(totalcount>0){
                cout<<input[i]<<" "<<alt<<endl;
                totalcount--;
            }
        }
        alt=(input[i]-k);
        if(arr.count(alt)>0){
            int totalcount=arr[alt]*arr[input[i]];
           // cout<<totalcount<<endl;
         	while(totalcount>0){
                cout<<alt<<" "<<input[i]<<endl;
                totalcount--;
            }
        }
        arr[input[i]]=0;
    }
}


/*
#include<unordered_map>
void printPairs(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> a;
	for(int i=0;i<n;i++){
        if(a.count(arr[i])>0){
            a[arr[i]]++;
        }
        else{
            a[arr[i]]=1;
        }
    }
    for(int i=0;i<n;i++){
        
        if(k==0){
            int s = a[arr[i]];
            int count=(s*(s-1))/2;
            for(int j=0;j<count;j++)
                cout<<arr[i]<<" "<<arr[i]<<endl;
                    a.erase(arr[i]);

        }
        else{
        int s = a[arr[i]-k] * a[arr[i]];
        int d = a[arr[i]] * a[k+arr[i]];
        while(s>0){
            //cout<<arr[i]<<"y";
            cout<<min(arr[i]-k,arr[i])<<" "<<max(arr[i]-k,arr[i])<<endl;
            s--;
        }
        while(d>0){
            //cout<<arr[i]<<"n";

            cout<<min(k+arr[i],arr[i])<<" "<<max(k+arr[i],arr[i])<<endl;
            d--;
        }
        a.erase(arr[i]);
    }
    }
    
}

*/

/*
#include<iostream>
using namespace std;
#include "solution.h"

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}

*/