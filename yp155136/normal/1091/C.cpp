#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ll n;
    cin >> n;
    vector<ll> ans;
    set<ll> st;
    for (ll i=1;i*i<=n;++i) {
        if (n%i==0) {
            st.insert(i);
            st.insert(n/i);
        }
    }
    for (ll i:st) {
        ans.push_back( ((1 + (n+1-i) ) * (n/i) ) / 2);
    }
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}