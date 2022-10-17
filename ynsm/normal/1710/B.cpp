#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 600500, inf = 1e9, mod = 998244353;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int mult(int a, int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x){
    return bp(x, mod - 2);
}

int n, m, k;
int bl[N], bm[N], br[N];

ll ax[N], ap[N];
ll c[N];
ll d[N], val[N];
ll pre[N], suf[N];

void solve() {
    k = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> ap[i] >> ax[i];

    for(int i = 0; i < n; i++) {
        c[k++] = ap[i] - ax[i];
        c[k++] = ap[i];
        c[k++] = ap[i] + ax[i];
    }
    sort(c, c + k);
    k = unique(c, c + k) - c;
    for(int i = 0; i < k; i++)
        d[i] = 0;
    for(int i = 0; i < n; i++) {
        bl[i] = lower_bound(c, c + k, ap[i] - ax[i]) - c;
        bm[i] = lower_bound(c, c + k, ap[i]) - c;
        br[i] = lower_bound(c, c + k, ap[i] + ax[i]) - c;
        d[bl[i]] += 1;
        d[bm[i]] -= 2;
        d[br[i]] += 1;
    }


    {
        ll x = d[0];
        for (int i = 1; i < k; i++) {
            val[i] = val[i - 1] + x * (c[i] - c[i - 1]);
            x += d[i];
        }
    }
    for (int i = 0; i < k; i++){
        ll need = val[i] - m;
        if(need <= 0)
            need = -1e18;
        if(i)
            pre[i] = max(pre[i - 1] + (c[i] - c[i - 1]), need);
        else
            pre[i] = need;
    }
    for(int i = k - 1; i >= 0; i--){
        ll need = val[i] - m;
        if(need <= 0)
            need = -1e18;
        if(i + 1 < k)
            suf[i] = max(suf[i + 1] + (c[i + 1] - c[i]), need);
        else
            suf[i] = need;
    }

    for(int i = 0; i < n; i++){
        ll need = max(pre[bm[i]], suf[bm[i]]);
        cout << (need <= ax[i]);
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}