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
struct SegmentTree{
    int n;
    vector<long long> sum1, sum2, lazy, tot;
    SegmentTree(int N){
        n = N;
        sum2.resize(n * 4 + 5, 0);
        lazy.resize(n * 4 + 5, 0);
    }

 
    void upd(int idx, int l, int r, int fl, int fr, int val){
        if(fl > r || fr < l) return;
        if(fl <= l && r <= fr){
            lazy[idx] += val;
            sum2[idx] += 1LL * val * (r - l + 1);
            return;
        }
        int mid = (l + r) >> 1;
        if(lazy[idx]){
            sum2[idx * 2] += lazy[idx] * (mid - l + 1);
            sum2[idx * 2 + 1] += lazy[idx] * (r - mid);
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx] = 0;
        }
        upd(2 * idx, l, mid, fl, fr, val);
        upd(2 * idx + 1, mid + 1, r, fl, fr, val);
        sum2[idx] = sum2[idx * 2] + sum2[idx * 2 + 1];
    }

    long long cari(int idx, int l, int r, int fl, int fr){
        if(fl > r || fr < l) return 0;
        if(fl <= l && r <= fr) return sum2[idx];
        int mid = (l + r) >> 1;
        if(lazy[idx]){
            sum2[idx * 2] += lazy[idx] * (mid - l + 1);
            sum2[idx * 2 + 1] += lazy[idx] * (r - mid);
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx] = 0;
        }
        return cari(2 * idx, l, mid, fl, fr) + cari(2 * idx + 1, mid + 1, r, fl, fr);
    }
 
    void upd(int l, int r, int val){
        upd(1, 0, n - 1, l, r, val);
    }

    long long cari(int l, int r){
        return cari(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> s[2], e[2];
    for(int i = 0; i < 2; i++) s[i].resize(n), e[i].resize(n);
    vector<int> ve;
    for(int i = 0; i < n; i++){
        cin >> s[0][i] >> e[0][i] >> s[1][i] >> e[1][i];
        ve.pb(s[0][i]);
        ve.pb(e[0][i]);
        ve.pb(s[1][i]);
        ve.pb(e[1][i]);
    }
    sort(ALL(ve));
    for(int i = 0; i < n; i++){
        s[0][i] = lower_bound(ALL(ve), s[0][i]) - ve.begin();
        e[0][i] = lower_bound(ALL(ve), e[0][i]) - ve.begin();
        s[1][i] = lower_bound(ALL(ve), s[1][i]) - ve.begin();
        e[1][i] = lower_bound(ALL(ve), e[1][i]) - ve.begin();
    }
    for(int i = 0; i < 2; i++){
        vector<int> vv(n);
        iota(ALL(vv), 0);
        sort(ALL(vv), [&](int x, int y){
            return s[i][x] < s[i][y];
        });
        SegmentTree ST(500000);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int j : vv){
            while(!pq.empty() && pq.top().f < s[i][j]){
                int now = pq.top().s;
                pq.pop();
                ST.upd(s[i ^ 1][now], e[i ^ 1][now], 1);
            }
            auto cek = ST.cari(s[i ^ 1][j], e[i ^ 1][j]);
            if(cek){
                cout << "NO\n";
                return;
            }
            pq.push({e[i][j], j});
        }
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        solve();
    }
}