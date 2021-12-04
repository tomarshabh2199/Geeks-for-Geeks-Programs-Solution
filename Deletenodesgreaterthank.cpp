#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node * deleteNode(Node *, int);

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val >= (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        
        int s;
        cin>>s;
        
    Node *R= deleteNode(root,s);
    	inorder(R);
      cout<<endl;
    }
}

// } Driver Code Ends

//search for all the nodes in the bst whose node values are >=k
//then delete the node free node and return the root of the modified bst 


/*Node* deleteNode(Node* root, int key)
{
    if(root==NULL)
       return NULL;
     //  while(k valuue nodes are deleted in the bst)
    for(int i=0;i<N;i++)
    {
        for(int i=0;i<k;i++)
         delete node(root->data>=k);
         free(node);
         //print modified bst
         for(int i=0;i<n-k;i++)
           root=root->data;
    }
}*/
//stack based solution
/*Node* deleteNode(Node* root, int key)
{
    stack<Node*>s;
    s.push(root);
    while(!s.empty()&&s.size()<k)
    Node *temp=NULL;
    temp=root->data[i];
    if(temp->data>k)
      s.top();
      s.pop();
 for(int i=0;i<n-k;i++)
   s.push(root->data);
return 0;
}*/
Node* buildTree(Node* root,int key)
{
    if(root==NULL)
       return NULL;
    if(root->data==key){
        return root->left;
    }
    else if(root->data>key)
        return buildTree(root->left,key);
    else {
      root->right=buildTree(root->right,key);
         return root;
    }
}
Node* deleteNode(Node* root,int key){
    root=buildTree(root,key);
    return root;
}















