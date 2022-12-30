//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<deque>
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

vector<int> findSpiral(Node *root);

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
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> resultList;
    if (root == NULL)
        return resultList;
    
    int DELIMITER_DATA = -1;
    Node* DELIMITER_NODE = new Node;
    DELIMITER_NODE->data = DELIMITER_DATA;

    int RIGHT = 1;
    int LEFT = -1;
    int removeDirection = LEFT;
    // insertDirection is always reverse of removeDirection throughout this method
    
    deque<Node*> traversalDeque;
    // removeDirection = LEFT
    traversalDeque.push_back(root);
    resultList.push_back(root->data);
    traversalDeque.push_back(DELIMITER_NODE);

    while(!traversalDeque.empty()) {
        Node *frontNode = traversalDeque.front();
        Node *backNode = traversalDeque.back();
        
        if (frontNode->data == DELIMITER_DATA && backNode->data == DELIMITER_DATA) {
            // DELIMITER is the only element left in the queue
            // pop_back() or pop_front() doesn't matter here
            traversalDeque.pop_back();
        } else if (removeDirection == LEFT) {
            if (frontNode->data == DELIMITER_DATA) {
                removeDirection = RIGHT;
            } else {
                traversalDeque.pop_front();
                if (frontNode->left != NULL) {
                    traversalDeque.push_back(frontNode->left);
                    resultList.push_back(frontNode->left->data);
                }
                if (frontNode->right != NULL) {
                    traversalDeque.push_back(frontNode->right);
                    resultList.push_back(frontNode->right->data);
                }
            }
        } else if (removeDirection == RIGHT) {
            if (backNode->data == DELIMITER_DATA) {
                removeDirection = LEFT;
            } else {
                traversalDeque.pop_back();
                if (backNode->right != NULL) {
                    traversalDeque.push_front(backNode->right);
                    resultList.push_back(backNode->right->data);
                }
                if (backNode->left != NULL) {
                    traversalDeque.push_front(backNode->left);
                    resultList.push_back(backNode->left->data);
                }
            }
        }
    }

    return resultList;
}
