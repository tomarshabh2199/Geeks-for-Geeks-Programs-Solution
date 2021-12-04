//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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

bool isBST(Node* n, int lower, int upper)
{
    if(!n) return true;
    if( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int,int>> &mismatch )
{
    if( !a && !b ) return true;
    if( !a || !b ) return false;
    
    if( a->data != b->data )
        mismatch.push_back( pair<int,int> (a->data,b->data) );
    
    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}

struct Node *correctBST( struct Node* root );

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        
        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);
        
        root = correctBST(root);
        
        // check 1: is tree now a BST
        if( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout<< "0\n";
            continue;
        }
        
        // check 2: comparing with duplicate tree
        
        vector<pair<int,int>> mismatch;
        // a vector to store data of mismatching nodes
        
        if( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout<< "0\n";
            continue;
        }
        
        // finally, analysing the mismatching nodes
        if( mismatch.size() !=2 || mismatch[0].first!=mismatch[1].second || mismatch[0].second!=mismatch[1].first )
            cout<<"0\n";
        else cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*struct Node *correctBST( struct Node* root )
{
    if(root==NULL)
      return NULL;
    //CHECK FOR BST
    bool isbst(Node* root,int min,int max){
        if(root->data<min ||root->data>max)
          return false;
    return (isbst(root->left,INT_MIN,root->data-1)
         && isbst(root->right,root->data+1,INT_MAX));
    }
    else{
        int swap(Node* root,Node* &a,Node* &b)
        Node*temp=NULL;
          if()
          *a=*b
          *b=temp;
          temp=*a
    }
}*/
void insertionsort(vector<int>&v,int n){
    int i,j,key;
    for(int i=1;i<n;i++){
        key=v[i];
        j=i-1;
    while(j>=0&&v[j]>key){
        v[j+1]=v[j];
        j=j-1;
    }
    v[j+1]=key;
    }
}
void inorder(Node* root, vector<int>& v) 
{ 
    // Base cases 
    if (!root) 
        return; 
   
    // Recurive call for left subtree 
    inorder(root->left, v); 
   
    // Insert node into vector 
    v.push_back(root->data); 
   
    // Recursive call for right subtree 
    inorder(root->right, v); 
} 

void find(Node* root,int res,int res2){
    if(!root)
     return;
     find(root->left,res,res2);
      if(root->data==res){
        root->data=res2;}
     else if(root->data==res2){
         root->data=res;}
    find(root->right,res,res2);
}



    struct Node *correctBST( struct Node* root )
    {
        vector<int>v;
        inorder(root,v);
        vector<int>v1=v;
        insertionsort(v,v.size());
        for(int i=0;i<v.size();i++){
        if(v[i]!=v1[i]){
            find(root,v1[i],v[i]);
            break;
    }
}
    return root;
}
