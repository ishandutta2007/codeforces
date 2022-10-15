#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
mt19937 rnd(0);
int Rand(int l,int r){uniform_int_distribution<>gen(l,r);return gen(rnd);}
const int maxn=1<<20;
const int inf=1e9;
int n,k,a[maxn];
int ans;
struct graph
{
	static const int maxn=16000;
	static const int maxm=16000;
	int s,t;
	int head[maxn],ver[maxm<<2],nxt[maxm<<2],val[maxm<<2],cost[maxm<<2],tot=1;
	void add(int x,int y,int z,int c){ver[++tot]=y;val[tot]=z;cost[tot]=c;nxt[tot]=head[x];head[x]=tot;}
	void link(int x,int y,int z,int c){add(x,y,z,c);add(y,x,0,-c);}
	map<int,int>num;
	int dis[maxn],pre[maxn],incf[maxn];bool in[maxn];
	bool spfa()
	{
		memset(dis,-0x3f,sizeof(int)*(num.size()+2));memset(pre,0,sizeof(int)*(num.size()+2));
		memset(incf,0,sizeof(int)*(num.size()+2));memset(in,0,sizeof(bool)*(num.size()+2));
		queue<int>q;
		dis[s]=0;q.push(s);incf[s]=inf;in[s]=1;
		while(!q.empty())
		{
			int x=q.front();in[x]=0;q.pop();
			for(int i=head[x];i;i=nxt[i])
			{
				if(val[i]&&dis[ver[i]]<dis[x]+cost[i])
				{
					dis[ver[i]]=dis[x]+cost[i];
					pre[ver[i]]=i;
					incf[ver[i]]=min(incf[x],val[i]);
					if(!in[ver[i]])q.push(ver[i]),in[ver[i]]=1;
				}
			}
		}
		return dis[t]>0;
	}
	void update()
	{
		int now=t;
		while(now!=s)
		{
			val[pre[now]]-=incf[t];
			val[pre[now]^1]+=incf[t];
			now=ver[pre[now]^1];
		}
		ans+=incf[t]*dis[t];
	}
	struct edge{int fr,to,val;bool operator <(const edge &x)const{return val<x.val;}}e[1<<25];int cnt;	
	void build()
	{
		s=0;t=1;
		for(int i=0;i<(1<<n);i++)
			if(__builtin_popcount(i)&1)
				for(int j=0;j<n;j++)e[++cnt]={i,i^(1<<j),a[i]+a[i^(1<<j)]};
		int to=max(1,cnt-(2*n-1)*(k-1));
		nth_element(e+1,e+to,e+cnt+1);
		for(int i=to;i<=cnt;i++)
		{
			if(!num[e[i].fr])num[e[i].fr]=num.size()+1;
			if(!num[e[i].to])num[e[i].to]=num.size()+1;
			link(num[e[i].fr],num[e[i].to],1,e[i].val);
		}
		for(int i=0;i<(1<<n);i++)
		{
			if(num.count(i))
			{
				if(__builtin_popcount(i)&1)link(s,num[i],1,0);
				else link(num[i],t,1,0);
			}
		}
	}
	void solve()
	{
		while(k--&&spfa())
		{
			if(dis[t]<0)break;
			update();
		}
	}
}o;
int main()
{
	n=read();k=read();generate_n(a,1<<n,read);
	o.build();
	o.solve();
	printf("%d\n",ans);
	return 0;
}