#include<stdio.h>
#include<queue>
#include<stack>
#include<cstdlib>
int b[500002][3],a[500002],tot1=0,Next[500002],Last[500002],Len[500002],End[500002],tot2=0;
int tot=0,g[500002],i,j,k,x,y,maxx=1,n,h;
bool p[500002];
int c[500002][2];
std::stack<int>S[20000];
struct node{int p,dis;}r,t;
std::priority_queue<int>Q;int cnttt=0;
inline node dfs(int t,int f,int dis,int u)
{
	p[t]=1;
	node k={t,dis};int i=Last[t];
	while(i)
	{
		if(f!=End[i]&&Len[i]%u==0&&Len[i])
		{
			r=dfs(End[i],t,dis+1,u);
			if(r.dis>k.dis)k=r;
		}i=Next[i];
	}return k;
}
inline int gcd(int a,int b){while(b){a^=b^=a^=b;b%=a;}return a;}
main()
{
	//freopen("a.txt","r",stdin);
	for(int i=2;i<=300000;i++)
	{
		if(!p[i])g[++tot]=i;
		for(j=1;j<=tot&&i*g[j]<=300000;j++)
		{
			p[i*g[j]]=1;
			if(i%g[j]==0)break;
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);k=(k|(a[i]!=1));
		h=a[i];
		for(j=1;j<=tot&&g[j]<=448&&h>1;j++)
		{
			if(h%g[j]==0)
			{
				if(!p[g[j]])Q.push(-j);S[j].push(i);
				p[g[j]]=1;while(h%g[j]==0)h/=g[j];
			}
		}
		if(h!=1)
		{
			j=std::lower_bound(g,g+tot,h)-g;
			if(!p[g[j]])Q.push(-j);S[j].push(i);p[g[j]]=1;
		}
	}
	if(k==0){printf("0");return 0;}
	for(i=1;i<n;i++)
	{++tot1;
		scanf("%d%d",&b[tot1][1],&b[tot1][2]);
		b[tot1][0]=gcd(a[b[tot1][1]],a[b[tot1][2]]);
		if(b[tot1][0]!=1)
		{
			End[++tot2]=b[tot1][1];Next[tot2]=Last[b[tot1][2]];Last[b[tot1][2]]=tot2;Len[tot2]=b[tot1][0];
			End[++tot2]=b[tot1][2];Next[tot2]=Last[b[tot1][1]];Last[b[tot1][1]]=tot2;Len[tot2]=b[tot1][0];
		}
		else tot1--;
	}
	for(i=-Q.top();!Q.empty();i=(Q.empty()?20000000:-Q.top()))
	{
		if(g[i]>448)break;
		for(j=1;j<=n;j++)p[j]=0;
		while(!S[i].empty())
		{j=S[i].top();S[i].pop();
			if(!p[j])
			{
				t=dfs(j,0,1,g[i]);
				t=dfs(t.p,0,1,g[i]);
				if(t.dis>maxx)maxx=t.dis;
			}
		}
		Q.pop();
	}
	for(j=1;j<=n;j++)p[j]=0;
	for(;!Q.empty();i=(Q.empty()?20000000:-Q.top()))
	{
		if(g[i]>200000)break;
		while(!S[i].empty())
		{j=S[i].top();S[i].pop();
			if(!p[j])
			{
				t=dfs(j,0,1,g[i]);
				t=dfs(t.p,0,1,g[i]);
				if(t.dis>maxx)maxx=t.dis;
			}
		}
		Q.pop();
	}
	printf("%d",maxx);return 0;
}