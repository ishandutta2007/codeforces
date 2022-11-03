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


const int MOD = 998244353;

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
    int n, k;
    cin >> n >> k;
    vector<int> p(n), di(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i] -= 1;
        di[p[i]] = i;
    }
    long long ans1 = k;
    int ans2 = 1;
    vector<int> ve;
    for(int i = n - 1; i >= n - k; i--){
        ve.pb(di[i]);
        ans1 += i;
    }
    sort(ALL(ve));
    for(int i = 1; i < sz(ve); i++){
        ans2 = mul(ans2, ve[i] - ve[i - 1]);
    }
    cout << ans1 << ' ' << ans2 << '\n';
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