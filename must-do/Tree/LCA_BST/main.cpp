#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<deque>


//{ Driver Code Starts
using namespace std;

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

Node* LCA(Node * root , int l , int h);

int main()
{
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}
// } Driver Code Ends

Node* _LCA(Node *root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (n1 <= root->data && n2 >= root->data)
        return root;
    else if (n2 <= root->data)
        return _LCA(root->left, n1, n2);
    else if (n1 >= root->data)
        return _LCA(root->right, n1, n2);
    // should not reach here
    return NULL;
}

//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2) {
    if (root == NULL)
        return NULL;
   //Your code here
   int lowerN = min(n1, n2);
   int higherN = max(n1, n2);

   return _LCA(root, lowerN, higherN);
}