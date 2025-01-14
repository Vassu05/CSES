#include <bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class TreapNode {
    public:
    TreapNode *left, *right;
    int prior, size;
    char val;
    TreapNode(char c) {
        left = right = NULL;
        prior = rng();
        size = 1;
        val = c;
    }
};

ostream &operator<<(ostream &os, TreapNode* node) {
    if(!node) return os;
    cout << node->left;
    cout << node->val;
    cout << node->right;
    return os;
}

class Treap {
    public:
    static int size(TreapNode* treap) {
        return treap ? treap->size : 0;
    }
    static void split(TreapNode* treap, TreapNode* &left, TreapNode* &right, int k) {
        if(treap == NULL) {
            left = right = NULL;
            return;
        }
        if(size(treap->left) < k) {
            split(treap->right, treap->right, right, k - size(treap->left) - 1);
            left = treap;
        }
        else {
            split(treap->left, left, treap->left, k);
            right = treap;
        }
        treap->size = 1 + size(treap->left) + size(treap->right);
    }
    static void merge(TreapNode* &treap, TreapNode* left, TreapNode* right) {
        if(left == NULL) treap = right;
        else if(right == NULL) treap = left;
        else {
            if(left->prior < right->prior) {
                merge(left->right, left->right, right);
                treap = left;
            }
            else {
                merge(right->left, left, right->left);
                treap = right;
            }
            treap->size = 1 + size(treap->left) + size(treap->right);
        }
    }
};

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    TreapNode * root = NULL;
    for(char c : s) {
        Treap::merge(root, root, new TreapNode(c));
    }

    while(m--) {
        int l, r; cin >> l >> r;
        TreapNode *left, *temp, *middle, *right;
        Treap::split(root, left, temp, l - 1);
        Treap::split(temp, middle, right, r - l + 1);
        Treap::merge(root, left, right);
        Treap::merge(root, root, middle);
    }

    cout << root << '\n';
}
