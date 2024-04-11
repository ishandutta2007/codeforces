#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> beauty(n);
    map<ll,ll> m;
    rep(i,n) {
        cin >> beauty[i];
        m[beauty[i]-i]+=beauty[i];
    }
    ll ans = 0;
    for(auto p : m) {
        ans = max(ans,p.second);
    }
    cout << ans << endl;
}