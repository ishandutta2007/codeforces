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
    int n, m, k;
    cin >> n >> m >> k;
    if(4 * n * m - 2 * n - 2 * m < k){
        cout << "NO\n";
        return;
    }
    vector<pair<int, string>> ret, ans;
    ret.pb({n - 1, "D"});
    ret.pb({m - 1, "R"});
    ret.pb({m - 1, "L"});
    for(int i = n - 2; i >= 0; i--){
        ret.pb({1, "U"});
        ret.pb({m - 1, "RDU"});
        ret.pb({m - 1, "L"});
    }
    for(auto x : ret){
        if(k == 0) break;
        if(x.f * sz(x.s) <= k){
            k -= x.f * sz(x.s);
            if(x.f > 0) ans.pb(x);
            continue;
        }
        int sisa = k / sz(x.s);
        if(sisa > 0){
            ans.pb({sisa, x.s});
        }
        int berapa = k % sz(x.s);
        string ini = "";
        for(int j = 0; j < berapa; j++) ini += x.s[j];
        if(berapa > 0) ans.pb({1, ini});
        break;
    }

    cout << "YES\n";
    cout << sz(ans) << endl;
    for(auto x : ans) cout << x.f << ' ' << x.s << '\n';
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