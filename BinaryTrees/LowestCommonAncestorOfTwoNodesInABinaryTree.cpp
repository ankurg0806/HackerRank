/*
 *                     1
 *                    / \
 *                   2   3
 *                  / \   \
 *                 5   6   7 
 *                / \   \
 *               8   9   10
 *
 *               In this tree, the lowest common ancestor of 8 and 10 is 2, as 2 is the node which is a common ancestor for both 8 and 10(lowest)
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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
bool pathExist(Node *root, vector<Node*>& v, int val)
    {
        if (root==NULL)
            return false;

        v.push_back(root);

        if (root->data == val)
            return true;

        if (pathExist(root->left, v, val) ||
            pathExist(root->right, v, val))
            return true;

        v.pop_back();
        return false;
    }
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        vector<Node*> ar1, ar2;
        if (pathExist(root, ar1, v1) &&
            pathExist(root, ar2, v2))
            {
                cout<<"here";
                if(ar1.size()==1||ar2.size()==1)
                    return root;
                for(int i=0;i<ar1.size()&&i<ar2.size();i++)
                {
                    cout<<"Here";
                    if(ar1[i]->data!=ar2[i]->data)
                    {
                        return ar1[i-1];
                    }
                }
                return ar1[ar1.size()-1];
            }
            return NULL;
    }

}; //End of Solution

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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}

