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
    int n, satu, nol;
    cin >> n >> satu;
    nol = n - satu;
    int panjang = nol / (satu + 1);
    int banyak = satu + 1 - (nol % (satu + 1));
    long long ans = 1LL * banyak * panjang * (panjang + 1) / 2;
    panjang = nol / (satu + 1) + 1;
    banyak = nol % (satu + 1);
    ans += 1LL * banyak * panjang * (panjang + 1) / 2;
    long long jaw = 1LL * n * (n + 1) / 2;
    jaw -= ans;
    cout << jaw << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}