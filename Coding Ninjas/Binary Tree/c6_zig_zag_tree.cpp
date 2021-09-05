/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    int i=0;
    while(s1.size()!=0 || s2.size()!=0){
    	if(i==0){
            BinaryTreeNode<int> *temp=s1.top();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                s2.push(temp->left);
            if(temp->right!=NULL)
                s2.push(temp->right);
            s1.pop();
            if(s1.size()==0){
           		cout<<endl;
                i=1;}
        }
        else{
            BinaryTreeNode<int> *temp1=s2.top();
            cout<<temp1->data<<" ";
            if(temp1->right!=NULL)
                s1.push(temp1->right);
            if(temp1->left!=NULL)
                s1.push(temp1->left);
            s2.pop();
        	if(s2.size()==0){
            	cout<<endl;
                i=0;}
        }

    }
}
