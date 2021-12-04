#include <bits/stdc++.h>
#define MAX_HEIGHT 100000
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }
   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    cout << isBST(root) << endl;
   }
   return 0;
}

 // } Driver Code Ends
/*bool isBST(Node* root) {
   while(!root)
     right=inorder(root->right);
      root=root->data;
     left=inordder(root->right);
     //min values lies in the left subtree
     //max value lies in th right subtree
     //not skewed and each node values are distinict and unique
     
}*/

bool isBSTUtil(struct Node* root, int& prev) 
{ 
    // traverse the tree in inorder fashion and 
    // keep track of prev node 
    if (root) { 
        if (!isBSTUtil(root->left, prev)) 
            return false; 
  
        // Allows only distinct valued nodes 
        if (root->data <= prev) 
            return false; 
  
        // Initialize prev to current 
        prev = root->data; 
  
        return isBSTUtil(root->right, prev); 
    } 
  
    return true; 
} 
// Function to check if Binary Tree is BST 
bool isBST(Node* root) 
{ 
    int prev = INT_MIN; 
    return isBSTUtil(root, prev); 
} 

// { Driver Code Starts
  // } Driver Code Ends