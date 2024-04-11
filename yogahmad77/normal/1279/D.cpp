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


const int MOD = 998244353;
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


long long POW(long long a, int b){
    long long ret = 1;
    while(b > 0){
        if(b & 1) ret = ret * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

int inv(int x){
    return POW(x, MOD - 2);
}
/////////////////////////////

int hit[1000003];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x--){
            int y;
            cin >> y;
            hit[y] += 1;
            a[i].pb(y);
        }
    }
    int jaw = 0;

    int aa = inv(n);
    for(int i = 0; i < n; i++){
        int bb = inv(sz(a[i]));
        for(int j : a[i]){
            jaw = add(jaw, mul(aa, mul(bb, mul(hit[j], aa))));
        }
    }
    cout << jaw << endl;
}