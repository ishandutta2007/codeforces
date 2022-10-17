#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define Pair pair < int, int >
#define mkp make_pair
#define rint register int
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define Foe(i, u) for(register int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
#define ull unsigned long long
//#define int long long
const int P = 998244353;
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 1e4 + 5;
int n, m, k, a[MAXN], b[MAXN]; 
int c[MAXN], tot = 0, dist[25][25];
 
int dis[MAXN];
void bfs(int id, int u) {
    queue < int > q; q.push(u);
    For(i, 1, n) dis[i] = INF; dis[u] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        For(i, 1, m) {
            int v = u - b[i];
            if(v > 0 && dis[v] == INF)
                dis[v] = dis[u] + 1, q.push(v);
            v = u + b[i];
            if(v <= n && dis[v] == INF)
                dis[v] = dis[u] + 1, q.push(v);
        }
    }
    For(i, 0, tot-1)
        dist[id][i] = dis[c[i]];
     
}
int dp[1<<22];
signed main()
{
//  file("password");
    cin >> n >> k >> m;
    For(i, 1, k) a[read()] = 1;
	n++;
    For(i, 1, m) b[i] = read();
    foR(i, n, 1) {
        a[i] ^= a[i-1];
        if(a[i]) c[tot++] = i;
    }
    sort(c, c + tot);   
//  For(i, 0, tot-1) cout << c[i] << endl;
    For(i, 0, tot - 1)
        bfs(i, c[i]);
    int maxi = (1<<tot)-1;
    For(i, 0, maxi) dp[i] = INF; dp[0] = 0;
//  For(i, 0, tot-1) {
//      For(j, 0, tot-1) {
//          printf("dist[%d][%d] = %d\n", i, j, dist[i][j]);
//      }
//  }
    For(st, 0, maxi-1) {
        int pos = 0;
        for(; pos < tot; pos++)
            if(((st >> pos) & 1) == 0) break;
        For(i, 0, tot-1) {
            if(((st >> i) & 1) == 0 && pos != i) 
			    ckmin(dp[st^(1<<pos)^(1<<i)], dp[st] + dist[i][pos]);
        }
    }
    if(dp[maxi] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dp[maxi]);
    }
    return 0;
} 
/*
20 5 3
1 16 19 11 20 
20 20 1 

*/