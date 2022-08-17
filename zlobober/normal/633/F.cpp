#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

const int N = 100500;

llong A[N];

llong mxd[N];
llong mxdpath[N];

vector<int> E[N];

const llong inf = 1e18;

void DFS1(int x, int p = -1) {
    mxd[x] = A[x];
    vector<llong> val;
    val.reserve(3);
    for (int y : E[x]) {
        if (p == y)
            continue;
        DFS1(y, x);
        mxd[x] = max(mxd[x], A[x] + mxd[y]);
        val.push_back(mxd[y]);
        sort(val.rbegin(), val.rend());
        val.resize(min((int)val.size(), 3));
        mxdpath[x] = max(mxdpath[x], mxdpath[y]);
    }
    if (val.size() == 0)
        mxdpath[x] = max(mxdpath[x], A[x]);
    else if (val.size() == 1)
        mxdpath[x] = max(mxdpath[x], A[x] + val[0]);
    else
        mxdpath[x] = max(mxdpath[x], A[x] + val[0] + val[1]);
}

llong ans = 0;

inline llong get_neq(const vector<llong>& a, llong x) {
    if (a.empty())
        return 0;
    if (a[0] == x && a.size() == 1)
        return 0;
    if (a[0] == x)
        return a[1];
    else
        return a[0];
}

inline llong get_neq2(const vector<llong>& a, llong x) {
    llong res = 0;
    int cnt = 0;
    bool was = false;
    for (int i = 0; i < a.size(); i++) {
        if (!was && a[i] == x)
            was = true;
        else {
            cnt++, res += a[i];
            if (cnt == 2)
                break;
        }
    }
    return res;
}

void DFS2(int x, llong mxu = 0, llong mxupath = 0, int p = -1) {
    vector<llong> valmxd, valmxdpath;
    valmxd.reserve(4);
    valmxdpath.reserve(3);
    for (int y : E[x]) {
        if (p == y)
            continue;
        valmxd.push_back(mxd[y]);
        sort(valmxd.rbegin(), valmxd.rend());
        valmxd.resize(min((int)valmxd.size(), 3));
        valmxdpath.push_back(mxdpath[y]);
        sort(valmxdpath.rbegin(), valmxdpath.rend());
        valmxdpath.resize(min((int)valmxdpath.size(), 2));
    }
    ans = max(ans, mxupath + A[x]);
    if (valmxd.size() >= 1) {
        ans = max(ans, mxupath + A[x] + valmxd[0]);
    }
    if (valmxd.size() >= 2) {
        ans = max(ans, mxupath + A[x] + valmxd[0] + valmxd[1]);
    }
    for (int y : E[x]) {
        if (p == y)
            continue;
        llong tmxd = mxd[y];
        llong tmxdpath = mxdpath[y];
        llong nmxu = max(mxu + A[x], A[x] + get_neq(valmxd, tmxd));
        llong nmxupath = max({mxupath,  get_neq(valmxdpath, tmxdpath), mxu + A[x] + get_neq(valmxd, tmxd), A[x] + get_neq2(valmxd, tmxd)});
        DFS2(y, nmxu, nmxupath, x);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        A[i] = x;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS1(0);
    DFS2(0);
    cout << ans << endl;
}