#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

inline LL read()
{
    LL x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define MK(a,b) make_pair(a,b)

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-8;
const int INF=(int) 0x3f3f3f3f;
const int SINF=(int) ~0U>>1;
const double DINF=(double) 1e50;
const int mod=(int) 1000000007;
const int maxm=(int) 100000+20;
const int maxn=(int) 100000+20;

struct adjs
{
    int to,next;
}ad[maxm<<1];
int head[maxn],adcnt;

inline void add_edge(int a,int b)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    head[a]=adcnt++;
}

int n,m,k;
int dp[2][maxn];
bool vis[maxn], zoomba[maxn];

void dfs(int *dp,int now) {
    vis[now] = true;
    for(int i = head[now]; i != -1; i = ad[i].next) {
        int& v = ad[i].to;
        if(vis[v]) continue;
        dfs(dp, v);
        if(dp[v] >= 0) dp[now] = max(dp[now], dp[v] + 1);
    }
}

void dfs2(int now, int last) {
    vis[now] = true;
    int max1 = -1, max2 = -3;
    if(last != -1 && dp[1][last] >= 0) dp[1][now] = max(dp[1][now], dp[1][last] + 1);
    for(int i = head[now]; i != -1; i = ad[i].next) {
        int& v = ad[i].to;
        if(vis[v]) continue;
        if(dp[0][v] < 0) continue;
        if(dp[0][v] > max1) {
            if(max1 >= 0) max2 = max1;
            max1 = dp[0][v];
        }
        else if(dp[0][v] > max2) max2 = dp[0][v];
    }
    for(int i = head[now]; i != -1; i = ad[i].next) {
        int& v = ad[i].to;
        if(vis[v]) continue;
        if(dp[0][v] == max1) dp[1][v] = max(dp[1][v], max2 + 2);
        else dp[1][v] = max(dp[1][v], max1 + 2);
    }
    for(int i = head[now]; i != -1; i = ad[i].next) {
        int& v = ad[i].to;
        if(!vis[v]) dfs2(v, now);
    }
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        adcnt=0;
        memset(head,-1,sizeof(head));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            int t=read();
            dp[0][t] = 0;
            dp[1][t] = 0;
        }
        for(int i=1;i<n;i++)
        {
            int a=read(),b=read();
            add_edge(a,b);
            add_edge(b,a);
        }
        memset(vis, 0, sizeof vis);
        dfs(dp[0], 1);
        memset(vis, 0, sizeof vis);
        dfs2(1, -1);
        int Ans = 0;
        for(int i = 1; i <= n; ++i)
            if(max(dp[0][i], dp[1][i]) <= k) ++Ans;
        cout << Ans << endl;
    }
    return 0;
}