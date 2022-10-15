#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vi gl(26);

bool rythm (const string &s1, const string & s2, int k) {
    int cnt = 0;
    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        if (s1[s1.size() - i - 1] != s2[s2.size() - i - 1])
            return 0;
        if (gl[s1[s1.size() - i - 1] - 'a'])
            ++cnt;
        if (cnt == k)
            return 1;
    }
    return 0;
}

int main() {
    gl[0] = gl['e' - 'a'] = gl['i' - 'a'] = gl['o' - 'a'] = gl['u' - 'a'] = 1;
    int n, k;
    cin >> n >> k;
    vector<string> vs(4*n);
    for (int i = 0; i < 4 * n; ++i)
        cin >> vs[i];
    vi ok(4, 1);
    for (int i = 0; i < n; ++i) for (int j1 = 0; j1 < 4; ++j1) for (int j2 = j1 + 1; j2 < 4; ++j2) {
        if (!rythm(vs[4 * i + j1], vs[4 * i + j2], k)) {
            ok[0] = 0;
            if (j2 - j1 == 1 && j1 != 1)
                ok[1] = 0;
            if (j2 - j1 == 2)
                ok[2] = 0;
            if (j1 + j2 == 3) {
                ok[3] = 0;
            }
        }
    }
    if (ok[0]) {
        cout << "aaaa\n";
    } else if (ok[1]) {
        cout << "aabb\n";
    } else if (ok[2]) {
        cout << "abab\n";
    } else if (ok[3]) {
        cout << "abba\n";
    } else cout << "NO\n";
    return 0;
}