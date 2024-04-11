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


const int mx = 1e5 + 10;
int berapa[mx], tambah[mx];
void solve(){
    int n, m;
    cin >> n >> m;
    if(m == 0){
        for(int i = n + 100; i < n + n + 100; i++) cout << i << ' ';
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(i <= 2) berapa[i] = 0;
        else berapa[i] = berapa[i - 2] + i - 2;
    }
    int cnt = n;
    vector<int> ans;
    for(int i = n; i > 2; i--){
        if(m >= berapa[i] && cnt >= i){
            m -= berapa[i];
            cnt -= i;
            for(int x = 1; x <= i; x++)
                ans.pb(x);
            break;
        }
    }
    if(m == 0 && cnt == 0){
        for(int i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }
    else if(cnt == 0){
        cout << -1 << '\n';
        return;
    }
    for(int i = 0; i < sz(ans); i++){
        for(int j = i + 1; j < sz(ans); j++){
            tambah[ans[i] + ans[j]] += 1;
        }
    }
    for(int i = sz(ans) + 1; i < mx; i++){
        if(tambah[i] == m){
            ans.pb(i);
            m -= i;
            break;
        }
    }
    if(m > 0){
        cout << -1 << '\n';
        return;
    }
    int now = ans[sz(ans) - 1] + ans[sz(ans) - 2] + 1;
    int tambah = ans.back() + 1; 
    while(sz(ans) < n){
        ans.pb(now);
        now += tambah;
    }
    for(int i : ans) cout << i << ' ';
    cout << '\n';
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