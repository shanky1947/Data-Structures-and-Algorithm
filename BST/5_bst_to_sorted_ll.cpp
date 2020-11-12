/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. Return the head of LL.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Linked list elements (separated by space)
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
2 5 6 7 8 10
*/

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root==NULL)
        return NULL;
    Node<int>* headroot=new Node<int>(root->data);
    Node<int>* headl=constructBST(root->left);
    Node<int>* headr=constructBST(root->right);
    headroot->next=headr;
    if(headl!=NULL){
        Node<int>* temp=headl;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=headroot;
        return headl;
    }
    else
    	return headroot;
}