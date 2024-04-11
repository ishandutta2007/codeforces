#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int VS = 27*27*27*27;
const int MS = 50500;
vector<int> v[VS];
vector<int> vr[VS];

inline int getid(const string s) {
    int u = 0;
    for (char c: s) {
        u *= 27;
        u += c-'a'+1;
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    char k = 'a'-1;
    s += k; s += k; s += k;
    int n = s.size();
    for (int i = 0; i < n-3; i++) {
        for (int k = 1; k <= 4; k++) {
            v[getid(s.substr(i, k))].push_back(i);
            vr[getid(s.substr(i, k))].push_back(i+k);
        }
    }
    for (int i = 0; i < VS; i++) {
        reverse(vr[i].begin(), vr[i].end());
    }
    int m;
    cin >> m;
    map<P, int> dp;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int a = getid(s1), b = getid(s2);
        if (!v[a].size() || !v[b].size()) {
            cout << -1 << endl;
            continue;
        }
        if (s1.find(s2,0) != string::npos || s2.find(s1,0) != string::npos) {
            cout << max(s1.size(), s2.size()) << endl;
            continue;
        }
        if (P(v[a].size(), a) > P(v[b].size(), b)) {
            swap(s1, s2);
            swap(a, b);
        }
        if (dp.count(P(a, b))) {
            cout << dp[P(a, b)] << endl;
            continue;
        }

        int r = 10000000;
        int mx = v[b][v[b].size()-1];
        for (int d: v[a]) {
            if (d > mx) break;
            r = min(r, (int)(*lower_bound(v[b].begin(), v[b].end(), d)-d+s2.size()));
        }
        mx = vr[b][vr[b].size()-1];
        for (int d: vr[a]) {
            if (d < mx) break;
            r = min(r, (int)(d-*lower_bound(vr[b].begin(), vr[b].end(), d, greater<int>())+s2.size()));
        }
        dp[P(a, b)] = r;
        cout << r << endl;
    }
    return 0;
}