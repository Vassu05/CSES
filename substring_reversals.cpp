#include <bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
class TreapNode {
    public:
    TreapNode *left, *right;
    int prior, size;
    T val;
    bool flip;
    TreapNode(char c) {
        left = right = NULL;
        prior = rng();
        size = 1;
        val = c;
        flip = 0;
    }
};

template<typename T>
class Treap {
    public:
    static int size(TreapNode<T>* treap) {
        return treap ? treap->size : 0;
    }
    static void push(TreapNode<T>* treap) {
        if(treap && treap->flip) {
            swap(treap->left, treap->right);
            if(treap->left) treap->left->flip ^= 1;
            if(treap->right) treap->right->flip ^= 1;
            treap->flip = 0;
        }
    }
    static void split(TreapNode<T>* treap, TreapNode<T>* &left, TreapNode<T>* &right, int k) {
        if(treap == NULL) {
            left = right = NULL;
            return;
        }
        push(treap);
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
    static void merge(TreapNode<T>* &treap, TreapNode<T>* left, TreapNode<T>* right) {
        if(left == NULL) treap = right;
        else if(right == NULL) treap = left;
        else {
            push(left);
            push(right);
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

template<typename T>
ostream &operator<<(ostream &os, TreapNode<T>* node) {
    if(!node) return os;
    Treap<char>::push(node);
    cout << node->left;
    cout << node->val;
    cout << node->right;
    return os;
}

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    TreapNode<char>* root = NULL;
    for(char c : s) {
        Treap<char>::merge(root, root, new TreapNode<char>(c));
    }
    while(m--) {
        int l, r; cin >> l >> r;
        TreapNode<char> *left, *temp, *middle, *right;
        Treap<char>::split(root, left, temp, l - 1);
        Treap<char>::split(temp, middle, right, r - l + 1);
        middle->flip ^= 1;
        Treap<char>::merge(root, left, middle);
        Treap<char>::merge(root, root, right);
    }

    cout << root << '\n';
}
