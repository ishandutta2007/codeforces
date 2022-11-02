#include<iostream>
#include<cstdio>
using namespace std;
const int N=101000,V=2000200,P=150000/*148933*/,L=0,R=1;
const int Query=1,Change=2;
struct node
{
	int sum,s[2];
}t[N*160]={};
int n,q,a[N]={},tot,prime[P]={},ptot=0,minp[V]={},root[P]={};
int last[N]={},next[N+N]={},end[N+N]={},total_edge=0,rew[N]={};
int hson[N]={},top[N]={},size[N]={},w[N]={},f[N]={},totw=0;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	int v=2000000;
	bool d[V]={};
	for(int i=2;i<=v;++i)
	{
		if(!d[i])
			prime[++ptot]=i,minp[i]=ptot;
		for(int j=1;j<=ptot && i*prime[j]<=v;++j)
		{
			d[i*prime[j]]=true;
			minp[i*prime[j]]=j;
			if(i%prime[j]==0)
				break;
		}
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1,u=0,v=0;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
}
void dfs(int s)
{
	size[s]=1;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j!=f[s])
		{
			f[j]=s;
			dfs(j);
			size[s]+=size[j];
			if(size[j]>size[hson[s]])
				hson[s]=j;
		}
	}
}
void bfs(int s)
{
	bool mark[N]={};
	int q[N]={},head=0,tail=0;
	q[++tail]=s;
	while(head!=tail)
	{
		int s=q[++head];
		if(!mark[s])
		{
			top[s]=s;
			w[s]=++totw;
			rew[totw]=s;
			mark[s]=true;
			for(int p=hson[s];p;p=hson[p])
			{
				q[++tail]=p;
				mark[p]=true;
				w[p]=++totw;
				rew[totw]=p;
				top[p]=s;
			}
		}
		for(int i=last[s];i;i=next[i])
			if(!mark[end[i]])
				q[++tail]=end[i];
	}
}
void add(int &k,int pos,int v,int l,int r)
{
	if(k==0)
		k=++tot;
	t[k].sum+=v;
	//cout<<"k="<<k<<" pos="<<pos<<" v="<<v<<" l="<<l<<" r="<<r<<endl;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(pos<=mid)
		add(t[k].s[L],pos,v,l,mid);
	else
		add(t[k].s[R],pos,v,mid+1,r);
}
inline void add_pos(int p,int v)
{
	int x=a[p],l=0;
	//cout<<"x="<<x<<endl;
	while(x!=1)
	{
		if(minp[x]!=l)
		{
			l=minp[x];
			//cout<<"minp[x]="<<l<<endl;
			add(root[l],w[p],v,1,n);
		}
		x/=prime[l];
	}
	//cout<<"-----------------"<<endl;
}
void Heavy_light_decomposition()
{
	dfs(1);
	bfs(1);
	for(int i=1;i<=n;++i)
		add_pos(i,1);
}
int find(int &k,int l_,int r_,const int &l,const int &r)
{
	//cout<<"k="<<k<<" l_="<<l_<<" r_="<<r_<<" l="<<l<<" r="<<r<<endl;
	if(t[k].sum==0)
		return 0;
	if(l>r_ || r<l_)
		return 0;
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	if(int p=find(t[k].s[R],l_,r_,mid+1,r))
		return p;
	else
		return find(t[k].s[L],l_,r_,l,mid);
}
inline int find_pos(int p,int l,int r)
{
	int x=a[p],last=0,ans=0;
	//cout<<"x="<<x<<endl;
	while(x!=1)
	{
		if(minp[x]!=last)
		{
			last=minp[x];
			//cout<<"minp[x]="<<last<<" l="<<l<<" r="<<r<<endl;
			ans=max(ans,find(root[last],l,r,1,n));
		}
		x/=prime[last];
	}
	return rew[ans];
}
void work()
{
	int type,u,v,w;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&type);
		if(type==Query)
		{
			scanf("%d",&u);
			int now=u;
			u=f[u];
			//cout<<"u="<<u<<endl;
			int ans=-1;
			while(u)
			{
				int tu=top[u];
				//cout<<"u="<<u<<" tu="<<tu<<endl;
				if(int tmp=find_pos(now,::w[tu],::w[u]))
				{
					ans=tmp;
					break;
				}
				u=f[tu];
			}
			printf("%d\n",ans);
		}
		if(type==Change)
		{
			scanf("%d%d",&v,&w);
			add_pos(v,-1);
			a[v]=w;
			add_pos(v,1);
		}
	}
}
int main()
{	
	init();
	Heavy_light_decomposition();
	work();
	return 0;
}