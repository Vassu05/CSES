#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Fenwick {
    public:
    int n;
    vector<T> fen;
    Fenwick(int _n) {
        n = _n;
        fen = vector<T> (n + 1);
    }
    void add(int i, T x) {
        for (++i; i <= n; i += (i & -i)) fen[i] += x;
    }
    T query(int i) {
        T ans = 0;
        for (++i; i > 0; i -= (i & -i)) ans += fen[i];
        return ans;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
};


int main(){
    int n, q; cin >> n >> q;
    vector<int> store;
    vector<int> arr(n);
    for(int &i : arr) { 
        cin >> i;
        store.push_back(i);
    }
    vector<tuple<char,int,int>> queries;
    for(int i = 0; i < q; i++) {
        char c; int a, b;
        cin >> c >> a >> b;
        queries.emplace_back(c, a, b);
        if(c == '!') store.push_back(b);
        else {
            store.push_back(a);
            store.push_back(b);
        }
    }
    sort(store.begin(), store.end());
    store.erase(unique(store.begin(), store.end()), store.end());
    int c = store.size();

    auto getIndex = [&](int x) -> int { return lower_bound(store.begin(), store.end(), x) - store.begin(); };

    Fenwick<int> fen(c);
    for(int i : arr) fen.add(getIndex(i), 1);
    for(auto [ch, a, b] : queries) {
        if(ch == '!') {
            --a;
            fen.add(getIndex(arr[a]), -1);
            arr[a] = b;
            fen.add(getIndex(arr[a]), 1);
        }
        else {
            cout << fen.query(getIndex(a), getIndex(b)) << '\n';
        }
    }
}
