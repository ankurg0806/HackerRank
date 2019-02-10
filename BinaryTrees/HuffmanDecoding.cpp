/* For Problem https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
 *
 *
*/

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    node* temp = root;
    for(char c: s)
    {
        if(c=='0')
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        if(temp->left == NULL && temp->right == NULL)
        {
            cout<<temp->data;
            temp = root;
        }
    }
}
