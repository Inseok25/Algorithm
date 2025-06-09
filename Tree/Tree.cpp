#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node
{
    Node() {};
    Node(const string& data) : data(data) {};
    string          data;
    vector<NodeRef> child;
};

NodeRef CreateTree()
{
    NodeRef root = make_shared<Node>("R1 개발실");
    {
        NodeRef node = make_shared<Node>("디자인팀");
        root->child.push_back(node);
        {
            NodeRef leaf = make_shared<Node>("전투");
            node->child.push_back(leaf);
        }
        {
            NodeRef leaf = make_shared<Node>("경제");
            node->child.push_back(leaf);
        }
        {
            NodeRef leaf = make_shared<Node>("스토리");
            node->child.push_back(leaf);
        }
    }

    return root;
}

void PrintTree(NodeRef root,int depth)
{
    for (int i = 0; i < depth; i++)
    {   
        cout << "-";
    }
    cout << root->data << endl;

    for (NodeRef& child : root->child)
        PrintTree(child, depth+1);
}

int GetHeight(NodeRef root)
{
    int height = 1;

    for (NodeRef& child : root->child)
        height = max(height, GetHeight(child) + 1);

    return height;
}
int main()
{
    NodeRef root = CreateTree();

    PrintTree(root, 0);

    cout << GetHeight(root) << endl;
}
