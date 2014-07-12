class Node {
public:
    int seq;
    bool visited;
    vector<Node*> adj;
    
    Node(int s, vector<Node*> v) {
        seq = s;
        visited = false;
        adj = v;
    }
};

void dfs(Node* root, list<Node*>& res);

// Performed on Directed Acyclic Graph (DAG)
list<Node*> topological_sort(vector<Node*>& graph) {
    list<Node*> res;
    for (auto t : graph) {
        dfs(t, res);
    }
    return res;
}

void dfs(Node* root, list<Node*>& res) {
    if (root == NULL || root->visited) return;
    root->visited = true;
    for (auto t : root->adj) {
        dfs(t, res);
    }
    res.push_front(root);
}


