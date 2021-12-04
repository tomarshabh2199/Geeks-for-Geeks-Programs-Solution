#include <bits/stdc++.h>
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

int kthLargest(Node *root, int k);

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        cout << kthLargest( head, k ) << endl;
    }
    return 1;
}// } Driver Code Ends

/*int kthLargest(Node *root, int K)
{
    
}*/
// A function to find k'th largest element in a given tree. 
/*void kthLargestUtil(Node *root, int k, int &c) 
{ 
    // Base cases, the second condition is important to 
    // avoid unnecessary recursive calls 
    if (root == NULL || c >= k) 
        return; 
  
    // Follow reverse inorder traversal so that the 
    // largest element is visited first 
    kthLargestUtil(root->right, k, c); 
  
    // Increment count of visited nodes 
   // c++; 
  
    // If c becomes k now, then this is the k'th largest  
    if (++c == k) 
    { 
        cout << root->data<<endl;; 
        //return (root->data) ; 
    } 
  
    // Recur for left subtree 
    kthLargestUtil(root->left, k, c); 
} 
  
// Function to find k'th largest element 
int kthLargest(Node *root, int k) 
{ 
    // Initialize count of nodes visited as 0 
    int c = 0; 
  
    // Note that c is passed by reference 
    kthLargestUtil(root, k, c); 
} */

    void preorder(Node* root,priority_queue <int,vector<int>,greater<int>> &pq,int k)
    {
        if(!root)
        return ;
        pq.push(root->data);

        if(pq.size()>k)
        {
        pq.pop();
        }

        preorder(root->left,pq,k);
        preorder(root->right,pq,k);
    }
        int kthLargest(Node *root, int K)
        {
        priority_queue<int,vector<int>,greater<int>>pq;
        preorder(root,pq,K);

        if(K>pq.size())
            return -1;

        return pq.top();
        }