#include <bits/stdc++.h>
using namespace std;
map<tuple<int, int, int>, int> trans_map;
int permu_length;
constexpr int search_until = 15;
int p[search_until + 1];
int mx[search_until + 1];
bool done[search_until + 1];
vector<tuple<int, int, int, int>> trans;
void backtrack(int pos, int add_k, int add_x) {
    if (add_k > 11) return;
    if (pos > permu_length) {  // done
        assert(add_k);
        assert(add_x);
        trans_map[{permu_length, add_k, add_x}]++;
        return;
    }
    if ((pos > 1) && (mx[pos - 1] == pos - 1)) {  // reducible
        return;
    }
    for (int i = 1, skipped = 0; i <= permu_length; i++)
        if (!done[i]) {
            done[i] = 1;
            p[pos] = i;
            mx[pos] = max(mx[pos - 1], i);
            backtrack(pos + 1, add_k + skipped, add_x + ((pos > 1) && (i < p[pos - 1])));
            done[i] = 0;
            skipped++;
        }
}

constexpr int base = 998'244'353;
constexpr int used_highest = 11;
constexpr int total_highest = 22;
int64_t f[used_highest + 1][total_highest + 1][12][12];
int64_t power(int64_t x, int64_t a) {
    int64_t res = 1;
    while (a) {
        if (a % 2) (res *= x) %= base;
        (x *= x) %= base;
        a /= 2;
    }
    return res;
}
int64_t inverse[51 + 1];
void prepare() {
    for (permu_length = 2; permu_length <= search_until; permu_length++) {
        backtrack(1, 0, 0);
    }
    for (auto&& [abc, d] : trans_map) {
        auto&& [a, b, c] = abc;
        trans.emplace_back(a, b, c, d);
        // cerr << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
    f[0][0][0][0] = 1;
    int actual_highest = 0;
    for (int h = 0; h <= used_highest; h++)
        for (int i = 0; i <= total_highest; i++)
            for (int j = 0; j <= 11; j++)
                for (int k = 0; k <= 11; k++)
                    if (f[h][i][j][k]) {
                        actual_highest = i;
                        for (auto&& [a, b, c, d] : trans) {
                            if (b + j > 11) continue;
                            if (c + k > 11) continue;
                            (f[h + 1][i + a][j + b][k + c] += (f[h][i][j][k] * d)) %= base;
                        }
                    }
    // cerr << actual_highest;
    assert(total_highest == actual_highest);
    for (int i = 1; i <= 50; i++) inverse[i] = power(i, base - 2);

    // cerr << trans_map.size() << '\n';
}
int C(int n, int k) {
    if (n < k) return 0;
    int64_t ans = 1;
    for (int i = n; i >= n - k + 1; i--) (ans *= i) %= base;
    for (int i = 1; i <= k; i++) (ans *= inverse[i]) %= base;
    return ans;
}
int distribute(int n, int k) {
    // cerr << n << ' ' << k << '\n';
    return C(n + k - 1, k - 1);
}
int n, k, x;
void solve() {
    cin >> n >> k >> x;
    int64_t ans = 0;
    for (int i = 1; i <= used_highest; i++) {
        for (int j = 1; j <= total_highest; j++) {
            if (j > n) break;
            if (f[i][j][k][x]) {
                (ans += f[i][j][k][x] * distribute(n - j, i + 1)) %= base;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    auto start = clock();
    prepare();
    // cerr << (double(clock() - start)) / CLOCKS_PER_SEC << '\n';
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}