/* Given a binary tree, and a val, Print the path to that val in the binary tree if exist, otherwise display not exist e.g.
 *                                1
 *                               / \
 *                              2   3
 *                             / \   \
 *                            4   5   7
 *
 *                            If user enter 7, the output should be 1->3->7
 */


#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
struct Node* getNode(int data) 
{ 
    struct Node *newNode = new Node; 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
  
bool pathExist(Node *root, vector<int>& v, int val) 
{ 
    if (root==NULL) 
        return false; 
      
    v.push_back(root->data);     
      
    if (root->data == val)     
        return true; 
      
    if (pathExist(root->left, v, val) || 
        pathExist(root->right, v, val)) 
        return true; 
      
    v.pop_back(); 
    return false;             
} 
 
void displayPath(Node *root, int val) 
{ 
    vector<int> v; 
      
    if (pathExist(root, v, val)) 
    { 
        for (int i: v)     
            cout << i << "->"; 
    } 
    
    else
        cout << "Not exist"; 
} 
  
int main() 
{ 
    struct Node *root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
          
    int x = 7; 
    displayPath(root, x); 
    return 0; 
} 
