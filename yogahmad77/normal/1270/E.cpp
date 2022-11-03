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
long long x[mx], y[mx];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    if(n == 2){
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    
    long long bagi = 2;
    while(1){
        vector<int> genap;
        genap.pb(1);
        for(int i = 2; i <= n; i++){
            if(((x[i] - x[1]) * (x[i] - x[1]) + (y[i] - y[1]) * (y[i] - y[1])) % bagi == 0)
                genap.pb(i);
        }
        if(sz(genap) > 0 && sz(genap) < n){
            cout << sz(genap) << endl;
            for(int i : genap) cout << i << ' ';
            return 0;
        }
        bagi *= 2;
    }
}