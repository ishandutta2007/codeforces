#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m; cin >> n >> m;
    if (m%n != 0) cout << -1 << endl;
    else {
        int del = m/n;
        int ans=0;
        while (del%2==0) {
            del/=2;
            ans++;
        }
        while (del%3==0) {
            del/=3;
            ++ans;
        }
        if (del==1) cout << ans << endl;
        else cout << -1 << endl;
    }
}