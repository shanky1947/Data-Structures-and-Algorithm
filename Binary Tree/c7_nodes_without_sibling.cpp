/*
Nodes without sibling
Send Feedback
Given a binary tree, print all nodes that don’t have a sibling.
Edit : Print the elements in different lines. And order of elements doesn't matter.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.
Output format :
Print nodes separated by new line.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
9    
*/

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)
        return;
    if(root->left==NULL || root->right==NULL){
        if(root->left!=NULL)
            cout<<root->left->data<<endl;
            
        if(root->right!=NULL)
            cout<<root->right->data<<endl;
    }
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}
