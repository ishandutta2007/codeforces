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
vector<int> pref;
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<bool> ya(n, false);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i].resize(x);
        for(int j = 0; j < x; j++) cin >> a[i][j];
        for(int j = 1; j < x; j++) if(a[i][j] > a[i][j - 1]) ya[i] = 1;
        sort(ALL(a[i]));
    }
    pref.resize(1000000 + 100, 0);
    int berapa = 0;
    for(int i = 0; i < n; i++){
        if(ya[i]){
            berapa += 1;
            continue;
        }
        pref[a[i][0]] += 1;
    }
    for(int i = 1; i < sz(pref); i++) pref[i] += pref[i - 1];
    long long jaw = 0;
    for(int i = 0; i < n; i++){
        int x = a[i].back();
        auto tadi = jaw;
        if(ya[i]) jaw += n;
        else if(x > 0) jaw += pref[x - 1] + berapa;
        else jaw += berapa;
    }
    cout << jaw << '\n';
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