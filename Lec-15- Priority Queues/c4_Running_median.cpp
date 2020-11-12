/*
Running median
Send Feedback
You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer N, denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list on a new line.
Input Constraints
1 <= N <= 10^5
1 <= Ai <= 10^5

Time Limit: 1sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5
4
4
3
3
*/

#include<queue>
#include<bits/stdc++.h>
using namespace std;
void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    
        //priority_queue<int> pq;

    
    for(int i=0;i<n;i++){
        if(max.empty()){
            max.push(arr[i]);
        }
        else{
            if(arr[i]>max.top()){
                min.push(arr[i]);
            }
            else{
                max.push(arr[i]);
            }
        }
            
            while(abs(max.size()-min.size())>1){
               
                if(max.size()>min.size()){
                    min.push(max.top());
                     
                    max.pop();
                }else{
                    max.push(min.top());
                    min.pop();
                }
            }
           // cout<<arr[i]<<max.size()<<" "<<min.size()<<" "<<endl;
            if((max.size()+min.size())%2 == 0){
                
                cout<<(max.top()+min.top())/2<<endl;
            }else if(max.size()>min.size()){
                    cout<<max.top()<<endl;
            }else{
                    cout<<min.top()<<endl;
            }
    }


}

/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    
    int n;
    cin >> n;

    int arr[n], i;
    for(i=0;i<n;i++) cin >> arr[i];

    findMedian(arr, n);
}
*/

/*
Other solution-
#include<queue>
#include<bits/stdc++.h>
using namespace std;
void findMedian(int arr[], int n){

	priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    max.push(arr[0]);
    cout<<arr[0]<<endl;
    for(int i=1;i<n;i++){
		if(arr[i]>max.top())
            min.push(arr[i]);
        else
            max.push(arr[i]);
        if(abs(max.size()-min.size())>1){
            if(max.size()>min.size()){
                int temp=max.top();
            	max.pop();
            	min.push(temp);
            }
            else{
                int temp=min.top();
            	min.pop();
            	max.push(temp);  
            }
        }
        if(abs(max.size()-min.size())==1){
            if(max.size()>min.size())
                cout<<max.top()<<endl; 
            else
                cout<<min.top()<<endl;
        }
        else if(max.size()==min.size()){
            cout<<(min.top()+max.top())/2<<endl;
        }
    }
}
*/