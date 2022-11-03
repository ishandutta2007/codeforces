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


const int mx = 1e5 + 10;

struct FT{
    int n;
    vector<int> bit;
    FT(int N){
        n = N;
        bit.resize(n, 0);
    }
    void upd(int i, int val){
        i += 1;
        for(; i <= n; i += i & -i) bit[i - 1] += val;
    }
    int get(int i){
        i += 1;
        int ret = 0;
        for(; i > 0; i -= i & -i) ret += bit[i - 1];
        return ret;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> mini(n), maks(n), ve;
    for(int i = n - 1; i >= 0; i--) ve.pb(i);
    for(int i = 0; i < n; i++){
        mini[i] = maks[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        x -= 1;
        mini[x] = 0;
        ve.pb(x);
    }
    vector<vector<int>> isi(n);
    vector<pair<pair<int, int>, int>> query;
    for(int i = 0; i < sz(ve); i++){
        isi[ve[i]].pb(i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < sz(isi[i]); j++){
            query.pb({{isi[i][j], j + 1 == sz(isi[i]) ? sz(ve) : isi[i][j + 1]}, i});
        }
    }
    sort(ALL(query), [&](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y){
        return x.f.f < y.f.f;
    });
    FT bit(sz(ve));
    for(int i = 0; i < n; i++){
        bit.upd(isi[i][0], 1);
    }
    int l = 0;
    for(auto i : query){
        while(l < i.f.f){
            bit.upd(l, -1);
            int x = ve[l];
            int in = upper_bound(ALL(isi[x]), l) - isi[x].begin();
            if(in < sz(isi[x])){
                bit.upd(isi[x][in], 1);
            }
            l += 1;
        }
        maks[i.s] = max(maks[i.s], bit.get(i.f.f + 1, i.f.s - 1));
    }
    for(int i = 0; i < n; i++) cout << mini[i] + 1 << ' ' << maks[i] + 1 << '\n';
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