#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *root,int data)
{
    if(root==NULL)
       root=new Node(data);
    else if(data<root->data)
        root->left=insert(root->left,data);
    else
       root->right=insert(root->right,data);
    
    return root;
}

 // } Driver Code Ends
int getCountOfNode(Node *root, int l, int h)
{ 
    if(!root)
      return 0;
   if(root->data==l && root->data==h)
     return 1;
    if(root->data>=l && root->data<=h)
     return 1+getCountOfNode(root->left,l,h)+ getCountOfNode(root->right,l,h);
    else if(root->data<l)
       return getCountOfNode(root->right,l,h);
     else
    return getCountOfNode(root->left,l,h);
    }

// { Driver Code Starts.
int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        cout<<getCountOfNode(root,l,h)<<endl;       
    }
	return 0;
}  // } Driver Code Ends