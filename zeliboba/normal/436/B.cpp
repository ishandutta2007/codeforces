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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

char s[2005][2005];

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    vi res(m);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'U' && i % 2 == 0) ++res[j];
            if (s[i][j] == 'R' && i + j < m) ++res[i+j];
            if (s[i][j] == 'L' && j - i >= 0) ++res[j-i];
        }
    }
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    return 0;
}