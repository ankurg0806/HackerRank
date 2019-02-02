/*                       4
                        / \
                       2   7
                      / \
                     1   3
A Binary Search tree has a property that at any node, it's left child must be lesser than current node, and it's right child must be greater than current node.
If we have to insert 6 in it.
The output should be like this
         4
       /   \
      2     7
     / \   /
    1   3 6

*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

    Node * insert(Node * root, int data) {
        
        if(root==NULL)
        {
            return new Node(data);
        }
        if(root->data > data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }

        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}

