//Initial Template for C++
// CPP code to find floor of a key in BST 
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

/* This function is used to insert new values in BST*/
Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 
 // } Driver Code Ends

/*int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
}*/
int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // We found equal key 
    if (root->data == input) 
        return root->data; 
  
    // If root's key is smaller, ceil must be in right subtree 
    if (root->data < input) 
        return findCeil(root->right, input); 
  
    // Else, either left subtree or root has the ceil value 
    int ceil = findCeil(root->left, input); 
    return (ceil >= input) ? ceil : root->data; 
} 

// { Driver Code Starts.

int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << findCeil(root, x) << endl;
	}
	
	return 0; 
}  // } Driver Code Ends