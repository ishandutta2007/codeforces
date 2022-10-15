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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

char s[100000][2][51];

bool less1(int i, int a, int j, int b) {
    int n = strlen(s[i][a]);
    int m = strlen(s[j][b]);
    for (int l = 0; l < min(m, n); ++l) {
        if (s[i][a][l] < s[j][b][l]) return 1;
        if (s[i][a][l] > s[j][b][l]) return 0;
    }
    return n < m;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", s[i][0], s[i][1]);
    }
    vi p(n);
    vi q(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
        q[p[i]] = i;
    }
    vi v(2);
    v[1] = 1;
    for (int i = 1; i < n; ++i) if (!v.empty()) {
        vi was(2);
        for (int t = 0; t < v.size(); ++t) for (int j = 0; j < 2; ++j) if (!was[j]) {
            if (less1(p[i-1], v[t], p[i], j))
                was[j] = 1;
        }
        v.clear();
        for (int j = 0; j < 2; ++j) if (was[j])
            v.push_back(j);
    }
    if (v.empty()) printf("NO\n");
    else printf("YES\n");
    return 0;
}