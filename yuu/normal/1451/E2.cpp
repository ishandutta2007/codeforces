#include <bits/stdc++.h>
using namespace std;
int ask(const string& op, int i, int j) {
    cout << op << ' ' << i << ' ' << j << '\n';
    cout.flush();
    cin >> i;
    return i;
}
int n;
int xor_1[(1 << 16) + 1];
int a[(1 << 16) + 1];
map<int, vector<int>> result;
void solve() {
    cin >> n;
    xor_1[0] = 0;
    for (int i = 2; i <= n; i++) {
        xor_1[i] = ask("XOR", 1, i);
        result[xor_1[i]].push_back(i);
    }
    if (result[0].size()) {
        int j = result[0][0];
        a[1] = ask("AND", 1, j);
    } else {
        for (auto&& [val, items] : result) {
            if (items.size() > 1) {
                int x = items[0];
                int y = items[1];
                a[x] = ask("AND", x, y);
                a[1] = a[x] ^ xor_1[x];
                goto finalise;
            }
        }

        // every element is different
        auto& XOR_1 = result[1];
        auto& XOR_2 = result[2];
        assert(XOR_1.size());
        assert(XOR_2.size());
        int and_1 = ask("AND", 1, XOR_1[0]);
        int and_2 = ask("AND", 1, XOR_2[0]);
        a[1] = and_1 | and_2;
    }
finalise:;
    for (int i = 2; i <= n; i++) a[i] = a[1] ^ xor_1[i];
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    cout.flush();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}