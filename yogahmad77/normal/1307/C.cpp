#include <bits/stdc++.h>
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
    string ss;
    cin >> ss;
    vector<int> cnt(26, 0);
    vector<vector<int>> isi(26);
    long long ans = 0;
    for(auto i : ss){
        cnt[i - 'a'] += 1;
        ans = max(ans, (long long)cnt[i - 'a']); 
        ans = max(ans, 1LL * cnt[i - 'a'] * (cnt[i - 'a'] - 1) / 2); 
    }
    for(int i = 0; i < sz(ss); i++) isi[ss[i] - 'a'].pb(i);
    for(int i = 0; i < 26; i++){
        vector<int> pref(sz(ss), 0);
        for(int j = 0; j < sz(ss); j++){
            if(ss[j] - 'a' == i)
                pref[j] += 1;
        }
        for(int j = 1; j < sz(ss); j++)
            pref[j] += pref[j - 1];
        for(int j = 0; j < 26; j++){
            long long brp = 0;
            if(j == i) continue;
            for(int x : isi[j]) brp += pref[x];
            ans = max(ans, brp);
        }
    }
    cout << ans << '\n';
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