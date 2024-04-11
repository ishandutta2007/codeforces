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



struct FT{
    int n;
    vector<int> bit;
    FT(int N){
        n = N;
        bit.resize(n, 0);
    }
    void upd(int i, int val){
        i += 1;
        for(; i <= n; i += i & -i) bit[i - 1] += val;
    }
    int get(int i){
        i += 1;
        int ret = 0;
        for(; i > 0; i -= i & -i) ret += bit[i - 1];
        return ret;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), pos(n);
        FT bit(n);
        for(int &i : a) cin >> i, i -= 1;
        for(int &i : b) cin >> i, i -= 1;
        for(int i = 0; i < n; i++) pos[a[i]] = i;
        long long ans = 0;
        for(int i = 0; i < n; i++) bit.upd(i, 1);
        int maks = -1;
        for(int i = 0; i < m; i++){
            int mana = bit.get(pos[b[i]]);
            if(pos[b[i]] > maks){
                ans += mana * 2 - 1;
                maks = pos[b[i]];
            }
            else ans += 1;
            bit.upd(pos[b[i]], -1);
        }
        cout << ans << '\n';
    }
}