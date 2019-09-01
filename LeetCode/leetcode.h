#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

template <class DataType>
void printVector(vector<DataType> v) {
    if (v.empty()) {
        cout << "<empty vector>" << endl;
    } else {
        for (DataType i : v) {
            cout << i << " ";
        }
    }
    cout << endl;
}

template <class DataType>
void printGrid(vector<vector<DataType> > g) {
    for (vector<DataType> &v : g) {
        printVector(v);
    }
}

template <class DataType1, class DataType2>
void printPair(pair<DataType1, DataType2> p) {
    cout << p.first << " " << p.second << endl;
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "" << endl;
    }
    queue<TreeNode*> q;
    string result = "";
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        if (node == nullptr) {
            result = result + "null,";
        } else {
            result = result + string(to_string(node->val)) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        q.pop();
    }
    cout << "[" + result.substr(0, result.size() - 1) + "]" << endl;
}

void printAryTree(Node* root) {
    if (root == nullptr) {
        cout << "" << endl;
    }
    queue<Node*> q;
    string result = "";
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        if (node == nullptr) {
            result = result + "null,";
        } else {
            result = result + string(to_string(node->val)) + ",";
            for(int i = 0; i < node->children.size(); i++) {
                q.push((node->children)[i]);
            }        
        }
        q.pop();
    }
    cout << "[" + result.substr(0, result.size() - 1) + "]" << endl;
}

int readNumber() {
    int result;
    cin >> result;
    return result;
}

string readString() {
    string str;
    cin >> str;
    return str; 
}

/**
 * Add cin.ignore() if there is cin >> YOUR_VAR before readStringLine()
*/
string readStringLine() {
    string str;
    getline(cin, str);
    return str;
}

char readChar() {
    char c;
    cin >> c;
    return c;
}

vector<int> readVector(int size) {
    vector<int> result;
    for (int i = 1; i <= size; ++i) {
        int temp;
        cin >> temp;
        result.push_back(temp);
    }
    return result;
}

vector<char> readCharVector(int size) {
    vector<char> result;
    for (int i = 1; i <= size; ++i) {
        char temp;
        cin >> temp;
        result.push_back(temp);
    }
    return result;
}

vector<string> readStringVector(int size) {
    vector<string> result;
    for (int i = 1; i <= size; ++i) {
        string temp = readString();
        result.push_back(temp);
    }
    return result;
}

vector<vector<int> > readGrid(int m, int n) {
    vector<vector<int> > result;
    for (int i = 1; i <= m; ++i) {
        result.push_back(readVector(n));
    }
    return result;
}

vector<vector<char> > readCharGrid(int m, int n) {
    vector<vector<char> > result;
    for (int i = 1; i <= m; ++i) {
        result.push_back(readCharVector(n));
    }
    return result;
}

ListNode* readLinkedList(int n) {
    ListNode* head = new ListNode(-1);
    cin >> head->val;
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(-1);
        current = current->next;
        cin >> current->val;
    }
    return head;
}

vector<string> split(string s, string d) {
    vector<string> values;
    int index = 0;
    while (s.find(d, index) != string::npos) {
        values.push_back(s.substr(index, s.find(d, index) - index));
        index = s.find(d, index) + 1;
    }
    values.push_back(s.substr(index, s.size() - index));
    return values;
}

TreeNode* readBinaryTree() {
    string line = "";
    cin >> line;
    line = line.substr(1, line.size() - 2);
    if (line == "") {
        return nullptr;
    }
    queue<TreeNode*> q;
    vector<string> values = split(line, ",");
    TreeNode* root = new TreeNode(stoi(values[0]));
    q.push(root);
    for (int i = 1; i < values.size(); i++) {
        TreeNode* parent = q.front();
        if (values[i] != "null" && parent != nullptr) {
            parent->left = new TreeNode(stoi(values[i]));
            q.push(parent->left);
        }
        if (i + 1 < values.size()) {
            if (values[++i] != "null" && parent != nullptr) {
                parent->right = new TreeNode(stoi(values[i]));
                q.push(parent->right);
            }
        }
        q.pop();
    }
    return root;
}

Node* readAryTree(int k_ary) {
    string line = "";
    cin >> line;
    line = line.substr(1, line.size() - 2);
    if (line == "") {
        return nullptr;
    }
    queue<Node*> q;
    vector<string> values = split(line, ",");
    Node* root = new Node(stoi(values[0]), {});
    q.push(root);
    for (int i = 1; i < values.size(); i++) {
        Node* parent = q.front();
        for (int j = 0; j < k_ary; j++) {
            if (values[i + j] == "") {
                q.push((parent->children)[j]);
                return root;
            }
            if (values[i + j] != "null" && parent != nullptr) {
                parent->children.push_back(new Node(stoi(values[i + j]), {}));               
            }
            q.push((parent->children)[j]);
            if (j == k_ary - 1) {
                i = i + j;
                break;
            }   
        }
        q.pop();      
    }
    return root;
}
