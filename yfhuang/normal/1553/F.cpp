#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 3e5 + 5;

int n;
int c[maxn];
ll s[maxn];
void add(int p, int d, ll v){
    for(int i = p;i < maxn;i += i & -i){
        c[i] += d;
        s[i] += v;
    } 
}
pair<int, ll> sum(int p){
    if(p < 0)
        return mp(0, 0);
    int res = 0;
    ll Sum = 0;
    for(int i = p;i > 0;i -= i& -i){
        res += c[i];
        Sum += s[i];
    }
    return mp(res, Sum);
}

ll bit[maxn];

void add(int p, ll v){
    for(int i = p;i < maxn;i += i & -i){
        bit[i] += v;
    }
}

ll sum1(int p){
    ll res = 0;
    for(int i = p;i > 0;i -= i & -i){
        res += bit[i];  
    }
    return res;
} 

int MAXA;

// a_i \mod a
ll solve1(int a){
    MAXA = max(MAXA, a);
    ll ret = 0;
     for(int i = 0; i * a <= MAXA;i++){
         int l = i * a;
         int r = min(MAXA, l + a - 1); 
         pair<int, ll> resr = sum(r);
         pair<int, ll> resl = sum(l - 1); 
         ll ss = resr.se - resl.se;
         int cc = resr.fi - resl.fi;
         ret += ss - 1LL * cc * l;  
    } 
    add(a, 1, a);
    return ret;
}

// a \mod a_i
ll solve2(int num, int a){
    int j;
    ll ret = 1LL * num * a - sum1(a);
    for(int i = 1;i * a < maxn;i++){
        add(i * a, a);
    }
    return ret;
}

int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    MAXA = 0;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        ans += solve1(a);
        ans += solve2(i - 1, a);
        cout << ans << ((i == n) ? '\n' : ' ');
    } 
    return 0;
}