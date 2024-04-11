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

const int N = 1000000;

int invind[N + 1];
int len[5000][5000];

int main() {
    int n;
    cin >> n;
    vi b(n), ts(n);
    vi ind(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        ts[i] = b[i];
    }
    sort(ts.begin(), ts.end());
    ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
    for (int i = 0; i < ts.size(); ++i) {
        ind[i] = ts[i];
        invind[ts[i]] = i;
    }
    memset(len, 0, sizeof(len));
    int ma = 1;
    vi cnt(n);
    for (int i = 0; i < n; ++i) {
        b[i] = invind[b[i]];
        ++cnt[b[i]];
        ma = max(ma, cnt[b[i]]);
        for (int j = 0; j < i; ++j) if (b[i] != b[j]) {
            if (len[b[j]][b[i]] > 0) {
                len[b[i]][b[j]] = len[b[j]][b[i]] + 1;
            } else len[b[i]][b[j]] = 2;
            ma = max(ma, len[b[i]][b[j]]);
        }
    }
    cout << ma << endl;
    return 0;
}