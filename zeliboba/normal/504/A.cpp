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

int main() {
    int n;
    cin >> n;
    vi d(n), s(n);
    vi q;
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> s[i];
        if (d[i] == 1) q.push_back(i);
    }
    vii ans;
    for (int it = 0; it < q.size(); ++it) {
        int v = q[it];
        if (d[v] != 1) continue;
        ans.push_back(pii(v, s[v]));
        s[s[v]] ^= v;
        d[s[v]]--;
        if (d[s[v]] == 1) q.push_back(s[v]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}