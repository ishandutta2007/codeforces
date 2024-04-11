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
    // for(int i = 1; i <= 5; i++){
    //     for(int j = 1; j <= 100000; j++){
    //         int tot = i * j + i + j;
    //         string I = to_string(i);
    //         string J = to_string(j);
    //         int con = stoi(I + J);
    //         if(tot == con){
    //             debug(i, j);
    //         }
    //     }
    // }
    long long a, b;
    cin >> a >> b;
    long long now = b + 1;
    long long log = -1;
    while(now > 0){
        now /= 10;
        log += 1;
    }
    cout << a * log << endl;
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