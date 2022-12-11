#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
ll p=1000000007;
struct graph
{
	int h[200010];
	int v[400010];
	int w[400010];
	int t[400010];
	int n;
	graph()
	{
		memset(h,0,sizeof h);
		n=0;
	}
	void add(int x,int y,int z)
	{
		n++;
		v[n]=y;
		w[n]=z;
		t[n]=h[x];
		h[x]=n;
	}
};
graph g,g2;
int f[200010][20];
int d[200010];
int st[200010];
int ti;
void dfs(int x,int fa,int dep)
{
	f[x][0]=fa;
	d[x]=dep;
	st[x]=++ti;
	int i;
	for(i=1;i<=19;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(i=g.h[x];i;i=g.t[i])
		if(g.v[i]!=fa)
			dfs(g.v[i],x,dep+1);
}
int getlca(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	int i;
	for(i=19;i>=0;i--)
		if(d[f[x][i]]>=d[y])
			x=f[x][i];
	if(x==y)
		return x;
	for(i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
ll phi[200010];
int b[200010];
int pri[100010];
int cnt;
ll inv[200010];
void init(int n)
{
	int i,j;
	inv[0]=inv[1]=1;
	for(i=2;i<=n;i++)
		inv[i]=-(p/i)*inv[p%i]%p;
	phi[1]=1;
	cnt=0;
	for(i=2;i<=n;i++)
	{
		if(!b[i])
		{
			pri[++cnt]=i;
			phi[i]=i-1;
		}
		for(j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			b[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*phi[pri[j]];
		}
	}
}
ll a[200010];
ll s[200010];
int c[200010];
int c1[200010];
int ct;
int n;
int stack[200010];
int top;
int cmp(int a,int b)
{
	return st[a]<st[b];
}
ll s1[200010];
ll s2[200010];
ll sum;
void add(int x,int y)//f[x]=y
{
	ll s3=(s1[x]+(d[x]-d[y])*s2[x])%p;
	sum=(sum+s3*s2[y]+s1[y]*s2[x])%p;
	s1[y]=(s1[y]+s3)%p;
	s2[y]=(s2[y]+s2[x])%p;
}
ll solve(int x)
{
	sum=0;
	ct=top=0;
	int i;
	for(i=x;i<=n;i+=x)
		c1[++ct]=c[i];
	sort(c1+1,c1+ct+1,cmp);
	int rt=getlca(c1[1],c1[ct]);
	if(rt!=c1[1])
	{
		stack[++top]=rt;
		s1[rt]=s2[rt]=0;
	}
	for(i=1;i<=ct;i++)
	{
		 if(i>=2)
		 {
		 	int lca=getlca(c1[i],c1[i-1]);
		 	while(d[stack[top]]>d[lca])
		 		if(d[stack[top-1]]<d[lca])
		 		{
		 			s1[lca]=s2[lca]=0;
		 			add(stack[top],lca);
		 			stack[top]=lca;
		 		}
		 		else
		 		{
		 			add(stack[top],stack[top-1]);
		 			top--;
		 		}
		 }
		 stack[++top]=c1[i];
		 s1[c1[i]]=0;
		 s2[c1[i]]=phi[a[c1[i]]];
	}
	while(top>1)
	{
		add(stack[top],stack[top-1]);
		top--;
	}
	return sum*2%p;
}
int main()
{
	scanf("%d",&n);
	init(n);
	int i,x,y,j;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		c[a[i]]=i;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y,0);
		g.add(y,x,0);
	}
	dfs(1,0,1);
	for(i=1;i<=n;i++)
		s[i]=solve(i);
	ll ans=0;
	for(i=n;i>=1;i--)
	{
		for(j=i+i;j<=n;j+=i)
			s[i]-=s[j];
		ans=(ans+s[i]*i%p*inv[phi[i]]%p)%p;
	}
	ans=ans*inv[n]%p*inv[n-1]%p;
	ans=(ans+p)%p;
	printf("%I64d\n",ans);
	return 0;
}