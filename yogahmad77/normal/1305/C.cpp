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


int MOD = 1e9 + 7;

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


int POW(int a, int b){
    int ret = 1;
    if(b == 0) return 1;
    while(b > 0){
        if(b & 1) ret = mul(ret, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    MOD = m;
    vector<int> a(n), cnt(m, 0);
    for(int &i : a) cin >> i;
    for(int i : a) cnt[i % m] += 1;
    for(int i : cnt){

        if(i > 1){
            cout << 0 << '\n';
            return;
        }
    }
    int ans = 1;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            ans = mul(ans, abs(a[i] - a[j]));
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