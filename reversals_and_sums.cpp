#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
class TreapNode {
    public:
    TreapNode *left, *right;
    int prior, size;
    T val;
    long long sum;
    bool flip;
    TreapNode(T c) {
        left = right = NULL;
        prior = rng();
        size = 1;
        val = c;
        sum = c;
        flip = 0;
    }
};

template<typename T>
class Treap {
    public:
    static int size(TreapNode<T>* treap) {
        return treap ? treap->size : 0;
    }
    static long long sum(TreapNode<T>* treap) {
        return treap ? treap->sum : 0;
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
        treap->sum = treap->val + sum(treap->left) + sum(treap->right);
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
            treap->sum = treap->val + sum(treap->left) + sum(treap->right);
        }
    }
};

template<typename T>
ostream &operator<<(ostream &os, TreapNode<T>* node) {
    if(!node) return os;
    Treap<T>::push(node);
    cout << node->left;
    cout << node->val;
    cout << node->right;
    return os;
}

int main(){
    int n, m; cin >> n >> m;
    TreapNode<int> * root = NULL;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        Treap<int>::merge(root, root, new TreapNode(x));
    }

    while(m--) {
        int op, l, r; cin >> op >> l >> r;
        TreapNode<int> *left, *temp, *middle, *right;
        Treap<int>::split(root, left, temp, l - 1);
        Treap<int>::split(temp, middle, right, r - l + 1);
        if(op == 1) middle->flip ^= 1;
        else cout << middle->sum << '\n';
        Treap<int>::merge(root, left, middle);
        Treap<int>::merge(root, root, right);
    }
}
