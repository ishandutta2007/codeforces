#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 5001000
#define M 100100
#define MN 
using namespace std;

int n,m,K,tt,bb,BB,top,ans,lt,dfn[N],low[N],sta[N],num[N],bj[M],cnt[N],first[N],dp[N],First[N];
bool use[N],ok[N],mm[M][60];
char str[60];
struct Bn
{
    int to,next;
}bn[N],Bn[N];

inline void add(int u,int v)
{
    bb++;
    bn[bb].to=v;
    bn[bb].next=first[u];
    first[u]=bb;
}

inline void Add(int u,int v)
{
    BB++;
    Bn[BB].to=v;
    Bn[BB].next=First[u];
    First[u]=BB;
}

void dfs(int now)
{
    int p,q;
    dfn[now]=low[now]=++tt;
    use[now]=1;
    sta[++top]=now;
    for(p=First[now];p!=-1;p=Bn[p].next)
    {
	int t=Bn[p].to;
	if(!dfn[t])
        {
            dfs(t);
            low[now]=min(low[now],low[t]);
        }
        else if(use[t])
        {
            low[now]=min(low[now],dfn[t]);
        }
    }
    if(low[now]==dfn[now])
    {
        num[now]=++lt;
        use[now]=0;
	int t=now;
	if(mm[t%n][t/n]&&bj[t%n]!=lt) cnt[lt]++,bj[t%n]=lt;
	for(;sta[top]!=now;top--)
	{
	    int t=sta[top];
	    if(mm[t%n][t/n]&&bj[t%n]!=lt) cnt[lt]++,bj[t%n]=lt;
	    num[t]=lt;
	    use[t]=0;
	}
	top--;
    }
}

int main()
{
    memset(first,-1,sizeof(first));
    memset(First,-1,sizeof(First));
    int i,j,p,q,t;
    cin>>n>>m>>K;
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&p,&q);
	p--,q--;
	for(j=0;j<K;j++)
	{
	    Add(j*n+p,(j+1)%K*n+q);
	}
    }
    for(i=0;i<n;i++)
    {
	scanf("%s",str);
	for(j=0;j<K;j++)
	{
	    if(str[j]=='1') mm[i][j]=1;
	}
    }
    dfs(0);
    for(i=0;i<n*K;i++)
    {
	if(!num[i]) continue;
	for(p=First[i];p!=-1;p=Bn[p].next)
	{
	    int t=Bn[p].to;
	    if(!num[t] ||num[t]==num[i]) continue;
	    add(num[t],num[i]);
	}
    }
    for(i=1;i<=lt;i++)
    {
	dp[i]+=cnt[i];
	for(p=first[i];p!=-1;p=bn[p].next)
	{
	    q=bn[p].to;
	    dp[q]=max(dp[q],dp[i]);
	}
    }
    cout<<dp[lt];
}