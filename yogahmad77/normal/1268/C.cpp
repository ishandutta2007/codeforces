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
const int mx = 2e5 + 10;

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

int a[mx], di[mx];
long long ans[mx];

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

long long sum[2][mx * 4], lazy[2][mx * 4];

void upd(int t, int idx, int l, int r, int fl, int fr){
    if(fl > r || fr < l) return;
    if(fl <= l && r <= fr){
        sum[t][idx] += r - l + 1;
        lazy[t][idx] += 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(lazy[t][idx]){
        sum[t][idx * 2] += lazy[t][idx] * (mid - l + 1);
        sum[t][idx * 2 + 1] += lazy[t][idx] * (r - mid);
        lazy[t][idx * 2] += lazy[t][idx];
        lazy[t][idx * 2 + 1] += lazy[t][idx]; 
        lazy[t][idx] = 0;
    }
    upd(t, 2 * idx, l, mid, fl, fr);
    upd(t, 2 * idx + 1, mid + 1, r, fl, fr);
    sum[t][idx] = sum[t][idx * 2] + sum[t][idx * 2 + 1];
}

long long cari(int t, int idx, int l, int r, int fl, int fr){
    if(fl > r || fr < l) return 0;
    if(fl <= l && r <= fr) return sum[t][idx];
    int mid = (l + r) >> 1;
    if(lazy[t][idx]){
        sum[t][idx * 2] += lazy[t][idx] * (mid - l + 1);
        sum[t][idx * 2 + 1] += lazy[t][idx] * (r - mid);
        lazy[t][idx * 2] += lazy[t][idx];
        lazy[t][idx * 2 + 1] += lazy[t][idx]; 
        lazy[t][idx] = 0;
    }
    return cari(t, 2 * idx, l, mid, fl, fr) + cari(t, 2 * idx + 1, mid + 1, r, fl, fr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= 1;
        di[a[i]] = i;
    }
    FT bit1(n);
    for(int i = 0; i < n; i++){
        ans[i] = bit1.get(di[i] + 1, n - 1);
        if(i > 0) ans[i] += ans[i - 1];
        bit1.upd(di[i], 1);
    }
    int L = 1e9, R = -1;
    priority_queue<int> kiri;
    priority_queue<int, vector<int>, greater<int>> kanan;
    for(int i = 0; i < n; i++){
        upd(0, 1, 0, n - 1, 0, di[i] - 1);
        upd(1, 1, 0, n - 1, di[i] + 1, n - 1);
        kiri.push(di[i]);
        kanan.push(kiri.top());
        kiri.pop();
        while(sz(kanan) > sz(kiri)){
            kiri.push(kanan.top());
            kanan.pop();
        }
        L = min(L, di[i]);
        R = max(R, di[i]);
        if(i == 0) continue;
        if(sz(kanan) == sz(kiri)){
            auto sa = cari(1, 1, 0, n - 1, L, kiri.top());
            auto du = cari(0, 1, 0, n - 1, kanan.top(), R);
            auto ti = cari(1, 1, 0, n - 1, kiri.top() + 1, kanan.top() - 1);
            ans[i] += sa + du + ti;
            long long brp = sz(kanan) - 1;
            brp = brp * (brp + 1) / 2;
            ans[i] -= brp + brp;
        }
        else{
            auto sa = cari(1, 1, 0, n - 1, L, kiri.top() - 1);
            auto du = cari(0, 1, 0, n - 1, kiri.top() + 1, R);
            ans[i] += sa + du;
            long long brp = sz(kanan) - 1;
            brp = brp * (brp + 1) / 2;
            ans[i] -= brp + brp;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}