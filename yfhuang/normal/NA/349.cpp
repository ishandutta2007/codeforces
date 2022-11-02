#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;


int q;
int r, n;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;

int fac[maxn], inv[maxn];
bool isprime[maxn];
vector<int> pdiv[maxn];

int f[1000005][22];

void init(){
    isprime[1] = true;
    for(int i = 2;i < maxn;i++){
        if(!isprime[i]){
            pdiv[i].push_back(i);
            for(int j = 2 * i;j < maxn;j += i){
                isprime[j] = true;
                pdiv[j].push_back(i);
            }
        }
    }
}

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

void pre_comb(){
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for(int i = maxn - 2;i >= 0;i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int comb(int n, int m){
    if(m > n or m < 0) return 0;
    return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int mul(int a, int b){
    ll res = 1LL * a * b;
    if(res >= mod)
        res %= mod;
    return res;
}

int F(int r, int n){
    int &ret = f[r][n];
    if(ret != -1){
        return ret;
    }
    if(r == 0){
        if(n == 0)
            return ret=1;
        return ret=2;
    }else{
        ret = 0;
        for(int i = 0;i <= n;i++){
            int tmp = comb(n - i + r - 1, r - 1); 
            add(ret, tmp);
            if(i > 0)
                add(ret, tmp);
        }
        return ret;
    }
}

void solve(int r, int n){
    int ans = 1;
    for(auto p : pdiv[n]){
        ll j = 1;
        int cnt = 0;
        while((n % (j * p)) == 0){
            j *= p;
            cnt++;
        }
        ans = mul(ans, F(r, cnt));
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pre_comb();
    init();
    memset(f, -1, sizeof(f));
    cin >> q;
    while(q--){
        cin >> r >> n;
        solve(r, n);
    }
    return 0;
}