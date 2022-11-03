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
    long long a, m;
    cin >> a >> m;
    long long gcd = __gcd(a, m);
    m /= gcd;
    set<long long> faktor, prima;
    long long now = m;
    for(long long i = 1; i * i <= m; i++){
        if(m % i == 0){
            faktor.insert(i);
            faktor.insert(m / i);
        }
        if(i > 1 && now % i == 0){
            prima.insert(i);
            while(now % i == 0) now /= i;
        }
    }
    if(now > 1) prima.insert(now);
    long long banyak = m;
    for(auto i : prima){
        banyak /= i;
        banyak *= i - 1;
    }
    cout << banyak << '\n';
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