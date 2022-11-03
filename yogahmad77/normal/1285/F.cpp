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
    int n;
    cin >> n;
    vector<vector<int>> fak(mx), isi(mx);
    vector<int> mobius(mx);
    for(int i = 1; i < mx; i++){
        for(int j = i; j < mx; j += i)
            fak[j].pb(i);
    }
    for(int i = 1; i < mx; i++){
        int now = i;
        mobius[i] = 1;
        while(now > 1){
            int f = fak[now][1];
            now /= f;
            mobius[i] *= -1;
            while(now % f == 0){
                now /= f;
                mobius[i] = 0;
            }
        }
    }
    set<int> a;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i : a){
        for(int j : fak[i]){
            isi[j].pb(i);
        }
        ans = i;
    }

    vector<int> cnt(mx, 0);
    for(int gcd = 1; gcd < mx; gcd++){
        if(sz(isi[gcd]) == 0) continue;
        sort(ALL(isi[gcd]));
        reverse(ALL(isi[gcd]));
        stack<int> bil;

        function<int(int)> count = [&](int i){
            int ret = 0;
            for(int j : fak[i]) ret += cnt[j] * mobius[j];
            return ret;
        };

        function<void(int, int)> ubah = [&](int i, int val){
            for(int j : fak[i])
                cnt[j] += val;
        };

        for(int i : isi[gcd]){
            int ii = i / gcd;
            int coprime = count(ii);
            while(coprime > 0){
                int atas = bil.top();
                bil.pop();
                ubah(atas, -1);
                if(__gcd(ii, atas) == 1){
                    ans = max(ans, 1LL * ii * atas * gcd);
                    coprime -= 1;
                }
            }
            bil.push(ii);
            ubah(ii, 1);
        }

        while(!bil.empty()){
            ubah(bil.top(), -1);
            bil.pop();
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}