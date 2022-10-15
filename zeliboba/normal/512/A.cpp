#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi d(26, vi(26));
string imp = "Impossible\n";

int main() {
    int n;
    cin >> n;
    vs s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        if (s[i].size() > s[j].size() && s[j] == s[i].substr(0, s[j].size())) {
            cout << imp;
            return 0;
        }
        for (int t = 0; t < min(s[i].size(), s[j].size()); ++t) {
            if (s[i][t] != s[j][t]) {
                d[s[i][t] - 'a'][s[j][t] - 'a'] = 1;
                break;
            }
        }
    }
    for (int m = 0; m < 26; ++m) for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) {
        if (d[i][m] && d[m][j]) d[i][j] = 1;
    }
    vii ts;
    for (int i = 0; i < 26; ++i) if (d[i][i]) {
        cout << imp;
        return 0;
    }
    for (int i = 0; i < 26; ++i) {
        int sum = 0;
        for (int j = 0; j < 26; ++j)
            sum += d[i][j];
        ts.push_back(pii(sum, i));
    }
    sort(ts.rbegin(), ts.rend());
    for (int i = 0; i < 26; ++i) 
        cout << (char)('a' + ts[i].second);
    return 0;
}