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
    int r, c;
    cin >> r >> c;
    if(r * c == 1){
        cout << 0 << endl;
        return 0;
    }
    if(r == 1){
        for(int i = 1; i <= c; i++) cout << i + 1 << '\n';
        cout << endl;
        return 0;
    }
    if(c == 1){
        for(int i = 1; i <= r; i++) cout << i + 1 << ' ';
        cout << endl;
        return 0;
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1 + r; j <= c + r; j++) cout << i * j << ' ';
        cout << '\n';
    }
}