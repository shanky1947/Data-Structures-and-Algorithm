/*
Code : Search in Tries
Send Feedback
Implement the function SearchWord for the Trie class.
For a trie, write the function for searching a word. Return true if found successfully otherwise return false.
Note : main function is given for your reference which we are using internally to test the code.

*/

// #include "TrieNode.h"
#include <string>

/***************
 * Main function - 
 
int main() {
    int choice;
    cin >> choice;
    Trie t;
    
    //cout << "asasas";
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 : // insert
                // getline(cin, word);
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
                // getline(cin, word);
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            default :
                return 0;
        }
        cin >> choice;
    }
    return 0;
}
 **************/

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    bool searchHelp(TrieNode *root, string word){
        if(word.size() == 0) {
            return root -> isTerminal;
        }
        int index = word[0] - 'a';
        if(root -> children[index] != NULL) {
            return searchHelp(root->children[index],word.substr(1));
        }
        else {
            return false;
        }
    }
    
    
    bool search(string word) {
        // Write your code here
        return searchHelp(root,word);
    }
};

/*
#include <iostream>
#include <string>
using namespace std;
#include "Trie.h"

int main() {
	int choice;
	cin >> choice;
	Trie t;

	//cout << "asasas";
	while(choice != -1){
		string word;
        bool ans;
		switch(choice) {
            case 1 : // insert
            	// getline(cin, word);
            	cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
            	// getline(cin, word);
            	cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            default :
                return 0;
        }
        cin >> choice;
	}
	return 0;
}
*/

