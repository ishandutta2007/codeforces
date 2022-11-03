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


const int mx = 5004 + 10;
vector<int> s, f, h, a, b;

int dp1[mx][4], dp2[mx][4];

int n, m;
int sampai;
int di;

//kiri 1
// kanan 2

pair<int, int> dp(int now, int tadi){
    if(now == 0 || now == m || f[now] != f[now - 1]) tadi = 0;
    if(now == m) return {0, 1};
    int &ret = dp1[now][tadi];
    int &sum = dp2[now][tadi];
    if(ret != -1) return {ret, sum};
    ret = sum = -1e9;
    if(a[now] == -1){
        ret = dp(now + 1, tadi).f;
        sum = dp(now + 1, tadi).s;
        return {ret, sum};
    }
    if(di == now){
        if(tadi & 1){
            ret = -1e9;
            sum = 1;
            return {ret, sum};
        }
        ret = dp(now + 1, tadi | 1).f + 1;
        sum = dp(now + 1, tadi | 1).s;
        return {ret, sum};
    }
    else{
        int inv = 3 - tadi;
        // gak ngambil
        ret = dp(now + 1, tadi).f;
        sum = dp(now + 1, tadi).s;

        //ngambil kiri
        if((inv & 1) == 1 && a[now] < sampai){
            auto aa = dp(now + 1, tadi | 1);
            if(ret == aa.f + 1) sum = add(sum, aa.s);
            else if(ret < aa.f + 1){
                ret = aa.f + 1;
                sum = aa.s;
            }
        }
        if((inv & 2) == 2 && b[now] > sampai){
            auto aa = dp(now + 1, tadi | 2);
            if(ret == aa.f + 1) sum = add(sum, aa.s);
            else if(ret < aa.f + 1){
                ret = aa.f + 1;
                sum = aa.s;
            }
        }
    }
    return {ret, sum};
}

void solve(){
    cin >> n >> m;
    s.resize(n), f.resize(m), h.resize(m), a.resize(m), b.resize(m);
    vector<pair<int, int>> ini(m);
    vector<vector<int>> isi(n);
    for(int &i : s){
        cin >> i;
        i -= 1;
    }
    for(int i = 0; i < n; i++) isi[s[i]].pb(i);
    for(int i = 0; i < m; i++) cin >> ini[i].f >> ini[i].s;
    sort(ALL(ini));
    for(int i = 0; i < m; i++){
        f[i] = ini[i].f;
        h[i] = ini[i].s;
        f[i] -= 1;
        if(sz(isi[f[i]]) < h[i]){
            a[i] = b[i] = -1;
            continue;
        }
        a[i] = isi[f[i]][h[i] - 1];
        b[i] = isi[f[i]][sz(isi[f[i]]) - h[i]];
    }
    for(int now = 0; now < m; now++)
        for(int tadi = 0; tadi < 4; tadi++)
            dp1[now][tadi] = dp2[now][tadi] = -1;
    sampai = -1;
    di = -1;
    auto aa = dp(0, 0);
    int ret = aa.f;
    int sum = aa.s;
    for(int i = 0; i < m; i++){
        if(a[i] == -1) continue;
        for(int now = 0; now < m; now++)
            for(int tadi = 0; tadi < 4; tadi++)
                dp1[now][tadi] = dp2[now][tadi] = -1;
        sampai = a[i];
        di = i;
        auto aa = dp(0, 0);
        if(aa.f == ret) sum = add(sum, aa.s);
        else if(ret < aa.f){
            ret = aa.f;
            sum = aa.s;
        }
    }
    cout << ret << ' ' << sum << '\n';
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