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

char s[5100000];
int sc[1000003][20];

int main() {
    int n,r,c;
    scanf("%d%d%d", &n, &r, &c);
    vi v;
    vector<string> txt;
    while (scanf("%s", s) == 1) {
        v.push_back(strlen(s));
        txt.push_back((string)s);
    }
    assert(v.size() == n);
    vl sum(n + 1);
    for (int i = 0; i < v.size(); ++i)
        sum[i + 1] = sum[i] + v[i];
    int it = 0;
    for (int i = 0; i < n; ++i) {
        while (it <= n && sum[it] - sum[i] + it - i - 1 <= c)
            ++it;
        sc[i][0] = it - 1;
//        cerr << sc[i][0] << endl;
    }
    for (int i = 0; i < 20; ++i)
        sc[n][i] = n;
    for (int i = 1; i < 20; ++i)
        for (int j = 0; j < n; ++j)
            sc[j][i] = sc[sc[j][i-1]][i-1];
    int best = 0;
    ll ma = 0;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        for (int pw = 0; pw < 20; ++pw) if (r & (1 << pw))
            pos = sc[pos][pw];
        if (ma < pos - i) {
            best = i;
            ma = pos - i;
        }
//        cerr << i << ' ' << pos << endl;
    }
    for (int i = 0; i < r; ++i) {
        if (sc[best][0] == best)
            break;
        string out = "";
        for (int j = best; j < sc[best][0]; ++j) {
            out += txt[j];
            if (j + 1 < sc[best][0])
                out += " ";
        }
        best = sc[best][0];
        printf("%s\n", out.c_str());
    }
    return 0;
}