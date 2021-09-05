/*
Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/

class bst{
public:
    int height;
    int maximum;
    int minimum;
    bool isBst;
};
bst helper(BinaryTreeNode<int> *root){
	if(root==NULL){
        bst b;
        b.maximum=INT_MIN;
        b.minimum=INT_MAX;
        b.isBst=true;
        b.height=0;
        return b;
    }
    bst left=helper(root->left);
    bst right=helper(root->right);
    bst b;
    b.maximum=max(root->data,max(left.maximum,right.maximum));
    b.minimum=min(root->data,min(left.minimum,right.minimum));
    b.isBst=left.isBst && right.isBst && (root->data>left.maximum) && (root->data<right.minimum);
    if(left.height>right.height)
        b.height=left.height;
    else
        b.height=right.height;
    if(b.isBst)
        b.height+=1;
    
    return b;
}


int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	return helper(root).height;
}

/*
#include<bits/stdc++.h>
class bst{
    public:
    int max,min,h;
    bool isBst;
    
};

bst helper(BinaryTreeNode<int> *root){
    bst result;
    
    if(root==NULL){
        result.max = INT_MIN;
            result.min = INT_MAX;
            result.h = 0;
            result.isBst = true;
            return result;
    }
    
    
    bst l = helper(root->left);
    bst r = helper(root->right);
    
    if(l.isBst==true && r.isBst==true && l.max<root->data && r.min>root->data){
            
            result.min = min(l.min,root->data);
            result.max = max(r.max,root->data);
            result.h = max(r.h,l.h)+1;
            result.isBst = true;
            return result;        
    }
    else{
        result.max = r.max;///////////////////
            result.min = l.min;//////////////////
            result.h = max(r.h,l.h);
            result.isBst = false;
            return result;
    }
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return helper(root).h;
}

*/
