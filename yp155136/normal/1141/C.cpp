#include <bits/stdc++.h>
using namespace std;

int a[222222];

int main () {
    set<int> st;
    int n; cin >> n;
    int pre=0;
    st.insert(pre);
    int mx=0,mn=0;
    a[1] = pre;
    for (int i=2;i<=n;++i) {
        int x; cin >> x;
        pre += x;
        st.insert(pre);
        mx = max(mx,pre);
        mn = min(mn,pre);
        a[i] = pre;
    }
    if (st.size() != n || mx-mn+1 != n) cout << -1 << endl;
    else {
        for (int i=1;i<=n;++i) {
            cout << a[i] + (1-mn) << ' ';
        }
        cout << endl;
    }
}