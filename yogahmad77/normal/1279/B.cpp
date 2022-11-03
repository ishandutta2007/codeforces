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
    int t;
    cin >> t;
    while(t--){
        int n;
        long long s;
        cin >> n >> s;
        vector<long long> a(n + 1, 0), pref(n + 1, 0);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
        if(pref[n] <= s){
            cout << 0 << '\n';
            continue;
        } 
        int maks = 0, sampai = 0, sampai2 = 0;
        for(int i = 1; i <= n; i++){
            if(pref[i - 1] >= s) continue;
            if(a[maks] < a[i]) maks = i;
        }
        for(int i = 1; i <= n; i++){
            if(pref[i] <= s) sampai = i;
        }
        long long ss = s + a[maks];
        for(int i = 1; i <= n; i++){
            if(pref[i] <= ss) sampai2 = i;
        }
        if(sampai + 1 >= sampai2) maks = 0;

        cout << maks << '\n';


    }
}