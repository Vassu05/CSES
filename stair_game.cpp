#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // balls on even stairs doesn't matter because if a player moves x balls from even stair to odd stair
        // then player b can move the same x balls from that odd stair to even stair and the state of the game doesn't change
        // 0 indexed
        // so we will just consider balls on odd stair
        // if we move x balls from odd stair even stair (where any number of balls doesn't really matter), it is basically like throwing the balls away
        // so this boils down to standard nim game of picking rocks from a pile
        int x = 0;
        for(int i = 0; i < n; i++) {
            int balls; cin >> balls;
            if(i & 1) x ^= balls;
        }
        cout << (x ? "first" : "second") << '\n';
    }
}
