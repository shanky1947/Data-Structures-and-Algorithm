/*
Level order traversal
Send Feedback
Given a binary tree, print the level order traversal. Make sure each level start in new line.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
*/

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> tree;
    tree.push(root);
    BinaryTreeNode<int>* mynode=new BinaryTreeNode<int>(-2);
    tree.push(mynode);
    int i=0;
    while(tree.size()!=0){
        BinaryTreeNode<int>* temp=tree.front();
        if(temp->data!=-2){
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                tree.push(temp->left);
            if(temp->right!=NULL)
                tree.push(temp->right);
            tree.pop();
        }
		else{
            cout<<endl;
            tree.push(mynode);
            tree.pop();
        	if(tree.front()->data==-2)
			break;
        }
    }
}

/*
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int>*>queue;
    queue.push(root);
    queue.push(NULL);
    while(queue.size()){
        BinaryTreeNode<int>* temp=queue.front();
        queue.pop();
        if(temp==NULL){
        	if(queue.size())
            	queue.push(NULL);
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                queue.push(temp->left);
            if(temp->right!=NULL)
                queue.push(temp->right);
        }
    }
}
*/