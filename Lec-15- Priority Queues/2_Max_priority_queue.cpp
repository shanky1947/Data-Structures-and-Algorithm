/*
Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

*/


/***************
 * Following is the main function that er are using internally
 *
 
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
*******************/
#include <vector>
class PriorityQueue {
    // Complete this class
    vector<int> pq;
    
    public:   
    PriorityQueue(){
        
    }
    
    int getSize(){
        return pq.size();
    }
    
    bool isEmpty(){
        return pq.size()==0;
    }
    
    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    
    void insert(int element){
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    
     int removeMax() {

        int ans = pq[0];
        int last = pq.size()-1;
        
        int temp = pq[0];
        pq[0] = pq[last];
        pq[last] = temp;
        
        pq.pop_back();
        
        int parent = 0;
        int childRight = 2*parent+2;
        int childLeft = 2*parent+1;
        
        while(childLeft<=pq.size()){
        
           
        if( childRight<=pq.size()-1 &&pq[parent]<max(pq[childLeft],pq[childRight])){
            if(pq[childRight]>pq[childLeft]){
                int temp = pq[childRight];
               	pq[childRight] = pq[parent];
                pq[parent] = temp;
                    
                parent = childRight;
            }else{
                int temp = pq[childLeft];
               	pq[childLeft] = pq[parent];
                pq[parent] = temp;
                parent = childLeft;
            }     
        }
        else if(pq[parent]<pq[childLeft]){
                int temp = pq[childLeft];
               	pq[childLeft] = pq[parent];
                pq[parent] = temp;
                parent = childLeft;
            }
        else{
            break;
        } 
        childRight = 2*parent+2;
        childLeft = 2*parent+1;

    }
        return ans;
     }
    
    
    
};