// Declaration
class SuffixNode {
public:
    SuffixNode(char c);
    void insert(string s, int index);
    vector<int> search(string s);
    
private:
    char m_c;
    vector<int> m_indices;
    unordered_map<char, SuffixNode*> m_children;
};

class SuffixTree {
public:
    SuffixTree(string s);
    vector<int> search(string s);
    
private:
    SuffixNode* m_root;
};


// SuffixNode implementation
SuffixNode::SuffixNode(char c) {
    m_c = c;
}

void SuffixNode::insert(string s, int index) {
    m_indices.push_back(index);
    if (s.length() == 0) return;
    if (m_children.count(s[0]) <= 0) {
        SuffixNode* node = new SuffixNode(s[0]);
        m_children[s[0]] = node;
    }
    m_children[s[0]]->insert(s.substr(1), index);
}

vector<int> SuffixNode::search(string s) {
    if (s.length() == 0) {
        return m_indices;
    }
    if (m_children.count(s[0]) > 0) {
        return m_children[s[0]]->search(s.substr(1));
    }
    return vector<int>();
}

// SuffixTree implementation
SuffixTree::SuffixTree(string s) {
    m_root = new SuffixNode('\0');
    for (int i = 0; i < s.length(); i++) {
        m_root->insert(s.substr(i), i);;
    }
}

vector<int> SuffixTree::search(string s) {
    return m_root->search(s);
}

