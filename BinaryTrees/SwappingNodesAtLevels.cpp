/*For Example Here we perform swap operations at the nodes whose depth is either 2 or 4 for  and then at nodes whose depth is 4 for .

         1                     1                          1             
        / \                   / \                        / \            
       /   \                 /   \                      /   \           
      2     3    [s]        2     3                    2     3          
     /      /                \     \                    \     \         
    /      /                  \     \                    \     \        
   4      5          ->        4     5          ->        4     5       
  /      / \                  /     / \                  /     / \      
 /      /   \                /     /   \                /     /   \     
6      7     8   [s]        6     7     8   [s]        6     7     8
 \          / \            /           / \              \         / \   
  \        /   \          /           /   \              \       /   \  
   9      10   11        9           11   10              9     10   11 
*/


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
 struct Node
 {
     int data;
     struct Node* left;
     struct Node* right;
 };
 struct Node* createTree(vector<vector<int>>& v )
 {
     struct Node* root = new Node;
     root->data = 1;
     root->left = NULL;
     root->right = NULL;
     queue<Node*> q;
     q.push(root);
     for(int i=0;i<v.size();i++)
     {
         struct Node* temp = q.front();
         if(v[i][0] == -1)
         {
             temp->left = NULL;
         }
         else
         {
             temp->left = new Node;
             temp->left->data = v[i][0];
             temp->left->left = NULL;
             temp->left->right = NULL;
             q.push(temp->left);
         }
         if(v[i][1] == -1)
         {
             temp->right=NULL;
         }
         else
         {
           temp->right = new Node;
           temp->right->data = v[i][1];
           temp->right->left = NULL;
           temp->right->right = NULL;
           q.push(temp->right);
         }
         q.pop();
     }
     return root;
 }
 void inorder(struct Node* root, vector<int>& v)
 {
     if(root)
     {
         inorder(root->left,v);
         v.push_back(root->data);
         inorder(root->right,v);
     }
 }
 void swapNodeAtILevel(Node *root, int level, int k) {
   if (root == NULL || (root->left == NULL && root->right == NULL))
     return;
   if (level% k == 0)
     {
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
     }

   // Recur for left and right subtrees
     swapNodeAtILevel(root->left, level + 1, k);
     swapNodeAtILevel(root->right, level + 1, k);
 }

void swapNode(struct Node* root, int i)
 {
     swapNodeAtILevel(root, 1, i);
 }
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
     struct Node* root = createTree(indexes);
     vector<int> r;
     inorder(root,r);
     indexes.clear();
     for(auto& i: queries)
     {
         swapNode(root, i);
         vector<int> v;
         inorder(root, v);
         indexes.push_back(v);
     }
     
     return indexes;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

