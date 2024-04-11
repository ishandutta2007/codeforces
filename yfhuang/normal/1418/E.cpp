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

const int maxn = 2e5 + 5;

int n, m;
int d[maxn];

struct shield{
    int dur;
    int def;
    int id;
    shield(int _dur=0, int _def=0, int _id=0): dur(_dur), def(_def), id(_id){}
    bool operator < (const shield & rhs) const{
        return def < rhs.def;
    }
}s[maxn];

const int mod = 998244353;

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

int ans[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ll sum = 0; 
    for(int i = 1;i <= n;i++){
        cin >> d[i];
        sum += d[i];
    }
    sort(d + 1, d + 1 + n);
    for(int i = 1;i <= m;i++){
        cin >> s[i].dur >> s[i].def;
        s[i].id = i;
    }
    sort(s + 1, s + 1 + m);
    ll pre = 0;
    int j = 0;
    for(int i = 1;i <= m;i++){
        while(j < n and d[j + 1] < s[i].def){
            pre += d[++j];
        }
        ll suf = sum - pre;
        ll sum1 = pre % mod;
        ll sum2 = suf % mod;
        if(s[i].dur > n - j or j == n){
            ans[s[i].id] = 0; 
        }else{
            int inv1 = qpow(n - j, mod - 2);
            int inv2 = qpow(n - j + 1, mod - 2);
            ans[s[i].id] = (1LL * inv1 * sum2 % mod * (n - j - s[i].dur) % mod + 1LL * inv2 * sum1 % mod * (n - j + 1 - s[i].dur) % mod) % mod; 
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << endl;
    }
    return 0;
}