/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
0 <= N <= 10^4
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2
*/

 	#include<unordered_map>
	void PairSum(int *input, int n) {	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
     	unordered_map<int,int> fre;
        for(int i=0;i<n;i++){
            if(fre.count(input[i])>0){
				fre[input[i]]++;
            }
            else{
                fre[input[i]]=1;
            }
            
            int neg=-input[i];
            if(fre.count(neg)>0){
                int totalcount=fre[neg];
                //cout<<input[i]<<" "<<totalcount<<endl;
                while(totalcount>0){
                    if(input[i]>0)
                    	cout<<neg<<" "<<input[i]<<endl;
                    else
                        cout<<input[i]<<" "<<neg<<endl;
                    totalcount--;
                }
            }
        }
 	}


/*
 	#include<unordered_map>
	void PairSum(int *input, int n) {	 
     	unordered_map<int,int> a;
        for(int i=0;i<n;i++){
            
            if(a.count(input[i])){
                a[input[i]]++;
            }
            else{
                pair<int,int> p(input[i],1);
            a.insert(p);
        }
        }
        //cout<<a[2] * a[-1*2];
            for(int i=0;i<n;i++){
                if(a[input[i]] && a[-1*input[i]]){
                    
                    for(int j=0;j<a[input[i]] * a[-1*input[i]] ; j++){
                        cout<<min(input[i],-1*input[i])<<" "<<max(input[i],-1*input[i])<<endl;
                    }
                    a.erase(input[i]);
                    a.erase(-1*input[i]);
                }
            }

 	}
    

*/