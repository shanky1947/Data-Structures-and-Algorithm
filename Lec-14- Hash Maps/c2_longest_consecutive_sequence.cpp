/*
Longest Consecutive Sequence
Send Feedback
You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
*/

#include <vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    int mlength=0,mstart,mindex=INT_MAX;
    int length,start,a;
    int g;

    unordered_map<int,bool> s;
    for(int i=0;i<n;i++){
        s[arr[i]] = true;
    }
    
    for(int i=0;i<n;i++){
        
        /*
        
        if(mark[arr[i]]==true){
            s=arr[i];
            while(true){
                if(mark.count(arr[i]+j)>0){
                    mark[arr[i]+j]=false;
                    length++; }
                else
                    break;
                j++;
            }
           // cout<<"hi1"<<" "<<length<<endl;
            j=1;
            int temp=arr[i];
            while(temp>0){
                temp=arr[i]-j;
                if(mark.count(temp)>0){
                    mark[temp]=false;
                    length++;  s=temp;}
                else
                    break;
                j++;
            }
           // cout<<"hi2"<<" "<<length<<endl;
        	mark[arr[i]]=false;
            

            
            
    	}
        */
        int j=1;
        int length=1;
        if(s[arr[i]] == true){
             start=arr[i];
             //a=arr[i]+1;
            
            while(true){
                if(s.count(arr[i]+j)>0){
                    s[arr[i]+j]=false;
                    length++; }
                else
                    break;
                j++;
            }
            
            
            
            /*while(s[a]==true){
                length++;
                s[a]==false;
                a++;
            }*/
            //a=arr[i]-1;
            
            
            j=1;
            int temp=arr[i];
            while(temp>0){
                temp=arr[i]-j;
                if(s.count(temp)>0){
                    s[temp]=false;
                    length++;  start=temp;}
                else
                    break;
                j++;
            }
            
            /*while(s[a]==true){
                length++;
                start=a;
                s[a]==false;
                a--;
            }*/
            
            for( g=0;g<n;g++){
                if(arr[g]==start)
                    break;
            }            
            
            if(mlength==length){
                if(mindex>g){
                    mstart=start;
                    mindex=g;
                }
            }
            else if(mlength<length){
                mstart=start;
                mlength=length;
                mindex=g;
            }
            
            	
        }
        
    }
    
    vector<int> v;
    for(int i=0;i<mlength;i++){
        v.push_back(mstart);
        mstart++;
    }
    return v;
}

/*
#include <vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    int mlength=0,mstart,mindex=INT_MAX;
    int length,start,a;
    int g;

    unordered_map<int,bool> s;
    for(int i=0;i<n;i++){
        s[arr[i]] = true;
    }
    
    for(int i=0;i<n;i++){
        
        if(s[arr[i]] == true){
             start=arr[i];
             length=1;
             a=arr[i]+1;
            while(s[a]==true){
                length++;
                s[a]=false;
                a++;
            }
            a=arr[i]-1;
            while(s[a]==true){
                length++;
                start=a;
                s[a]=false;
                a--;
            }
            
            for( g=0;g<n;g++){
                if(arr[g]==start)
                    break;
            }            
            
            
            if(mlength<length){
                mstart=start;
                mlength=length;
                mindex=g;
            }
            else if(mlength==length){
                if(mindex>g){
                    mstart=start;
                    mindex=g;
                }
            }     	
        }
        
    }
    
    vector<int> v;
    for(int i=0;i<mlength;i++){
        v.push_back(mstart);
        mstart++;
    }
    return v;
}
*/

/*
#include "Solution.h"
#include<iostream>
using namespace std;

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
*/