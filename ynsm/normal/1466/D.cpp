#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, cnt[N];
pii a[N];

void solve(){
    scanf("%d", &n);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cnt[i] = 0;
        scanf("%d", &a[i].f);
        ans += a[i].f;
        a[i].s = i;
    }
    for(int i = 1; i < n; i++){
        int v, u;
        scanf("%d%d", &v, &u);
        cnt[v]++;
        cnt[u]++;
    }
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    printf("%lld ", ans);
    for(int i = 1; i <= n; i++){
        int j = a[i].s;
        while(cnt[j] > 1){
            ans += a[i].f;
            cnt[j]--;
            printf("%lld ", ans);
        }
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
}