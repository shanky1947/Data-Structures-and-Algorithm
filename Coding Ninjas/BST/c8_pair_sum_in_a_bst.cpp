/*
Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
Assume BST contains all unique elements.
Note: In a pair, print the smaller element first.
Input format:

Line 1: Elements in the level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2: S

Output format: Each pair in a different line (pair elements separated by space)

Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output
2 10
5 7
*/

vector<int> arr(BinaryTreeNode<int> *root){
    vector<int> v;
    if(root==NULL)
        return v;
    v.push_back(root->data);
    vector<int> temp1=arr(root->left);
    for(int i=0;i!=temp1.size();i++)
    	v.push_back(temp1[i]);
    vector<int> temp2=arr(root->right);
    for(int i=0;i!=temp2.size();i++)
    	v.push_back(temp2[i]);
    return v;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int> v;
    v=arr(root);
    sort(v.begin(),v.end());
	int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        else if(v[i]+v[j]>sum){
            j--;
        }
        else
            i++;
    }
    
}

/*
int len(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    return len(root->left)+len(root->right)+1;
}


void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root==NULL)
        return;
	stack<BinaryTreeNode<int>*> in;
	stack<BinaryTreeNode<int>*> rev;
	
    int totalcount=len(root);
    int count=0;
    
    BinaryTreeNode<int>* temp=root;
	while(temp!=NULL){
        in.push(temp);
        temp=temp->left;
    }
    temp=root;
	while(temp!=NULL){
        rev.push(temp);
        temp=temp->right;
    }
    
    while(count<totalcount-1){
        BinaryTreeNode<int> *top1=in.top();
        BinaryTreeNode<int> *top2=rev.top();
        
        if(top1->data+top2->data==s){
            if(top1->data<top2->data)
            	cout<<top1->data<<" "<<top2->data<<endl;
            else
                cout<<top2->data<<" "<<top1->data<<endl;
            count++;
            BinaryTreeNode<int> *top=top1;
            in.pop(); 
            if(top->right!=NULL){
                top=top->right;
                while(top!=NULL){
                    in.push(top);
                    top=top->left;
                }
            }
            count++;
            top=top2;
            rev.pop();
            if(top->left!=NULL){
                top=top->left;
                while(top!=NULL){
                    rev.push(top);
                    top=top->right;
                }
            }
        }
        else if(top1->data+top2->data>s){
            BinaryTreeNode<int>* top=top2;
            count++;
            rev.pop();
            if(top->left!=NULL){
                top=top->left;
                while(top!=NULL){
                    rev.push(top);
                    top=top->right;
                }
            }
        }
        else{
            BinaryTreeNode<int>* top=top1;
            in.pop();
            count++;
            if(top->right!=NULL){
                top=top->right;
                while(top!=NULL){
                    in.push(top);
                    top=top->left;
                }
            }
        }
	}
}
*/
