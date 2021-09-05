/*
Pair sum BInary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
Output Format :
Each pair in different line (pair elements separated by space)
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

vector<int> arr(BinaryTreeNode<int> *root){
    vector<int> v;
    if(root==NULL)
        return v;
    v.push_back(root->data);
    vector<int> temp1=arr(root->left);
    for(int i=0;i!=temp1.size();i++)
    	v.push_back(temp1[i]);
    vector<int> temp2=arr(root->right);
    for(int i=0;i!=temp2.size();i++)
    	v.push_back(temp2[i]);
    return v;
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int> v;
    v=arr(root);
    sort(v.begin(),v.end());
	int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        else if(v[i]+v[j]>sum){
            j--;
        }
        else
            i++;
    }
    
}