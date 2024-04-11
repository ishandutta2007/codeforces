#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, m, p[N], ans_cnt;
bool was[N], ans[N];
int pp(int v){
    return (p[v] == v ? v : p[v] = pp(p[v]));
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        p[i] = i;
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        if(k == 1){
            int v;
            scanf("%d", &v);
            v = pp(v);
            if(was[v])
                continue;
            was[v] = 1;
            ans[i] = 1;
            ans_cnt++;
        }else{
            int v, u;
            scanf("%d%d", &v, &u);
            v = pp(v);
            u = pp(u);
            if(v == u)
                continue;            
            if(was[v] && was[u])
                continue;
            p[v] = u;
            was[u] |= was[v];
            ans[i] = 1;
            ans_cnt++;
        }
    }
    ll cnt = 1;
    for(int i = 0; i < ans_cnt; i++)
        cnt = cnt * 2 % mod;
    printf("%lld %d\n", cnt, ans_cnt);
    for(int i = 0; i < n; i++)
        if(ans[i])
            printf("%d ", i + 1);
}