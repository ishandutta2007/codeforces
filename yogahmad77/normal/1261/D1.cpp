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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 998244353;
const int mx = 2000 + 10;

int n, k, ans[mx];

long long dep[mx][mx + mx];

long long dp(int now, int selisih){
    if(now == n){
        if(selisih > 0) return 1;
        return 0;
    }
    long long &ret = dep[now][selisih + 2000];
    if(ret != -1) return ret;
    ret = 0;
    set<int> ii;
    ii.insert(ans[now]);
    ii.insert(ans[(now + 1) % n]);
    for(int i : ii){
        int x = (now + 1) % n;
        int nex = selisih;
        if(ans[now] == i) nex -= 1;
        if(ans[x] == i) nex += 1;
        ret = (ret + dp(now + 1, nex)) % MOD;
    }
    ret = (ret + dp(now + 1, selisih) * (k - sz(ii))) % MOD;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> ans[i];
        ans[i] -= 1;
    }
    reset(dep, -1);
    cout << dp(0, 0) << endl;
}