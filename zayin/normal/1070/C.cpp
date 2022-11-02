#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,k,m;
typedef long long ll;

ll cnt[4*N], tot[4*N], ans;
vector<int> ins[N], del[N];
int c[N], p[N];
const int M = 1e6 + 1;


void add(int x, ll y, int v = 0, int l = 1, int r = M) {
    cnt[v] += y;
    tot[v] += x * y;
    if (l + 1 == r) return;
    int mid = (l + r) / 2, chl = v * 2 + 1, chr = v * 2 + 2;
    if (x < mid) add(x, y, chl, l, mid);
    else add(x, y, chr, mid, r);
}

ll query(ll k, int v = 0, int l = 1, int r = M) {
    if (k <= 0) return 0;
    if (cnt[v] <= k) return tot[v];
    if (l + 1 == r) return k * l;
    int mid = (l + r) / 2, chl = v * 2 + 1, chr = v * 2 + 2;   
    if (k <= cnt[chl]) return query(k, chl, l, mid);
    else return tot[chl] + query(k - cnt[chl], chr, mid, r); 
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < m; i++) {
        int l,r;
        scanf("%d%d%d%d", &l, &r, c + i, p + i);
        ins[l].push_back(i);
        del[r].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto j: ins[i]) {
            add(p[j], c[j]);
        }
        ans += query(k);    
        for (auto j: del[i]) {
            add(p[j], -c[j]);
        }
    }
    printf("%lld\n", ans);
}