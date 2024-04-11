#include <bits/stdc++.h>
using namespace std;
int n, k;
int64_t x;
string s;
int64_t cnt[2001];
vector<int> weight;
vector<int64_t> rcount;
int64_t mul(int64_t a, int mul) {
    long double temp = a;
    temp *= mul;
    if (temp >= 2e18) return x + 1;
    a *= mul;
    if (a > x) return x + 1;
    return a;
}

void solve() {
    cin >> n >> k >> x >> s;
    if (k == 0) {
        for (auto&& c : s)
            if (c == 'a') cout << 'a';
        cout << '\n';
        return;
    }
    weight.clear();
    for (char c : s) {
        if (c == '*') {
            if ((weight.empty()) || (weight.back() == 0)) {
                weight.push_back(k);
            } else {
                weight.back() += k;
            }
        } else {
            weight.push_back(0);
        }
    }
    rcount.resize(weight.size() + 1);
    for (auto&& x : rcount) x = 0;
    rcount.back() = 1;
    for (int i = weight.size() - 1; i >= 0; i--) rcount[i] = mul(rcount[i + 1], weight[i] + 1);
    for (int i = 0; i < weight.size(); i++) {
        if (weight[i] == 0) {
            cout << 'a';
            continue;
        }
        int total = 0;
        while (x > rcount[i + 1]) {
            total++;
            cout << 'b';
            x -= rcount[i + 1];
        }
        assert(total <= weight[i]);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}