#include <bits/stdc++.h>
using namespace std;
int pos_x[1024];
int pos_y[1024];
const vector<int> basis_A({1, 4, 16, 64, 256});
const vector<int> basis_B({2, 8, 32, 128, 512});
vector<int> weight_A;
vector<int> weight_B;
void make_weight(int l, int r, int val) {
    int m = (l + r) / 2;
    weight_A[m] = basis_A[val];
    weight_B[m] = basis_B[val];
    if (l == r) return;
    make_weight(l, m - 1, val - 1);
    make_weight(m + 1, r, val - 1);
}
bool done[1 << 20];
void check() {
    int sum = 0;
    int current = 0;
    int px = 0;
    int py = 0;
    done[0] = 1;
    pos_x[0] = ++px;
    pos_y[0] = ++py;
    int temp_current = current;
    for (auto&& y : weight_B) {
        temp_current ^= y;
        pos_x[temp_current] = px;
        pos_y[temp_current] = ++py;
    }
    int mx = 0;
    for (auto&& x : weight_A) {
        sum += x;
        current ^= x;
        pos_x[current] = ++px;
        py = 0;
        pos_y[current] = ++py;
        mx = max(mx, current);
        assert(!done[current]);
        done[current] = 1;
        temp_current = current;
        for (auto&& y : weight_B) {
            temp_current ^= y;
            pos_x[temp_current] = px;
            pos_y[temp_current] = ++py;
            assert(!done[temp_current]);
            done[temp_current] = 1;
            mx = max(mx, temp_current);
        }
        // pos[current] = ++p;
    }
    for (auto&& y : weight_B) sum += y;
    assert(sum * 32 <= 48000);
    // cerr << mx << '\n';
}
void solve() {
    int n, k;
    weight_A.resize(31);
    weight_B.resize(31);
    make_weight(0, 30, 4);
    check();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n; j++) cout << weight_B[j] << " \n"[j + 2 == n];
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < n; j++) cout << weight_A[i] << " \n"[j + 1 == n];
    }
    cout.flush();
    int current_xor = 0;
    int input;
    for (int i = 1; i <= k; i++) {
        cin >> input;
        current_xor ^= input;
        cout << pos_x[current_xor] << ' ' << pos_y[current_xor] << '\n';
        cout.flush();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}