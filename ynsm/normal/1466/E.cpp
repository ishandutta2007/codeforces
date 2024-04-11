#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7, LOG = 60;
const ll INF = 1e18;

int n;
ll a[N], ans, cnt[LOG];
void solve(){
    
    for(int j = 0; j < LOG; j++)
        cnt[j] = 0;
    ans = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        for(int j = 0; j < LOG; j++)
            cnt[j] += ((a[i] >> j) & 1);
    }
    for(int i = 0; i < n; i++){
        ll A = 0, B = 0;
        for(int j = 0; j < LOG; j++){
            if((a[i] >> j) & 1){
                A += (1ll << j) % mod * cnt[j] % mod;
                B += (1ll << j) % mod * n % mod;
            }else{
                B += (1ll << j) % mod * cnt[j] % mod;
            }
        }
        A %= mod;
        B %= mod;
        ans += A * B % mod;
    }
    ans %= mod;
    printf("%lld\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
}