#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 101000;
int n, m;
ll s;
P a[MN];
T b[MN];

vector<int> res;
bool solve(int md) {
    res.clear();
    priority_queue<P, vector<P>, greater<P>> que;
    int l = 0;
    ll sum = 0;
    for (int i = 0; i < m; i += md) {
        while (l < n && get<0>(b[l]) >= a[i].first) {
            que.push(P(get<1>(b[l]), l));
            l++;
        }
        if (que.empty()) return false;
        P p = que.top(); que.pop();
        res.push_back(p.second);
        sum += p.first;
    }
    return (sum <= s);
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int aa;
        scanf("%d", &aa);
        a[i] = P(aa, i);
    }
    for (int i = 0; i < n; i++) {
        int bb;
        scanf("%d", &bb);
        get<0>(b[i]) = bb;
    }
    for (int i = 0; i < n; i++) {
        int cc;
        scanf("%d", &cc);
        get<1>(b[i]) = cc;
    }
    for (int i = 0; i < n; i++) {
        get<2>(b[i]) = i;
    }
    sort(a, a+m, greater<P>());
    sort(b, b+n, greater<T>());
    int l = 0, r = MN;
    while (r - l > 1) {
        int md = (r+l)/2;
        if (!solve(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    if (r > MN-100) {
        cout << "NO" << endl;
        return 0;
    }
    solve(r);
    cout << "YES" << endl;
    vector<int> re(m, 0);
    int ad = 0;
    for (int d: res) {
        for (int i = ad; i < min(ad+r, m); i++) {
            re[a[i].second] = get<2>(b[d]);
        }
        ad += r;
    }
    for (int i = 0; i < m; i++) {
        printf("%d ", re[i]+1);
    }
    printf("\n");
    return 0;
}