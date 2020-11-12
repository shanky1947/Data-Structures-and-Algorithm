/*
Code: Construct Tree from Preorder and Inorder
Send Feedback
Given Preorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Pre order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
12
1 2 3 4 15 5 6 7 8 10 9 12
4 15 3 2 5 1 6 10 8 7 9 12
Sample Output :
1 
2 6 
3 5 7 
4 8 9 
15 10 12
*/

BinaryTreeNode<int>* helper(int *preorder,int *inorder,int preStart,int preEnd,int inStart, int inEnd){
    if(preStart>preEnd)
        return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[preStart]);
    int a=inStart;
    while(inorder[a]!=preorder[preStart]){
        a++;
    }
    int q=a-inStart;
   	root->left=helper(preorder,inorder,preStart+1,preStart+q,inStart,inStart+a-1);
    root->right=helper(preorder,inorder,preStart+1+q,preEnd,a+1,inEnd);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	return helper(preorder,inorder,0,preLength-1,0,inLength-1);
}
