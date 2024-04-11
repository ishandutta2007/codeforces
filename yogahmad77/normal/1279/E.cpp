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

long long fak[100], dep[100];

long long dp(int sisa){
    if(sisa == 0) return 1;
    long long &ret = dep[sisa];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i <= sisa; i++){
        long long ini = 3e18;
        long long ff = 1;
        if(i > 2) ff = fak[i - 2];
        if(ini / ff >= dp(sisa - i)){
            ret = ret + dp(sisa - i) * ff;
            ret = min(ret, (long long) 2e18);
        }
        else ret = 2e18;
    }
    return ret;
}

vector<int> ans;

int find(int x, vector<int> &par){
    if(x == par[x]) return x;
    return par[x] = find(par[x], par);
}

void gabung(int x, int y, vector<int> &par){
    x = find(x, par);
    y = find(y, par);
    par[x] = y;
}

vector<int> kth_permutation(long long berapa, int n){
    vector<int> ret(n);
    ret[0] = n - 1;
    vector<int> par(n);
    iota(ALL(par), 0);
    gabung(0, n - 1, par);
    for(int i = 1; i < n - 1; i++){
        vector<int> apa, sudah(n, 0);
        for(int j = 0; j < i; j++) sudah[ret[j]] = 1;
        for(int j = 0; j < n; j++) if(!sudah[j] && find(i, par) != find(j, par)) apa.pb(j);
        long long ff = 1;
        int xx = n - 2 - i;
        if(xx >= 0) ff = fak[xx];
        for(int j : apa){
            if(berapa >= ff){
                berapa -= ff;
                continue;
            }
            ret[i] = j;
            gabung(i, j, par);
            break;
        }
    }
    vector<int> sudah(n, 0);
    for(int j = 0; j < n - 1; j++) sudah[ret[j]] = 1;
    for(int j = 0; j < n; j++){
        if(!sudah[j]) ret[n - 1] = j;
    } 
    return ret;
}

void bt(int offset, int sisa, long long berapa){
    if(sisa == 0) return;
    for(int i = 1; i <= sisa; i++){
        long long ini = 3e18;
        long long ff = 1;
        if(i > 2) ff = fak[i - 2];
        if(ini / ff >= dp(sisa - i)){
            if(berapa >= ff * dp(sisa - i)){
                berapa -= ff * dp(sisa - i);
                continue;
            }
            long long ke = berapa / dp(sisa - i);
            auto aa = kth_permutation(ke, i);
            for(int x : aa) ans.pb(x + offset);
            bt(offset + i, sisa - i, berapa % dp(sisa - i));
            return;
        }
        else{
            long long ke = berapa / dp(sisa - i);
            auto aa = kth_permutation(ke, i);
            for(int x : aa) ans.pb(x + offset);
            bt(offset + i, sisa - i, berapa % dp(sisa - i));
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fak[0] = 1;
    for(int i = 1; i <= 19; i++){
        fak[i] = fak[i - 1] * i;
    }
    for(int i = 20; i <= 50; i++) fak[i] = 2e18;
    for(int i = 0; i < 30; i++){
        // debug(i, fak[i]);
    }
    int t;
    cin >> t;
    reset(dep, -1);
    while(t--){
        long long n, m;
        cin >> n >> m;
        if(dp(n) < m){
            cout << -1 << '\n';
            continue;
        }
        ans.clear();
        bt(1, n, m - 1);
        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
}