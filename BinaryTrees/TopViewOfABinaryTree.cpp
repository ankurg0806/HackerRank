#include<bits/stdc++.h>

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

    void topView(Node * root) {
        map<int, int> mymap;
        queue<pair<Node*, int>> q;
        if(root==NULL)
        {
            return;
        }
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*, int> p = q.front();
            q.pop();
            int data = p.first->data;
            int val = p.second;
            if(mymap.find(val)==mymap.end())
                {
                    mymap[val] = data;
                }
            if(p.first->left)
            {
                q.push(make_pair(p.first->left, val-1));
            }
            if(p.first->right)
            {
                q.push(make_pair(p.first->right, val+1));
            }
        }
	for(auto& it: mymap)
        {
            cout<<it.second<<" ";
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
  
	myTree.topView(root);
    return 0;
}


/* Explanation : The idea is to do a kind of level order traversal for traversing all nodes. We are calculating a kind of distance from root for all nodes.
 * And by using level order traversal, We are making sure that we will display any node at a specific distance in some logical order. We used unordered_map 
 * so that it can serve as a data structure, where we will check whether the map already have a node of that specific distance. If it is there, that means we 
 * have already displayed a node in that view. When I say "in that view" it means the nodes 4 and 7 are in same view from top, thus only 4 should be displayed. And 
 * the algorithm should compute same distance for 4 and 7. Plus, because We use level order traversal, we make sure We will encounter node 4 before node 7.
 *
 *
 *
 *
 *                                          1
 *                                         / \
 *                                        3   4
 *                                       / \
 *                                      5   6
 *                                           \
 *                                            7
 *
 *                                            For this tree the output should be 1 3 4 5
