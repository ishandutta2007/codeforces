#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 100100
#define S 400
using namespace std;

int n,m,s,num[N],ck,ans;
P a,b;
struct Kuai
{
	int cnt[N],num[S<<1],size;
	inline void add(int u,int v)
	{
		int i;
		cnt[v]++,size++;
		for(i=size;i>u;i--) num[i]=num[i-1];
		num[u]=v;
	}
	inline void del(int u)
	{
		int i;
		cnt[num[u]]--,size--;
		for(i=u;i<=size;i++) num[i]=num[i+1];
	}
	inline int ask(int u,int v,int w)
	{
		int i,res=0;
		for(i=u;i<=v;i++) res+=(num[i]==w);
		return res;
	}
}ku[S];

inline void build()
{
	int i;
	for(i=1;i<=n;i++)
	{
		ku[(i-1)/s+1].add((i-1)%s+1,num[i]);
	}
}

inline void rb()
{
	int i,j,k=0;
	for(i=1;i<=ck;i++)
	{
		for(j=1;j<=ku[i].size;j++)
		{
			num[++k]=ku[i].num[j];
			ku[i].cnt[num[k]]=0;
		}
		ku[i].size=0;
	}
	build();
}

int main()
{
	int i,j,o,p,q,t,tmp;
	cin>>n;s=sqrt(n);ck=(n-1)/s+1;
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	build();
	cin>>m;
	for(i=1;i<=m;i++)
	{
		if(i%s==0) rb();
		scanf("%d%d%d",&o,&p,&q);
		p=(p+ans-1)%n+1;
		q=(q+ans-1)%n+1;
		if(p>q) swap(p,q);
		if(o==1)
		{
			if(p==q) continue;
			t=0;
			for(j=1;;j++)
			{
				if(t+ku[j].size>=q) break;
				t+=ku[j].size;
			}
			tmp=ku[j].num[q-t];
			ku[j].del(q-t);
			
			t=0;
			for(j=1;;j++)
			{
				if(t+ku[j].size>=p) break;
				t+=ku[j].size;
			}
			ku[j].add(p-t,tmp);
		}
		else
		{
			scanf("%d",&o);
			o=(o+ans-1)%n+1;
			ans=0;
			t=0;
			for(j=1;;j++)
			{
				if(t+ku[j].size>=p) break;
				t+=ku[j].size;
			}
			a=mp(j,p-t);
			
			for(;;j++)
			{
				if(t+ku[j].size>=q) break;
				t+=ku[j].size;
			}
			b=mp(j,q-t);
			
			if(a.fi==b.fi) ans=ku[a.fi].ask(a.se,b.se,o);
			else
			{
				for(j=a.fi+1;j<b.fi;j++) ans+=ku[j].cnt[o];
				ans+=ku[a.fi].ask(a.se,ku[a.fi].size,o);
				ans+=ku[b.fi].ask(1,b.se,o);
			}
			printf("%d\n",ans);
		}
	}
}