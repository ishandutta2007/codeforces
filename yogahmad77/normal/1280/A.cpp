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

void solve(){
    int x;
    string ss;
    cin >> x;
    cin >> ss;
    int l = 0;
    long long panjang = sz(ss);
    for(int i = 0; i < x; i++){
        l += 1;
        int sampai = sz(ss);
        long long tambah = panjang - l;
        for(int j = 0; j < ss[l - 1] - '0' - 1; j++){
            int now = l;
            panjang += tambah;
            panjang %= MOD;
            while(now < sampai){
                if(sz(ss) >= x + 5) break;
                ss += ss[now];
                now += 1;
            }
        }
        // debug(i, l, panjang, ss, ss[l - 1]);
    }
    panjang %= MOD;
    if(panjang < 0) panjang += MOD;
    cout << panjang << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}