#include <bits/stdc++.h>
using namespace std;
int n;
int p;
vector<int> s;
void solve() {
    cin >> n;
    s.clear();
    for (int i = 1, p; i <= n; i++) {
        cin >> p;
        if (s.empty() || p > s.back())
            s.push_back(p);
        else {
            int top = s.back();
            while (!s.empty() && s.back() > p) s.pop_back();
            s.push_back(top);
        }
    }
    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}