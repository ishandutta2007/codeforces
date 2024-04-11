#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;
int p[maxn], tot;
bool flg[maxn];
int mu[maxn];

void getMu(int n=100000) {
  mu[1] = 1;
  tot = 0;
  for (int i = 2; i <= n; ++i) {
    if (!flg[i]) p[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && i * p[j] <= n; ++j) {
      flg[i * p[j]] = 1;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = -mu[i];
    }
  }
}

const int mod = 998244353;

int m;
int a[maxn], freq[maxn];
ll cnt[maxn];
int sum[maxn];
int sqrsum[maxn];
int ijsum[maxn];
int val[maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void sub(int &a, int b){
    a -= b;
    if(a < 0)
        a += mod;
}

int qpow(int a, ll n){
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

void solve(int i){
    if(cnt[i] <= 1){
        val[i] = 0;
    }else{
        val[i] = 1LL * (cnt[i] - 1) % mod * qpow(2, cnt[i] - 2) % mod * sqrsum[i] % mod; 
        add(val[i], 1LL * cnt[i] % mod * qpow(2, cnt[i] - 2) % mod * qpow(2, mod - 2) % mod * ijsum[i] % mod);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    getMu();
    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> a[i] >> freq[i];
        //add(cnt[a[i]], freq[i]);
        cnt[a[i]] += freq[i];
        add(sum[a[i]], 1LL * a[i] * freq[i] % mod);
        add(sqrsum[a[i]], 1LL * a[i] * a[i] % mod * freq[i] % mod);
    }
    for(int i = 1;i <= 100000;i++){
        for(int j = i * 2;j <= 100000;j += i){
            //add(cnt[i], cnt[j]);
            cnt[i] += cnt[j];
            add(sum[i], sum[j]);
            add(sqrsum[i], sqrsum[j]);
        }
        ijsum[i] = 1LL * sum[i] * sum[i] % mod;
        sub(ijsum[i], sqrsum[i]);
    }
    int ans = 0;
    for(int i = 1;i <= 100000;i++){
        solve(i); 
        if(mu[i] == 1){
            add(ans, val[i]);
        }else if(mu[i] == -1){
            sub(ans, val[i]); 
        }
    }
    cout << ans << endl;
    return 0;
}