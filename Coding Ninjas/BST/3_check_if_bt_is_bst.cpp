/*
Check if a Binary Tree is BST
Send Feedback
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
Duplicate elements should be in right subtree.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
true or false
Constraints :
1 <= N <= 10^5
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/
#include<bits/stdc++.h>
bool helper(BinaryTreeNode<int> *root,int maximum,int minimum){
    if(root==NULL)
        return true;
    if(root->data<minimum || root->data>maximum)
        return false;
    bool left=helper(root->left,root->data-1,minimum);
    bool right=helper(root->right,maximum,root->data);
    return left && right;
}

bool isBST(BinaryTreeNode<int> *root){
       /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
	return helper(root,INT_MAX,INT_MIN);
}