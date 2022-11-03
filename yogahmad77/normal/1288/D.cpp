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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(auto &i : a) for(auto &j : i) cin >> j;
    int lo = 0, hi = 1e9, ans = 0, mid;
    int aa = 0, bb = 0;
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        vector<int> ada(1 << m, 0);
        for(int i = 0; i < n; i++){
            int mask = 0;
            for(int j = 0; j < m; j++){
                if(a[i][j] >= mid)
                    mask |= 1 << j;
            }
            ada[mask] = i + 1;
        }
        int ya = 0;
        for(int i = 0; i < 1 << m; i++){
            if(!ada[i]) continue;
            for(int j = 0; j < 1 << m; j++){
                if(!ada[j]) continue;
                if((i | j) == (1 << m) - 1){
                    ya = 1;
                    aa = ada[i];
                    bb = ada[j];
                }
            }
        }
        if(ya){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    // debug(ans);
    cout << aa << ' ' << bb << endl;
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