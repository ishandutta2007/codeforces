#include <bits/stdc++.h>
using namespace std;
int n, k[501];
deque<int> order;
void guess(int a, int b) {
    cout << "! " << a << ' ' << b << '\n';
    cout.flush();
    exit(0);
}
bool ask(int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    string s;
    cin >> s;
    return s == "Yes";
}

vector<tuple<int, int, int>> askes;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        k[i] = n - 1 - k[i];
    }
    for (int i = 1; i <= n; i++) order.push_back(i);
    sort(order.begin(), order.end(), [](const int &a, const int &b) { return k[a] < k[b]; });
    while (!order.empty()) {
        if (k[order.front()] == 0) {
            for (auto &&x : order) k[x]--;
            order.pop_front();
        } else if (k[order.back()] + 1 == order.size()) {
            order.pop_back();
        } else {
            break;
        }
    }
    if (order.empty()) guess(0, 0);
    assert(order.size() >= 2);
    for (int i = 0; i < order.size(); i++)
        for (int j = i + 1; j < order.size(); j++) askes.emplace_back(k[order[j]] - k[order[i]], order[i], order[j]);
    sort(askes.begin(), askes.end());
    reverse(askes.begin(), askes.end());
    for (auto &&[ans, x, y] : askes)
        if (ask(x, y)) guess(x, y);
    guess(0, 0);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}