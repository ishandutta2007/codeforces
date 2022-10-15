#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<array<int, 2>> E;
        vector<int> st;
        for (int i = n - 2; ~i; i--) {
            st.push_back(i);
            for (int j = i + 1; j < n; j++) if (s[i][j - i] == '1') {
                E.push_back({i, j}), st.pop_back();
                if (!st.empty() && st.back() < j) {
                    E.push_back({st.back(), j}), st.pop_back();
                    for (; !st.empty() && st.back() < j; st.pop_back()) {
                        E.push_back({i, st.back()});
                    }
                }
                if (st.empty()) break;
                j = max(j, st.back());
            }
        }
        for (auto &e : E) {
            cout << e[0] + 1 << " " << e[1] + 1 << "\n";
        }
    }
    return 0;
}