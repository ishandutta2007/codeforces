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
const int mx = 1e5 + 10;

/////////////////////////////
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
/////////////////////////////


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n, 0);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        a[u] -= w;
        a[v] += w;
    }
    vector<int> ve(n);
    iota(ALL(ve), 0);
    sort(ALL(ve), [&](int x, int y){
        return a[x] < a[y];
    });
    int l = 0, r = n - 1;
    vector<pair<pair<int, int>, long long>> ans;
    while(l < r){
        long long mini = min(abs(a[ve[l]]), abs(a[ve[r]]));
        a[ve[l]] += mini;
        a[ve[r]] -= mini;
        if(mini > 0)ans.push_back({{ve[l] + 1, ve[r] + 1}, mini});
        if(a[ve[l]] == 0) l += 1;
        if(a[ve[r]] == 0) r -= 1;
    }
    cout << sz(ans) << '\n';
    for(auto i : ans) cout << i.f.f << ' ' << i.f.s << ' ' << i.s << '\n';
}