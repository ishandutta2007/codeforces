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

// 0 sama, 1 kecil
// 0 sama, 1 besar

long long dep[32][2][2][2][2];
int l, r;

long long dp(int bit, int kecil1, int kecil2, int besar1, int besar2){
    if(bit == -1) return 1;
    long long &ret = dep[bit][kecil1][kecil2][besar1][besar2];
    if(ret != -1) return ret;
    ret = 0;
    int _bit, _kecil1, _kecil2, _besar1, _besar2, valid;
    _bit = bit - 1;
    // 0 0
    valid = 1;
    if(l & (1 << bit)){
        if(besar1) _besar1 = 1;
        else valid = 0;
        if(besar2) _besar2 = 1;
        else valid = 0;
    }
    else{
        _besar1 = besar1;
        _besar2 = besar2;
    }
    if(r & (1 << bit)){
        _kecil1 = 1;
        _kecil2 = 1;
    }
    else{
        _kecil1 = kecil1;
        _kecil2 = kecil2;
    }
    if(valid) ret = ret + dp(_bit, _kecil1, _kecil2, _besar1, _besar2);
    // 0 1
    valid = 1;
    if(l & (1 << bit)){
        if(besar1) _besar1 = 1;
        else valid = 0;
        _besar2 = besar2;
    }
    else{
        _besar1 = besar1;
        _besar2 = 1;
    }
    if(r & (1 << bit)){
        _kecil1 = 1;
        _kecil2 = kecil2;
    }
    else{
        _kecil1 = kecil1;
        if(kecil2) _kecil2 = 1;
        else valid = 0;
    }
    if(valid) ret = ret + dp(_bit, _kecil1, _kecil2, _besar1, _besar2);
    // 1 0
    valid = 1;
    if(l & (1 << bit)){
        _besar1 = besar1;
        if(besar2) _besar2 = 1;
        else valid = 0;
    }
    else{
        _besar1 = 1;
        _besar2 = besar2;
    }
    if(r & (1 << bit)){
        _kecil1 = kecil1;
        _kecil2 = 1;
    }
    else{
        if(kecil1) _kecil1 = 1;
        else valid = 0;
        _kecil2 = kecil2;
    }
    if(valid) ret = ret + dp(_bit, _kecil1, _kecil2, _besar1, _besar2);
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> l >> r;
        reset(dep, -1);
        cout << dp(31, 0, 0, 0, 0) << '\n';
    }
}