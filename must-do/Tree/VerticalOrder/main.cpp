//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
          
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> resultList;
        if (root == NULL)
            return resultList;

        queue<pair<int, Node*> > orderQueue;
        unordered_map<int, vector<int> > resultMap;
        int smallestHorPos = 0, largestHorPos = 0;
        
        orderQueue.push(make_pair(0, root));

        while(!orderQueue.empty()) {
            pair<int, Node*> poppedObject = orderQueue.front();
            orderQueue.pop();
            
            if (poppedObject.first < smallestHorPos)
                smallestHorPos = poppedObject.first;

            if (poppedObject.first > largestHorPos)
                largestHorPos = poppedObject.first;

            if (resultMap.find(poppedObject.first) == resultMap.end()) {
                vector<int> nodeList;
                nodeList.push_back(poppedObject.second->data);
                resultMap.insert(make_pair(poppedObject.first, nodeList));
            } else {
                resultMap.at(poppedObject.first).push_back(poppedObject.second->data);
            }

            if (poppedObject.second->left != NULL)
                orderQueue.push(make_pair(poppedObject.first - 1, poppedObject.second->left));
            
            if (poppedObject.second->right != NULL)
                orderQueue.push(make_pair(poppedObject.first + 1, poppedObject.second->right));
        }

        for (int i = smallestHorPos; i <= largestHorPos; i++) {
            vector<int> elementList = resultMap.at(i);
            for (int j : elementList)
                resultList.push_back(j);
        }

        return resultList;
    }
};



//{ Driver Code Starts.
int main() {
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends