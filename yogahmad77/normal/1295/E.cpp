#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())


const int MOD = 1e9 + 7;

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 2e5 + 10;

long long lazy[mx * 4], mini[mx * 4];

void upd(int idx, int l, int r, int fl, int fr, int val){
    if(fl > r || fr < l) return;
    if(fl <= l && r <= fr){
        lazy[idx] += val;
        mini[idx] += val;
        // debug(idx, mini[idx]);
        return;
    }
    if(lazy[idx] != 0){
        mini[idx * 2] += lazy[idx];
        mini[idx * 2 + 1] += lazy[idx];
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
        lazy[idx] = 0;
    }
    int mid = (l + r) >> 1;
    upd(idx * 2, l, mid, fl, fr, val);
    upd(idx * 2 + 1, mid + 1, r, fl, fr, val);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}



void solve(){
    int n;
    cin >> n;
    vector<int> p(n), a(n), di(n);
    for(int i = 0; i < n; i++) cin >> p[i], p[i] -= 1;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        di[p[i]] = i;
        upd(1, 0, n - 2, i, n - 2, a[i]);
    }
    long long ans = mini[1];
    // debug(ans);
    for(int i = 0; i < n; i++){
        upd(1, 0, n - 2, di[i], n - 2, -a[di[i]]);
        upd(1, 0, n - 2, 0, di[i] - 1, a[di[i]]);
        ans = min(mini[1], ans);
        // debug(i, mini[1]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}