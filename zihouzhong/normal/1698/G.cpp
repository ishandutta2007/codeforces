#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int p = 1;
    while (!s.empty() && s[0] == '0') s.erase(s.begin()), p++;
    while (s.back() == '0') s.pop_back();
    if (s.empty()) cout << "-1\n", exit(0);
    ll mask = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') mask |= 1LL << i;
    }
    const int B = 1e5;
    vector<ll> pw(B);
    unordered_map<ll, int> mp;
    ll x = 1;
    for (int i = 0; i < B; i++) {
        mp[pw[i] = x] = i, x <<= 1;
        if (x >> (s.size() - 1) & 1) x ^= mask;
    }
    vector<ll> b(s.size());
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (x >> j & 1) b[i] ^= pw[i + j];
        }
    }
    x = 1;
    for (int i = 1; ; i++) {
        ll _x = 0;
        for (int j = 0; j < s.size(); j++) {
            if (x >> j & 1) _x ^= b[j];
        }
        if (mp.count(x = _x)) {
            cout << p << " " << p + 1LL * i * B - mp[x] << "\n"; break;
        }
    }
    return 0;
}