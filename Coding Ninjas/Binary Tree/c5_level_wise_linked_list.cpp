/*
Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output format : Each level linked list is printed in new line (elements separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
*/
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<node<int>*> arr;
	queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    
    node<int>* head=NULL;
    node<int>* tail=NULL;
    while(q.size()!=0){
        BinaryTreeNode<int>* temp=q.front();
        q.pop();
        if(temp==NULL){
           // cout<<"hi1"<<endl;
            if(q.size()!=0)
                q.push(NULL);
            arr.push_back(head);    
            head=NULL;
            tail=NULL;        
        }
        else{
          //  cout<<temp->data<<endl;
           // cout<<"hi2"<<endl;
            node<int>* n=new node<int>(temp->data);
            if(head==NULL){
                head=n; tail=n;
            }
            else{
                tail->next=n; tail=n;
            }
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
    return arr;
}

/*

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int> *> q;
    vector<node<int>*> v;
    node<int> *head = NULL;
    node<int> *tail = NULL;    
    q.push(root);
    q.push(NULL);
    while(q.size()){
        BinaryTreeNode<int> * temp = q.front();
        q.pop();
        if(temp==NULL){
            if(q.size()){
                q.push(NULL);
            }
            v.push_back(head);
            head=NULL;
            tail=NULL;
            
        }
        else{
            node<int> *n = new node<int>(temp->data);
            if(head==NULL){
                head=n;
                tail=n;
            }
            else{
                tail->next = n;
                tail=n;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);           
            
        }
    }
    return v;
}

*/