#include <bits/stdc++.h>
using namespace std;
int n, q;
map<int, int> cnt_prime[200001];
int p[200001];
map<int, int> factor[200001];
vector<int> powers[200001];
int64_t ans;
constexpr int base = 1e9 + 7;
void Sub(const int p, const int value) {
    cnt_prime[p][value]--;
    if (cnt_prime[p][value] == 0) cnt_prime[p].erase(value);
}

void Add(const int p, const int value) { cnt_prime[p][value]++; }

void UpdateAnswer(const int p, const int power) {
    if (powers[p].empty()) powers[p].emplace_back(1);
    while (powers[p].size() <= power) powers[p].emplace_back((static_cast<int64_t>(powers[p].back()) * p) % base);
    (ans *= powers[p][power]) %= base;
}

void Multiply(int id, int value) {
    if (value == 1) return;
    static vector<pair<int, int>> updates;
    updates.clear();
    while (value > 1) {
        if (updates.empty() || (p[value] != updates.back().first)) {
            updates.emplace_back(p[value], 1);
        } else {
            updates.back().second++;
        }
        value /= p[value];
    }
    for (auto&& [prime, fact] : updates) {
        auto old_factor = cnt_prime[prime].begin()->first;
        Sub(prime, factor[id][prime]);
        factor[id][prime] += fact;
        Add(prime, factor[id][prime]);
        auto new_factor = cnt_prime[prime].begin()->first;
        if (new_factor > old_factor) UpdateAnswer(prime, new_factor - old_factor);
    }
}
void solve() {
    cin >> n >> q;
    for (int i = 2; i <= 200000; i++) {
        if (p[i] == 0)
            for (int j = i; j <= 200000; j += i)
                if (p[j] == 0) p[j] = i;
    }
    for (int i = 2; i <= 200000; i++)
        if (p[i] == i) {
            cnt_prime[i][0] = n;
        }
    ans = 1;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        Multiply(i, a);
    }
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        Multiply(x, y);
        cout << ans << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}