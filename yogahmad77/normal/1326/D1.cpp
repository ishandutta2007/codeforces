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
typedef int (*func)(int, int);


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


const int mx = 1e6 + 10;

bool is_palindrome(string &ss){
    int n = sz(ss);
    for(int i = 0; i < n; i++)
        if(ss[i] != ss[n - i - 1])
            return false;
    return true;
}

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const long long BASE1 = 37;
const long long BASE2 = 41;
long long pang1[mx], pang2[mx], inv1[mx], inv2[mx];

int POW(long long a, int b, int mod){
    long long ret = 1;
    while(b > 0){
        if(b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

struct Hash{
    vector<long long> pref1, pref2;
    Hash(vector<int> ve){
        int n = sz(ve);
        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pref1[i] = (pref1[i - 1] + pang1[i] * ve[i - 1]) % MOD1;
            pref2[i] = (pref2[i - 1] + pang2[i] * ve[i - 1]) % MOD2;
        }
    }
    pair<long long, long long> get(int l, int r){
        r += 1;
        long long ret1 = (pref1[r] - pref1[l] + MOD1) % MOD1;
        long long ret2 = (pref2[r] - pref2[l] + MOD2) % MOD2;
        ret1 = ret1 * inv1[l] % MOD1;
        ret2 = ret2 * inv2[l] % MOD2;
        if(ret1 < 0) ret1 += MOD1;
        if(ret2 < 0) ret2 += MOD2;
        return {ret1, ret2};
    }  
};

void solve(){
    string ss;
    cin >> ss;
    int n = sz(ss);
    if(is_palindrome(ss)){
        cout << ss << '\n';
        return;
    }
    int l = 0, r = n - 1;
    while(ss[l] == ss[r]){
        l += 1;
        r -= 1;
    }
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) a[i] = ss[i] - 'a' + 1;
    b = a;
    reverse(ALL(b));
    Hash sa(a), du(b);
    int l1 = l;
    int l2 = l;
    int r1 = r;
    int r2 = r;
    for(int i = l; i < r; i++){
        auto x = sa.get(l, i);
        auto y = du.get(n - i - 1, n - l - 1);
        if(x == y){
            l2 = i;
        }
    }
    for(int i = r; i > l; i--){
        auto x = sa.get(i, r);
        auto y = du.get(n - r - 1, n - i - 1);
        if(x == y){
            r1 = i;
        }
    }
    string ans = "";
    if(l2 - l1 > r2 - r1){
        for(int i = 0; i < l; i++)
            ans += ss[i];
        for(int i = l1; i <= l2; i++)
            ans += ss[i];
        for(int i = r + 1; i < n; i++)
            ans += ss[i];
    }
    else{
        for(int i = 0; i < l; i++)
            ans += ss[i];
        for(int i = r1; i <= r2; i++)
            ans += ss[i];
        for(int i = r + 1; i < n; i++)
            ans += ss[i];
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pang1[0] = pang2[0] = 1;
    inv1[0] = inv2[0] = 1;
    inv1[1] = POW(BASE1, MOD1 - 2, MOD1);
    inv2[1] = POW(BASE2, MOD2 - 2, MOD2);
    for(int i = 1; i < mx; i++){
        pang1[i] = pang1[i - 1] * BASE1 % MOD1;
        pang2[i] = pang2[i - 1] * BASE2 % MOD2;
    }
    for(int i = 2; i < mx; i++){
        inv1[i] = inv1[i - 1] * inv1[1] % MOD1;
        inv2[i] = inv2[i - 1] * inv2[1] % MOD2;
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}