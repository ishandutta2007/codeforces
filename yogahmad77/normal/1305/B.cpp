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

void solve(){
    string ss;
    cin >> ss;
    vector<vector<int>> ret;
    while(1){
        vector<int> ans;
        int n = sz(ss);
        int l = 0, r = n - 1;
        while(l < r){
            if(ss[l] != '('){
                l += 1;
                continue;
            }
            if(ss[r] != ')'){
                r -= 1;
                continue;
            }
            ans.pb(l);
            ans.pb(r);
            l += 1;
            r -= 1;
        }
        sort(ALL(ans));
        if(ans.empty()) break;
        string tmp = "";
        for(int i = 0; i < n; i++){
            int in = lower_bound(ALL(ans), i) - ans.begin();
            if(in == sz(ans) || ans[in] != i){
                tmp += ss[i];
            }
        }
        ss = tmp;
        ret.pb(ans);
    }
    cout << sz(ret) << '\n';
    for(auto i : ret){
        cout << sz(i) << '\n';
        for(auto x : i) cout << x + 1 << ' ';
        cout << '\n';
    }
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