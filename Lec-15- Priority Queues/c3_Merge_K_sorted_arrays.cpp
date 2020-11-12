/*
Merge K sorted arrays
Send Feedback
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234
*/
#include<queue>
#include<vector>

using namespace std;


class triplet{
    public:
    int element;
    int ai;
    int ei;
};


class comp{
    public:
    bool operator()(triplet const * first, triplet const * second){
        return first->element > second->element;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
  /*  pair<pair<int,int>,int> p;
    pair<int,int> small;
    small.first=2;
    small.second=4;
    p.first=small;
    p.second=5;*/
    vector<int> output;
    priority_queue<triplet*, vector<triplet*>, comp > pq;
    
    for(int i = 0; i<input.size(); i++){
        
        triplet * temp = new triplet;
        temp->element = input.at(i)->at(0);
        temp->ai = i;
        temp->ei = 0;
        
        pq.push(temp);
        
    }
    
    while(!pq.empty()){
        
        triplet * ans = pq.top();
        pq.pop();
        output.push_back(ans->element);
        
        if(ans->ei+1 < (input.at(ans->ai)->size())){
            triplet * temp = new triplet;
            temp->element = input.at(ans->ai)->at(ans->ei+1);
            temp->ai = ans->ai;
            temp->ei = ans->ei+1;
            
            pq.push(temp);
                                                
        }
       
    }
    
    return output;

}

/*
#include <iostream>
using namespace std;
#include <vector>
#include "Solution.h"

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
*/