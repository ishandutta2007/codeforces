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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int tadi = -1;
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == -1 || a[i + 1] == -1) continue;
        ans = max(ans, abs(a[i] - a[i + 1]));
    }
    int lo = ans, hi = 1e9, mid, apa;
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        int l = 0, r = 1e9;
        for(int i = 0; i < n - 1; i++){
            if(a[i] == -1 && a[i + 1] > -1){
                l = max(l, a[i + 1] - mid);
                r = min(r, a[i + 1] + mid);
            }
            if(a[i + 1] == -1 && a[i] > -1){
                l = max(l, a[i] - mid);
                r = min(r, a[i] + mid);
            }
        }
        if(l <= r){
            apa = r;
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }   
    cout << ans << ' ' << apa << '\n';
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