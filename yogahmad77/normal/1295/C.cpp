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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> di(26);
    for(int i = 0; i < sz(s); i++) di[s[i] - 'a'].pb(i);
    int tadi = -1;
    int ans = 1;
    for(int j = 0; j < sz(t); j++){
        auto i = t[j];
        int in = upper_bound(ALL(di[i - 'a']), tadi) - di[i - 'a'].begin();
        if(in == sz(di[i - 'a']) && tadi == -1){
            cout << -1 << '\n';
            return;
        }
        else if(in == sz(di[i - 'a'])) tadi = -1, ans += 1, j -= 1;
        else tadi = di[i - 'a'][in];
    }
    cout << ans << '\n';
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