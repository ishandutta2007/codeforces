#include <bits/stdc++.h>
using namespace std;
int cnt[23][26];
constexpr int64_t base = 998244353;
using StorageType = int;

StorageType f[1 << 23];
vector<int> min_val[26];
int n;
string s;
int sign = -1;
void generate_intersection(int item, int mask) {
    if (item == n) {
        if (mask == 0) return;
        int64_t total = sign;
        for (int i = 0; i < 26; i++) (total *= min_val[i].back()) %= base;
        if (total < 0) total += base;
        f[mask] = total;
        // cerr << "Intersection: " << mask << ' ' << total << '\n';
    } else {
        generate_intersection(item + 1, mask);

        if (mask == 0)
            for (int i = 0; i < 26; i++) min_val[i].push_back(cnt[item][i]);
        else
            for (int i = 0; i < 26; i++) min_val[i].push_back(min(min_val[i].back(), cnt[item][i]));
        sign = -sign;
        generate_intersection(item + 1, mask ^ (1 << item));
        sign = -sign;
        for (int i = 0; i < 26; i++) min_val[i].pop_back();
    }
}

void perform_SOS() {
    for (int bit = 0; bit < n; bit++) {
        for (int i = 0; i < (1 << n); i++) {
            if (((i >> bit) & 1) == 0) {
                f[i ^ (1 << bit)] += f[i];
                if (f[i ^ (1 << bit)] >= base) f[i ^ (1 << bit)] -= base;
            }
        }
    }
}
int64_t ans = 0;
int sum = 0;
int item_count = 0;
void get_ans(int item, int mask) {
    if (item == n) {
        ans ^= ((int64_t(f[mask])) * sum * item_count);
    } else {
        get_ans(item + 1, mask);
        sum += item + 1;
        item_count++;
        get_ans(item + 1, mask ^ (1 << item));
        item_count--;
        sum -= item + 1;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (auto&& x : s) cnt[i][x - 'a']++;
        for (int x = 0; x < 26; x++) cnt[i][x]++;
    }
    generate_intersection(0, 0);
    perform_SOS();
    // for (int i = 0; (i < (1 << n)); i++) cerr << "Union: " << i << ' ' << f[i] << '\n';

    get_ans(0, 0);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--) solve();
}