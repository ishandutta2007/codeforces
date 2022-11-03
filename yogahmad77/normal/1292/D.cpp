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


const int mx = 5001;
int p[mx], di[mx];
vector<int> prima, isi[mx], suff[mx];

void solve(){
    set<pair<vector<int>, pair<int, int>>> candidate;
    int n;
    vector<int> a(mx, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        // x = i;
        a[x] += 1;
    }
    int tadi = -1;
    for(int i = 0; i < mx; i++){
        if(a[i] == 0) continue;
        candidate.insert({suff[i], {i, i}});
        if(tadi != -1){
            vector<int> lca(sz(prima), 0);
            for(int j = sz(prima) - 1; j >= 0; j--){
                if(isi[i][j] == isi[tadi][j]){
                    lca[j] = isi[i][j];
                    continue;
                }
                lca[j] = min(isi[i][j], isi[tadi][j]);
                break;
            }
            for(int j = sz(prima) - 2; j >= 0; j--) lca[j] += lca[j + 1];
            candidate.insert({lca, {tadi, i}});
        }
        tadi = i;
    }
    long long ans = 1e18;
    for(auto xxx : candidate){
        auto center = xxx.f;
        int l = xxx.s.f;
        int r = xxx.s.s;
        long long jaw = 0;
        int di = -1;
        for(int i = l; i >= 0; i--){
            while(di + 1 < sz(prima) && center[di + 1] != suff[i][di + 1]) di += 1;
            if(di == -1 || a[i] == 0) continue;
            int ret = center[0] + suff[i][0];
            int sa = center[di];
            int du = suff[i][di];
            if(di + 1 < sz(prima)){
                ret -= center[di + 1] * 2;
                sa -= center[di + 1];
                du -= suff[i][di + 1];
            }
            ret -= min(sa, du) * 2;
            jaw += 1LL * ret * a[i];
        }
        di = -1;
        for(int i = r; i < mx; i++){
            while(di + 1 < sz(prima) && center[di + 1] != suff[i][di + 1]) di += 1;
            if(di == -1 || a[i] == 0) continue;
            int ret = center[0] + suff[i][0];
            int sa = center[di];
            int du = suff[i][di];
            if(di + 1 < sz(prima)){
                ret -= center[di + 1] * 2;
                sa -= center[di + 1];
                du -= suff[i][di + 1];
            }
            ret -= min(sa, du) * 2;
            jaw += 1LL * ret * a[i];
        }
        ans = min(ans, jaw);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i < mx; i++){
        if(p[i]) continue;
        di[i] = sz(prima);
        prima.pb(i);
        for(int j = i; j < mx; j += i)
            if(p[j] == 0) p[j] = i;
    }
    for(int i = 0; i < mx; i++){
        isi[i].resize(sz(prima), 0);
        suff[i].resize(sz(prima), 0);
        if(i <= 1) continue;
        isi[i] = isi[i - 1];
        int now = i;
        while(now > 1){
            int fak = p[now];
            while(now % fak == 0){
                now /= fak;
                isi[i][di[fak]] += 1;
            }
        }
        for(int j = sz(prima) - 1; j >= 0; j--){
            if(j == sz(prima) - 1) suff[i][j] = isi[i][j];
            else suff[i][j] = isi[i][j] + suff[i][j + 1];
        }
    }
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}