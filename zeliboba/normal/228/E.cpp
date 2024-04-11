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

pii f(int i) {
    return pii(i / 60, i % 60);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vl> a(m, vl(2));
    for (int i = 0; i < m; ++i) {
        int a1,b,c;
        scanf("%d%d%d", &a1, &b, &c);
        --a1; --b;
        pii x = f(a1), y = f(b);
        a[i][x.first] |= (1LL << x.second);
        a[i][y.first] |= (1LL << y.second);
        if (c == 0)
            a[i][1] |= (1LL << 60);
    }
    int prev = -1;
    vii res;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 60; ++j) {
        int t = prev;
        for (int l = prev + 1; l < m; ++l) if (a[l][i] & (1LL << j)) {
            t = l;
            break;
        }
        if (t == prev)
            continue;
        if (t != prev + 1)
            swap(a[t], a[prev + 1]);
        ++prev;
        res.push_back(pii(prev, i * 60 + j));
        for (int l = 0; l < m; ++l) if (l != prev && (a[l][i] & (1LL << j))) {
            a[l][0] ^= a[prev][0];
            a[l][1] ^= a[prev][1];
        }
    }
    for (int i = 0; i < m; ++i) if (a[i][0] == 0 && a[i][1] == (1LL << 60)) {
        cout << "Impossible\n";
        return 0;
    }
    vi ans;
    for (int i = 0; i < res.size(); ++i) if (a[res[i].first][1] & (1LL << 60)) {
        ans.push_back(res[i].second);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << " ";
    return 0;
}