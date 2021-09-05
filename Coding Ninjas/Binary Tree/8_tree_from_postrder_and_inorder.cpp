/*
Construct Tree from Postorder and Inorder
Send Feedback
Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Post order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
8
8 4 5 2 6 7 3 1
4 8 2 5 1 6 3 7
Sample Output :
1 
2 3 
4 5 6 7 
8
*/

BinaryTreeNode<int>* helper(int *postorder, int *inorder, int postStart,int postEnd, int inStart, int inEnd) {
    
    if(postStart>postEnd){
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postEnd]);
    int a = inStart;
    while(inorder[a]!=postorder[postEnd]){
        a++;
    }
    int q = a-inStart;
    root->left = helper(postorder,inorder,postStart,postStart+q-1,inStart,a-1);
    root->right = helper(postorder,inorder,postStart+q,postEnd-1,a+1,inEnd);
    return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	return helper(postorder,inorder,0,postLength-1,0,inLength-1);
}