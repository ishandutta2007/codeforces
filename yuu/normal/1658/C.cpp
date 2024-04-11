#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> c;
deque<int> pos[100002];
bool solve(int l, int r, int expect) {
    if (c[r] != expect) return false;
    if (l == r) return true;
    int low = l;
    while (!pos[expect + 1].empty() && pos[expect + 1].front() <= r) {
        if (!solve(low, pos[expect + 1].front(), expect + 1)) return false;
        low = pos[expect + 1].front() + 1;
        pos[expect + 1].pop_front();
    }
    return low == r;
}
void solve() {
    cin >> n;
    c.clear();
    for (int i = 1, temp; i <= n; i++) {
        cin >> temp;
        c.push_front(temp);
    }
    for (int i = 1; i <= n; i++) pos[i].clear();
    if (*min_element(c.begin(), c.end()) != 1) {
        cout << "No\n";
        return;
    }
    while (c.back() != 1) {
        c.push_front(c.back());
        c.pop_back();
    }
    for (int i = 0; i < n; i++) pos[c[i]].push_back(i);
    if (pos[1].size() != 1) {
        cout << "No\n";
        return;
    }
    if (solve(0, n - 1, 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}