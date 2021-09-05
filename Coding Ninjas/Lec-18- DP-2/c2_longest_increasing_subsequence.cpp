/*
Longest Increasing Subsequence
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
Line 1 : An integer N 
Line 2 : Elements of arrays separated by spaces
Output Format
Line 1 : Length of longest subsequence
Input Constraints
1 <= n <= 10^3
Sample Input :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2:
3
1 2 2
Sample Output 2 :
2
*/

using namespace std;

 int lis(int arr[], int n) {
		
				
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	int* out = new int[n];
    out[0]=1;
     
     for(int i=1;i<n;i++){
         out[i]=1;
         for(int j=i-1;j>=0;j--){
             if(arr[j]<arr[i]){
                 if(out[j]+1>out[i])
                     out[i]=out[j]+1;
             }
         }
     }
     
     int max=0;
     for(int i=0;i<n;i++){
         if(out[i]>max)
        	max=out[i];
     }
     return max;     
 }



 /*
 other-
 using namespace std;

 int lis(int arr[], int n) {
	int *output=new int[n];
     output[0]=1;
    for(int i=1;i<n;i++){
        int j=i-1;
        output[i]=1;
        while(j>=0){
            if(arr[j]<arr[i])
                if(output[j]>=output[i])
                    output[i]=output[j]+1;
            j--;
        }
    } 
     int max=0;
    for(int i=0;i<n;i++)
        if(output[i]>max)
     		max=output[i];
     return max;
 }
 */