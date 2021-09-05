/*
Code : Remove Min
Send Feedback
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.
*/

#include <vector>

/*******************
 * Main function -
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
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
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
**************************/


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
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
    
    int removeMin() {

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
        
           
        if( childRight<=pq.size()-1 &&pq[parent]>min(pq[childLeft],pq[childRight])){
            if(pq[childRight]<pq[childLeft]){
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
        else if(pq[parent]>pq[childLeft]){
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
