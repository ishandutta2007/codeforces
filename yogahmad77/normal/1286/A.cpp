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


const int mx = 100 + 10;

int a[mx], n;

int dep[mx][2][mx][mx];

int dp(int now, int tadi, int ganjil, int genap){
    if(now == n + 1) return 0;
    int &ret = dep[now][tadi][ganjil][genap];
    if(ret != -1) return ret;
    ret = 1e9;
    if(a[now] != 0){
        if(a[now] & 1){
            int cost = 0;
            if(now > 1 && tadi == 0) cost = 1;
            ret = dp(now + 1, 1, ganjil, genap) + cost;
        }
        else{
            int cost = 0;
            if(now > 1 && tadi == 1) cost = 1;
            ret = dp(now + 1, 0, ganjil, genap) + cost;

        }
            
    }
    else{
        if(ganjil > 0){
            int cost = 0;
            if(now > 1 && tadi == 0) cost = 1;
            ret = min(ret, dp(now + 1, 1, ganjil - 1, genap) + cost);
        }
        if(genap > 0){
            int cost = 0;
            if(now > 1 && tadi == 1) cost = 1;
            ret = min(ret, dp(now + 1, 0, ganjil, genap - 1) + cost);
        }
    }
    return ret;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ganjil = 0, genap = 0;
    for(int i = 1; i <= n; i++){
        int ada = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] == i) ada = 1;
        }
        if(!ada){
            if(i & 1) ganjil += 1;
            else genap += 1;
        }
    }
    reset(dep, -1);
    cout << dp(1, 0, ganjil, genap) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        solve();
    }
}