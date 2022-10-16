#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
multiset<int> s;
vector<int> t;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        while ((!s.empty()) && (a[i - 1] == *s.begin())) {
            t.push_back(*s.begin());
            s.erase(s.begin());
        }
        if (s.empty()) {
            a[i] = t.back();
            t.pop_back();
        } else {
            a[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}