/*
Code: Construct BST from a Sorted Array
Send Feedback
Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note : If array size is even, take first mid as root.
Input format :
Line 1 : Integer n (Size of array)
Line 2 : Array elements (separated by space)
Output Format :
BST elements (in pre order traversal, separated by space)
Sample Input :
7
1 2 3 4 5 6 7
Sample Output :
4 2 1 3 6 5 7 
*/



BinaryTreeNode<int>* abc(int *a, int s, int e){
    if(s>e)
        return NULL;
    int m=(s+e)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(a[m]);
    root->left=abc(a, s, m-1);
    root->right=abc(a, m+1, e);
    return root;
}
BinaryTreeNode<int>* constrctTree(int *input, int n){
    return abc(input, 0, n-1);
}





/*
BinaryTreeNode<int>* constructTree(int *input, int n) {

    if(n==0)
        return NULL;
	int len=(n+1)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[len-1]);
    root->left=constructTree(input,len-1);
    root->right=constructTree(input+len,n-len);
    return root;
}
*/