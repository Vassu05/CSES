#include <bits/stdc++.h>
using namespace std;

#define int long long

class Node {
    public:
    int sum;
    int l, r;
    Node* left, *right;
    Node() {
        sum = 0;
        l = r = 0;
        left = right = NULL;
    }
    Node(int l, int r, int x) {
        this->l = l, this->r = r;
        sum = x;
        left = right = NULL;
    }
    Node(Node *x, Node *y) {
        this->left = x, this->right = y;
        this->sum = 0;
        if(x) {
            sum += x->sum;
            this->l = x->l;
        }
        if(y) {
            sum += y->sum;
            this->r = y->r;
        }
    }
};


const int N = 2e5 + 118;
Node* seg[N];

int32_t main(){
    int n, q; cin >> n >> q;
    int now = 1;
    // every update will produce logN number of new nodes
    auto update = [&](auto self, Node* x, int l, int r, int idx, int val) -> Node* {
        if (l == r) {
            return new Node(l, r, val);
        }
        if(!x) x = new Node(l, r, 0);
        int mid = (l + r) / 2;
        Node*left = x->left, *right = x->right;
        if(idx <= mid) left = self(self, x->left, l, mid, idx, val);
        else right = self(self, x->right, mid + 1, r, idx, val);
        return new Node(left, right);
    };

    auto query = [&](auto self, Node *x, int l, int r, int ll, int rr) -> int {
        if(l > rr || l > r || r < ll) return 0LL;
        if(l >= ll && r <= rr) return x->sum;
        int mid = (l + r) / 2;
        return self(self, x->left, l, mid, ll, rr) + self(self, x->right, mid + 1, r, ll, rr);
    };

    vector<int> a(n);
    for(int &i : a) cin >> i;
    for(int i = 0; i < n; i++) {
        seg[now] = update(update, seg[now], 0, n - 1, i, a[i]);
    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int k, idx, x; cin >> k >> idx >> x;
            --idx;
            seg[k] = update(update, seg[k], 0, n - 1, idx, x);
        }
        else if(op == 2) {
            int k, l, r; cin >> k >> l >> r;
            --l, --r;
            cout << query(query, seg[k], 0, n - 1, l, r) << '\n';
        }
        else {
            int k; cin >> k;
            seg[++now] = seg[k];
            // array number now has the same pointers as array k
        }
    }
}
