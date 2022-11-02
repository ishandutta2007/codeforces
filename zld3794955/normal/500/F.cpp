#include<bits/stdc++.h>
using namespace std;
const int N=4040,P=10010,T=20020,V=4004;
struct thing
{
	int c,h,t;
}t[N]={};
struct state
{
	int t,f[V];
}empty={0,{}};
bool thing_cmp(const thing &t1,const thing &t2)
{
	return t1.t<t2.t;
}
int n,p,q;
vector<state> pre[T],suf[T];
void init()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&t[i].c,&t[i].h,&t[i].t);
	sort(t+1,t+n+1,thing_cmp);
}
void work()
{
	int l=0,r=0;
	state s={0,{}};
	for(int i=p;i<T;i+=p)
	{
		l=lower_bound(t+1,t+n+1,(thing){0,0,i-p+1},thing_cmp)-t;
		r=upper_bound(t+1,t+n+1,(thing){0,0,i},thing_cmp)-t-1;
		s.t=0;
		for(int k=0;k<V;++k)
			s.f[k]=0;
		for(int j=l;j<=r;++j)
		{
			s.t=t[j].t;
			for(int k=V-1;k>=t[j].c;--k)
				s.f[k]=max(s.f[k],s.f[k-t[j].c]+t[j].h);
			pre[i/p].push_back(s);
		}
		s.t=0;
		for(int k=0;k<V;++k)
			s.f[k]=0;
		for(int j=r;j>=l;--j)
		{
			s.t=t[j].t;
			for(int k=V-1;k>=t[j].c;--k)
				s.f[k]=max(s.f[k],s.f[k-t[j].c]+t[j].h);
			suf[i/p].push_back(s);
		}
	}
}
void query()
{
	scanf("%d",&q);
	for(int i=1,l=0,r=0,v=0;i<=q;++i)
	{
		scanf("%d%d",&r,&v);
		l=r-p+1;
		int b1=(l+p-1)/p,b2=(r+p)/p;
		state *s1=&empty,*s2=&empty;
		for(vector<state>::iterator it=suf[b1].begin();it!=suf[b1].end();++it)
			if(l<=it->t)
				s1=&(*it);
		for(vector<state>::iterator it=pre[b2].begin();it!=pre[b2].end();++it)
			if(it->t<=r)
				s2=&(*it);
		int ans=0;
		for(int j=0;j<=v;++j)
			ans=max(ans,s1->f[j] + s2->f[v-j]);
		printf("%d\n",ans);
	}
}
int main()
{
	init();
	work();
	query();
	return 0;
}