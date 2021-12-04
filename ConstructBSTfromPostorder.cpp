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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends

/*Node* constructTreeutil(int post[],int n)
{
    Node* root=new Node(post[n-1]);
    stack<Node*>s;
    s.push(root);
    for(int i=n-2;i>=0;--i)
    {
     Node* x=new Node(post[i]);
     Node* temp=NULL;
     while(s.size() && post[i]<s.top()->data)
      temp=s.top();
     s.pop();
     if(temp!=NULL)
      temp->left=x;
      else
         s.top()->right=x;
      s.push(x);
    
}
return root;
}
Node* constructTree(int post[],int size)
{
 return constructTreeutil(post,size);
}*/
Node* constructTreeUtil(int post[], int n) 
{ 
    // Last node is root 
    Node* root = new Node(post[n - 1]); 
    stack<Node*> s; 
    s.push(root); 
  
    // Traverse from second last node 
    for (int i = n - 2; i >= 0; --i) 
    { 
        Node* x = new Node(post[i]); 
  
        // Keep popping nodes while top()  
        // of stack is greater. 
        Node* temp = NULL; 
        while (s.size() &&  
               post[i] < s.top()->data)  
            temp = s.top(), s.pop();      
  
        // Make x as left child of temp  
        if (temp != NULL)  
            temp->left = x;      
  
        // Else make x as right of top      
        else
            s.top()->right = x; 
        s.push(x); 
    } 
    return root; 
} 
  
// Function that calls the method 
// which contructs the tree 
Node* constructTree(int post[], int size) 
{ 
    return constructTreeUtil(post, size); 
} 