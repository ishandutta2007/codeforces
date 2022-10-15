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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

char s[2005][2005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    vi h(n), v(n);
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v1 = 0, h1 = 0;
        for (int j = 0; j < i; ++j) {
            if ((v1 + v[j] + s[i][j] - '0') & 1) {
                ++v[j];
                ++v1;
                ++res;
            }
            if ((h1 + h[j] + s[j][i] - '0') & 1) {
                ++h[j];
                ++h1;
                ++res;
            }
        }
        if ((h1 + v1 + v[i] + h[i] + s[i][i] - '0') & 1)
            ++res;
    }
    cout << res << endl;
    return 0;
}