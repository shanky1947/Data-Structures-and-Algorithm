/*
Balanced
Send Feedback
Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

int height(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    int so1=height(root->left);
    int so2=height(root->right);
    if(so1>so2)
        return so1+1;
    else
        return so2+1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
	int left=height(root->left);
    int right = height(root->right);
   // cout<<left<<" "<<right<<endl;
	if(abs(left-right)>1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}


/*

pair<bool,int> helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        pair<int,int> q;
        q.first = true;
        q.second = 0;
        return q;
    }
    
    pair<bool,int> l = helper(root->left);
    pair<bool,int> r = helper(root->right);
    
    pair<bool,int> result;
    result.second = max(l.second,r.second)+1;
     if(abs(r.second-l.second)<=1){
         result.first = r.first && l.first;
         return result;
     }
    result.first = false;
    return result;
}


bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
	return helper(root).first;
}
*/