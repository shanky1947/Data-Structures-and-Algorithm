/*
Print nodes at distance k from node
Send Feedback
Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : Node

Line 3 : K

Output format : Answer nodes in different line

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3
1
Sample Output :
9
6
*/

void print(BinaryTreeNode<int> *root, int k){
    if(root==NULL)
        return;
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    print(root->left,k-1);
    print(root->right,k-1);
}

int helper(BinaryTreeNode<int> *root, int node, int k){
    if(root==NULL)
        return -1;
  
    if(root->data==node){
        print(root,k);
        return 0;
    }
    else{
        int leftd=helper(root->left,node,k);
        if(leftd!=-1){
            if(leftd+1==k){
                cout<<root->data<<endl;
                return leftd+1;
            }
            else
                print(root->right,k-leftd-2);
        }
        
        int rightd=helper(root->right,node,k);
        if(rightd!=-1){
            if(rightd+1==k){
                cout<<root->data<<endl;
                return rightd+1;
            }
            else
                print(root->left,k-rightd-2);
        }
        if(leftd==-1 && rightd==-1)
        	return -1;
        else if(leftd>rightd)
            return leftd+1;
        else
            return rightd+1;
    }
}


void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    int res=helper(root,node,k);
}
