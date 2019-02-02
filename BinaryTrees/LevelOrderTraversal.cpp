/* LevelOrderTraversal means all nodes at same depth should be traversed from left to right before going to the next depth. Queue DS is used to implement level order traversal because Queue keep track of the children of current node and push them to the end and each time we pop a node from queue, we print it and push it's children into the queue.
 *
 *
 *                           1
 *                          / \
 *                         2   3
 *                        / \   \
 *                       4   5   7
 *                       the output should be 1 2 3 4 5 7
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

    void levelOrder(Node * root) {
        if(root==NULL)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            q.pop();
        }
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
  
	myTree.levelOrder(root);
    return 0;
}

