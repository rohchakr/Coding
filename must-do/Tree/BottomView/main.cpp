//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>

using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

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


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> resultList;
        unordered_map<int, int> resultMap;
        queue<pair<int, Node*> > traversalQueue;
        int leftmostPos = 0, rightmostPos = 0;

        if (root != NULL) {
            traversalQueue.push(make_pair(0, root));
        }

        while(!traversalQueue.empty()) {
            pair<int, Node*> poppedObject = traversalQueue.front();
            traversalQueue.pop();

            // update resultMap
            if (resultMap.find(poppedObject.first) != resultMap.end())
                resultMap.erase(poppedObject.first);

            resultMap.insert(make_pair(poppedObject.first, poppedObject.second->data));

            // update leftmostPos
            if (poppedObject.first < leftmostPos)
                leftmostPos = poppedObject.first;
            
            // update rightmostPos
            if (poppedObject.first > rightmostPos)
                rightmostPos = poppedObject.first;
            
            if (poppedObject.second->left != NULL)
                traversalQueue.push(make_pair(poppedObject.first - 1, poppedObject.second->left));

            if (poppedObject.second->right != NULL)
                traversalQueue.push(make_pair(poppedObject.first + 1, poppedObject.second->right));
        }

        for (int i = leftmostPos; i <= rightmostPos; i++)
            resultList.push_back(resultMap.at(i));

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
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends