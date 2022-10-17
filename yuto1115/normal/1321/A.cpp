#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> b(n);
    rep(i,n) cin >> r[i];
    rep(i,n) cin >> b[i];
    int ro = 0;
    int rb = 0;
    int bo = 0;
    rep(i,n) {
        if(r[i] == b[i]) rb++;
        else {
            if(r[i] == 1) ro++;
            else bo++;
        }
    }
    if(ro == 0) cout << -1 << endl;
    else if(bo == 0) cout << 1 << endl;
    else {
        cout << bo/ro+1 << endl;
    }
}