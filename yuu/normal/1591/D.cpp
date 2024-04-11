#include <bits/stdc++.h>
using namespace std;
// namespace test {
// constexpr int size = 4;
// set<array<int, size>> total;
// queue<array<int, size>> q;

// int GetInversion(const array<int, size>& a) {
//     int ans = 0;
//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) ans += (a[i] > a[j]);
//     }
//     return ans;
// }

// void Test() {
//     // array<int, size> test_arr({1, 1, 2});
//     array<int, size> test_arr({1, 2, 3, 4});
//     total.insert(test_arr);
//     q.push(test_arr);
//     while (!q.empty()) {
//         auto f = q.front();
//         q.pop();
//         for (int i = 0; i < size; i++) {
//             for (int j = i + 1; j < size; j++) {
//                 for (int k = i + 1; k < size; k++) {
//                     if (j == k) continue;
//                     auto g = f;
//                     g[i] = f[j];
//                     g[j] = f[k];
//                     g[k] = f[i];
//                     if (total.find(g) == total.end()) {
//                         total.insert(g);
//                         q.push(g);
//                     }
//                 }
//             }
//         }
//     }
//     cerr << total.size() << '\n';
//     for (auto&& x : total) {
//         cerr << GetInversion(x) % 2 << ": ";
//         for (int i = 0; i < size; i++) cerr << x[i] << " \n"[i + 1 == size];
//     }
// }
// }  // namespace test

int n;
int ft[500001];
int a[500001];
bool done[500001];

int get(int u) {
    int res = 0;
    for (; u > 0; u -= (u & -u)) res ^= ft[u];
    return res;
}

void update(int u) {
    for (; u <= n; u += (u & -u)) ft[u] ^= 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++)
        if (done[a[i]]) {
            cout << "YES\n";
            return;
        } else {
            done[a[i]] = 1;
        }
    for (int i = 1; i <= n; i++) ft[i] = 0;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        ans ^= get(a[i]);
        update(a[i]);
    }
    if (ans == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // test::Test();
    int t = 1;
    cin >> t;
    while (t--) solve();
}