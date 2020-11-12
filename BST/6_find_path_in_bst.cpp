/*
Find Path in BST
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST). Return null otherwise.
Assume that BST contains all unique elements.
Input Format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer k
Output Format :
Path from node k to root
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output :
2
5
8
*/
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if(root==NULL)
        return NULL;
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if(data<root->data){
        vector<int>* leftoutput=findPath(root->left,data);
        if(leftoutput!=NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }
    }
    else if(data>root->data){
        vector<int>* rightoutput=findPath(root->right,data);
        if(rightoutput!=NULL){
            rightoutput->push_back(root->data);
            return rightoutput;
        }
    }
    else
        return NULL;
}


/*
vector<int>* findPath(BinaryTreeNode<int> *root , int data){

vector<int>* v = new vector<int>();
    if(root==NULL){
        return NULL;
    }
    if(data==root->data){
        v->push_back(root->data);
        return v;
    }
    
    if(data>root->data){
        v = findPath(root->right,data);
    }
    if(data<root->data){
        v = findPath(root->left,data);        
    }
    if(v!=NULL){
    v->push_back(root->data); 
    }
    
    return v;
}

*/