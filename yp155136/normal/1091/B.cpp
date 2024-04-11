#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int n;
    cin >> n;
    ll totx=0,toty=0;
    for (int i=0;i<n;++i) {
        ll x,y;
        cin >> x >> y;
        totx += x;
        toty += y;
    }
    for (int i=0;i<n;++i) {
        ll x,y;
        cin >> x >> y;
        totx += x;
        toty += y;
    }
    cout << totx/n << ' ' << toty/n << endl;
}