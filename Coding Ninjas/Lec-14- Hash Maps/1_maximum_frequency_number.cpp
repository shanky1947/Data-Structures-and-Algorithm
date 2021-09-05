/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
0 <= N <= 10^8
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/
 	#include<unordered_map>
	int highestFrequency(int *input, int n){	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
    	unordered_map<int, int> arr;
        for(int i=0;i<n;i++){
            if(arr.count(input[i])>0){
                arr[input[i]]+=1;
            }
            else
                arr[input[i]]=1;
        }
        int max=0,j;
     	for(int i=0;i<n;i++){
            if(arr[input[i]]>max){
                max=arr[input[i]];
                j=i;
            }
        }
        return input[j];
 	}

/*
#include<unordered_map>
	int highestFrequency(int *input, int n){	 

     	unordered_map<int, int> seen;
        
     	for(int i=0;i<n;i++){
            if(seen.count(input[i]))
                seen[input[i]]++;
            else
                seen[input[i]]=1;
        }
        
        int ans = input[0];
        int max = seen[input[0]];
        int j=1;
        while(j<n){
            if(seen[input[j]]>max){
                max = seen[input[j]];
                ans= input[j];
            }
            j++;
        }
        return ans;
     	
 	}
*/