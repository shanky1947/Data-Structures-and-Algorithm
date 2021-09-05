/*
Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BSt or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
Note : main function is given for your reference which we are using internally to test the class

*/


class BST {
	// Complete this class
    BinaryTreeNode<int>* root;
    public:
    BST(){
        root=NULL;
    }
    
    private:
    
    bool search_help(int data, BinaryTreeNode<int>* root){
        if(root==NULL){
            return false;
        }
        
        if(data == root->data)
            return true;
        if(data>root->data)
            return search_help(data,root->right);
        return search_help(data,root->left);
        
    }
    
    BinaryTreeNode<int>* insert_help(int data,BinaryTreeNode<int>* root1){
        //cout<<"hi"<<endl;
        if(root1==NULL){
            //cout<<root<<" "<<root1<<" "<<endl;
            BinaryTreeNode<int>* d = new BinaryTreeNode<int>(data);
            
            root1=d;
            
            
            return d;   
        }
        //cout<<"hi"<<endl;
        if(root1->data>data){
        	root1->left = insert_help(data,root1->left);
            //cout<<"hi"<<endl;
        }
        if(root1->data<data){
        	root1->right = insert_help(data,root1->right);
            //cout<<"hi"<<endl;
        }
        //cout<<"hi"<<endl;
        return root1;
    }
    
    int minimum(BinaryTreeNode<int>* root){
        if(root->left==NULL){
            return root->data;
        }
        return minimum(root->left);
    }
    
    
    BinaryTreeNode<int>* delete_help(int data,BinaryTreeNode<int>* root){
        if(root==NULL){
            return NULL;
        }
        if(root->data>data){
        	root->left = delete_help(data,root->left);
            return root;
        }
        if(root->data<data){
        	root->right = delete_help(data,root->right);
            return root;
        }
        
        if(root->right==NULL && root->left==NULL){
            return NULL;
        }
        if(root->right==NULL){
            return root->left;
        }
        if(root->left==NULL){
            return root->right;
        }
        
        int min= minimum(root->right);
        root->data=min;
        root->right = delete_help(min,root->right);
        return root;
        
    }
    
    void printTree_help(BinaryTreeNode<int>* root) {
        if(root==NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        printTree_help(root->left);
        printTree_help(root->right);
    }
    
    
    public:
    bool hasData(int data){
        return search_help(data,root);
    }
    
    
    void insert(int data){
        //cout<<"hi"<<endl;
        root = insert_help(data,root);
    }
    
    void deleteData(int data){
        delete_help(data,root);
    }
    
	void printTree(){
        printTree_help(root);
    }

};