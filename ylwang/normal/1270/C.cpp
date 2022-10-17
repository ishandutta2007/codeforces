#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define MAXN
#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 1 << 30;
const int p = 1000000009;
int lowbit(int x){ return x & (-x);}
int fast_power(int a, int b){ int x; for(x = 1; b; b >>= 1){ if(b & 1) x = 1ll * x * a % p; a = 1ll * a * a % p;} return x % p;}

int main(){
    int t;
    scanf("%d", &t);
    rep(times, 1, t){
        int n;
        scanf("%d", &n);
        ll s1 = 0, s2 = 0;
        rep(i, 1, n){
            ll x;
            scanf("%lld", &x);
            s1 += x;
            s2 ^= x;
        }
        s2 <<= 1;
        ll ans = 0;
        for(int i = 0; s1 != s2; i++){
            if((s1 & 1) ^ (s2 & 1)){
                s1 += 1;
                s2 ^= 2;
                ans += 1ll << i;
            }
            s1 >>= 1;
            s2 >>= 1;
        }
        printf("1\n%lld\n", ans);
    }
    return 0;
}