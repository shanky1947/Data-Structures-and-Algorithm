/*
Min and Max of Binary Tree
Send Feedback
Given a binary tree, find and return the min and max data value of given binary tree.
Return the output as an object of PairAns class, which is already created.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Max and min (separated by space)
Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output :
14 1
*/

PairAns minMax(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if(root==NULL){
        PairAns p;
        p.min=INT_MAX;
        p.max=INT_MIN;
        return p;
    }
    PairAns l=minMax(root->left);
    PairAns r=minMax(root->right);
    PairAns res;
    res.min=min(root->data,min(l.min,r.min));
    res.max=max(root->data,max(l.max,r.max));
	return res;
}