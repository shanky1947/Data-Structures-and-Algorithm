/*
Path Sum Root to Leaf
Send Feedback
Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : k

Output format : Print each path in new line, elements separated by space

Sample Input 1 :
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
Sample Output 1 :
5 6 2
5 7 1
*/

void print(BinaryTreeNode<int> *root, int k, string s){
    
    if(root==NULL)
        return;
    if(!root->right && !root->left){
        if(root->data == k)
            cout<<s<<root->data<<endl;
    return;
    }
    s=s + to_string(root->data)+" ";
    print(root->right,k-root->data,s);
    print(root->left,k-root->data,s);
    
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
	string s="";
    print(root,k,s);
}


int helper(BinaryTreeNode<int> *root, int k,vector<int> res){
	if(root==NULL)
        return 0;
    res.push_back(root->data);
    int so1=helper(root->left,k-root->data,res);
    int so2=helper(root->right,k-root->data,res);
    if(so1==0 && so2==0){
        if(k==root->data){
            for(int i=0;i<res.size();i++)
                cout<<res[i]<<" ";
        }
        res.erase(res.end()-1);
    }
    return 1;
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> res;
	int s=helper(root,k,res);
}

