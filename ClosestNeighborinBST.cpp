//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->key)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->key)
    {
        insert(&(*tree)->right, val);
    }

}
int mini=INT_MAX;
int findMaxForN(Node* root, int N,int size);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root=NULL;
        int n, k;
        cin>>n;
        mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            insert(&root, k);
        }
        int s;
        cin>>s;
     
       cout<<findMaxForN(root,s,n)<<endl;
         
    }
    return 0;
}// } Driver Code Ends

/*int findMaxForN(Node* root, int N,int size)
{
    //greatest number is find in the right subtree at the last 
    node* greatest=root[N-1];
    //traverse the complete bst in inorder traversal
    node=inorder(node=node->left);
    node->data;
    node=inorder(node-right);
    
    if(node->data>k)
      return -1;
    while(node->data<=N)
        node->data--; to get the one previous value of it
       cout<<node->data;
       
}*/


/*int findMaxForN(Node* root, int N,int size)
{
if(root == NULL) return -1;
else if(root->key == N) return N;
else if(root->key < N){
int right = findMaxForN(root->right, N, size);
if(right == -1) return root->key;
}else{
return findMaxForN(root->left, N, size);
}
}*/

        int findMaxForN(Node* root, int N,int size){
        if(root==NULL) 
          return -1;
        else if(root->key==N) 
           return N;
        else if(root->key<N){
             int right=findMaxForN(root->right,N,size);
        if(right==-1)
         return root->key;
        }
        else{
             return findMaxForN(root->left,N,size);
        }
    }
