#include <bits/stdc++.h>
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
typedef int (*func)(int, int);


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


const int mx = 1e7 + 3;



void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int ans = 0;
    for(int i = 29; i >= 0; i--){
        for(int &x : a) x %= 1 << (i + 1);
        sort(ALL(a));
        long long berapa = 0;
        int q = n, w = n, e = n;
        for(int l = 0; l < n; l++){
            while(q - 1 >= 0 && a[q - 1] + a[l] >= 1 << i) q -= 1;
            while(w - 1 >= 0 && a[w - 1] + a[l] >= (1 << (i + 1))) w -= 1;
            while(e - 1 >= 0 && a[e - 1] + a[l] >= (1 << i) * 3) e -= 1;

            berapa += w - q + n - e;
        }
        for(int x : a) if((x + x) & (1 << i)) berapa -= 1;
        berapa /= 2;
        if(berapa & 1) ans += 1 << i;
        // debug(1 << i, berapa);
        // for(int x : a) cout << x << ' ';
        // cout << endl;
    }
    cout << ans << '\n';
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