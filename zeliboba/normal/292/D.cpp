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

int e[11000][2];
vvi l;
vvi r;
vi v;
int ra[501];
int n, m;
int cur=0;

void init() {
    memset(ra, 0, sizeof(ra));
    v.resize(n);
    for (int i = 0; i < n; ++i)
        v[i] = i;
    cur = 0;
}

int getp(int a) {
    if (v[a] == a)
        return a;
    return v[a] = getp(v[a]);
}

void join(int a, int b) {
    int va = getp(a), vb = getp(b);
    if (va == vb)
        return;
    ++cur;
    if (ra[va] > ra[vb]) {
        v[vb] = va;
    } else {
        v[va] = vb;
        if (ra[va] == ra[vb])
            ++ra[vb];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &e[i][0], &e[i][1]);
        --e[i][0]; --e[i][1];
    }
    l.resize(m);
    r.resize(m);
    vi jn(m);
    init();
    for (int i = 0; i < m; ++i) {
        l[i] = v;
        jn[i] = cur;
        join(e[i][0], e[i][1]);
    }
    init();
    for (int i = 0; i < m; ++i) {
        r[i] = v;
        join(e[m-i-1][0], e[m-i-1][1]);
        for (int j = 0; j < n; ++j)
            getp(j);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
//        cerr << a << ' ' << b << ' ' << m << ' ' << l.size() << endl;
        v = l[a-1];
        cur = jn[a-1];
        memset(ra, 0, sizeof(ra));
        for (int j = 0; j < n; ++j)
            join(j, r[m-b][j]);
        printf("%d\n", n-cur);
    }
    return 0;
}