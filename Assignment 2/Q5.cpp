
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Cmp {
    bool operator()(const Node *a, const Node *b) const {
        return a->freq > b->freq;
    }
};

static void buildCodes(Node *root, string code, map<char, string> &out) {
    if (!root) return;
    if (!root->left && !root->right) {
        out[root->ch] = code.empty() ? "0" : code;
        return;
    }
    buildCodes(root->left, code + "0", out);
    buildCodes(root->right, code + "1", out);
}

static void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    cout << "Enter number of characters, then characters, then frequencies:\n";
    int N;
    if (!(cin >> N)) {
        return 0;
    }

    vector<char> chars(N);
    vector<int> freqs(N);

    cout << "Enter " << N << " characters:\n";
    for (int i = 0; i < N; ++i) {
        cin >> chars[i];
    }

    cout << "Enter " << N << " frequencies:\n";
    for (int i = 0; i < N; ++i) {
        cin >> freqs[i];
    }

    priority_queue<Node *, vector<Node *>, Cmp> pq;
    for (int i = 0; i < N; ++i) {
        pq.push(new Node(chars[i], freqs[i]));
    }

    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node *root = pq.top();
    map<char, string> codes;
    buildCodes(root, "", codes);

    cout << "Character   Huffman Code\n";
    for (int i = 0; i < N; ++i) {
        cout << chars[i] << "\t\t" << codes[chars[i]] << "\n";
    }

    freeTree(root);
    return 0;
}
