#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v.push_back(x);
        }
        set<int> st;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                st.insert(abs(v[i] - v[j]));
            }
        }
        cout << (int)st.size() - 1 << endl;
    }
}