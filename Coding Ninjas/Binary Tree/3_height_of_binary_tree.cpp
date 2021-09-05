/*
Code : Height of Binary Tree
Send Feedback
Given a binary tree, find and return the height of given tree.
Input format :
Nodes in the level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Height
Constraints :
1 <= N <= 10^5
Sample Input :
10
 9 
4 
-1 
-1 
 5 
 8 
-1 
6 
-1 
-1 
3 
-1 
-1
-1
Sample Output :
5
*/
#include<bits/stdc++.h>

int height(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)) + 1;
     
}


/*
int height(BinaryTreeNode<int> *root) {

    int max=0;
	if(root==NULL)
        return 0;
    int so1=height(root->left);
    if(so1>max)
        max=so1;
    int so2=height(root->right);
    if(so2>max)
        max=so2;
    return max+1;
}

*/