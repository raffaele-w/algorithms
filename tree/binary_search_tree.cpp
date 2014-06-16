// Binary Search Tree

class TreeNode {
public:
    int val;
    TreeNode* p;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value, TreeNode* parent = NULL, TreeNode* left_child = NULL, TreeNode* right_child = NULL) {
        this->val = value;
        this->p = parent;
        this->left = left_child;
        this->right = right_child;
    }
    
    ~TreeNode() {};
};

class BstOp {
public:
    TreeNode* search(TreeNode* x, int key);
    TreeNode* minimum(TreeNode* x);
    TreeNode* maximum(TreeNode* x);
    TreeNode* successor(TreeNode* x);
    TreeNode* predecessor(TreeNode* x);
    TreeNode* insert(TreeNode* root, TreeNode* x);
    TreeNode* transplant(TreeNode* root, TreeNode* u, TreeNode* v);
    TreeNode* del(TreeNode* root, TreeNode* x);
    void recursiveRemove(TreeNode* root);
    
    void print(TreeNode* root);
    int maxLevel(TreeNode* root);
    
private:
    void printHelper(vector<TreeNode*>& nodes, int level, int max_level);
};


TreeNode* BstOp::search(TreeNode* x, int key) {
    while (x && x->val != key) {
        if (key < x->val) x = x->left;
        else x = x->right;
    }
    return x;
}

TreeNode* BstOp::minimum(TreeNode* x) {
    while (x && x->left) {
        x = x->left;
    }
    return x;
}

TreeNode* BstOp::maximum(TreeNode* x) {
    while (x && x->right) {
        x = x->right;
    }
    return x;
}

TreeNode* BstOp::successor(TreeNode* x) {
    if (x == NULL) return NULL;
    if (x->right) return minimum(x->right);
    TreeNode* y = x->p;
    while (y && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}

TreeNode* BstOp::predecessor(TreeNode* x) {
    if (x == NULL) return NULL;
    if (x->left) return maximum(x->left);
    TreeNode* y = x->p;
    while (y && x == y->left) {
        x = y;
        y = y->p;
    }
    return y;
}

TreeNode* BstOp::insert(TreeNode* root, TreeNode* x) {
    if (root == NULL) return x;
    TreeNode* y = NULL;
    TreeNode* z = root;
    while (z) {
        y = z;
        if (x->val < z->val) z = z->left;
        else z = z->right;
    }
    x->p = y;
    if (x->val < y->val) y->left = x;
    else y->right = x;
    
    return root;
}

TreeNode* BstOp::transplant(TreeNode* root, TreeNode* u, TreeNode* v) {
    if (u->p == NULL) {
        v->p = NULL;
        return v;
    }
    
    if (u == u->p->left) u->p->left = v;
    else u->p->right = v;
    
    if (v) v->p = u->p;
    return root;
}

TreeNode* BstOp::del(TreeNode* root, TreeNode* x) {
    if (x == NULL) return root;
    if (x->left == NULL) {
        return transplant(root, x, x->right);
    } else if (x->right == NULL) {
        return transplant(root, x, x->left);
    }
    
    TreeNode* succ = minimum(x->right);
    if (succ != x->right) {
        transplant(root, succ, succ->right);
        succ->right = x->right;
        succ->right->p = succ;
    }
    succ->left = x->left;
    succ->left->p = succ;
    return transplant(root, x, succ);
}

void BstOp::recursiveRemove(TreeNode* root) {
    if (root == NULL) return;
    recursiveRemove(root->left);
    recursiveRemove(root->right);
    delete root;
}

int BstOp::maxLevel(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxLevel(root->left), maxLevel(root->right)) + 1;
}

void BstOp::print(TreeNode* root) {
    vector<TreeNode*> v;
    v.push_back(root);
    printHelper(v, 1, maxLevel(root));
}

void BstOp::printHelper(vector<TreeNode*>& nodes, int level, int max_level) {
    if (nodes.empty()) return;
    bool all_null = true;
    for (TreeNode* t : nodes) {
        if (t) {
            all_null = false;
            break;
        }
    }
    if (all_null) return;
    
    int flr = max_level - level;
    int edge_lines = 2 << max(flr - 1, 0);
    int first_spaces = (2 << flr) - 1;
    int between_spaces = (2 << (flr + 1)) - 1;
    
    cout << string(first_spaces, ' ');
    
    vector<TreeNode*> new_nodes;
    for (auto node : nodes) {
        if (node != NULL) {
            cout << node->val;
            new_nodes.push_back(node->left);
            new_nodes.push_back(node->right);
        } else {
            new_nodes.push_back(NULL);
            new_nodes.push_back(NULL);
            cout << ' ';
        }
        cout << string(between_spaces, ' ');
    }
    cout << endl;
    
    for (int i = 1; i <= edge_lines; i++) {
        for (int j = 0; j < nodes.size(); j++) {
            cout << string(first_spaces - i > 0 ? first_spaces - i : 0, ' ');
            if (nodes[j] == NULL) {
                cout << string(2 * edge_lines + i + 1, ' ');
                continue;
            }
            
            if (nodes[j]->left) cout << '/';
            else cout << ' ';
            
            cout << string(2 * i - 1, ' ');
            
            if (nodes[j]->right) cout << '\\';
            else cout << ' ';
            
            cout << string(2 * edge_lines - i, ' ');
        }
        cout << endl;
    }
    printHelper(new_nodes, level + 1, max_level);
}


// Test functions

void shuffle(vector<int>& v) {
    srand((uint)time(NULL));
    int n = (int)v.size();
    for (int i = 0; i < n; i++) {
        int j = i + rand() % (n - i);
        swap(v[i], v[j]);
    }
}

TreeNode* build(vector<int>& v) {
    BstOp op;
    TreeNode* root = NULL;
    for (int i : v) {
        TreeNode* node = new TreeNode(i);
        root = op.insert(root, node);
    }
    return root;
}

void test() {
    BstOp op;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shuffle(v);
    TreeNode* root = build(v);
    op.print(root);
    
    TreeNode* t = op.search(root, 3);
    root = op.del(root, t);
    delete t;
    cout << "Tree after delete 3:" << endl;
    op.print(root);
    
    cout << "Minimum: " << op.minimum(root)->val << endl;
    cout << "Maximum: " << op.maximum(root)->val << endl;
    
    t = op.search(root, 4);
    TreeNode* pred = op.predecessor(t);
    cout << "Predecessor of 4 is: " << (pred == NULL ? -1 : pred->val) << endl;

    t = op.search(root, 1);
    TreeNode* succ = op.successor(t);
    cout << "Successor of 1 is: " << (succ ? succ->val : -1) << endl;
    
    root = op.del(root, t);
    delete t;
    cout << "Tree after delete 1:" << endl;
    op.print(root);
    
    t = op.search(root, 4);
    root = op.del(root, t);
    delete t;
    cout << "Tree after delete 4:" << endl;
    op.print(root);
    
    op.recursiveRemove(root);
}


int main() {
    test();
    return 0;
}

