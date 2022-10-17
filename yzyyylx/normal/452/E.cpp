#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 300100
#define M 1000000007
using namespace std;

ll n=N,last,tt,num[N<<1],sz[N];
char str[N];
struct Node
{
	ll to[28],cs[4],pa,len,cj;
	Node()
	{
		pa=-1;
		memset(to,-1,sizeof(to));
	}
} node[N<<1];

inline void add(int u,int v)
{
//	cout<<"           "<<u<<" "<<tt<<endl;
	int np=++tt,p=last,nq,q;
	node[np].cs[v]=1;
	last=np;
	node[np].len=node[p].len+1;
	for(; p!=-1&&node[p].to[u]==-1; p=node[p].pa) node[p].to[u]=np;
	if(p==-1)
	{
		node[np].pa=0;
	}
	else
	{
		q=node[p].to[u];
		if(node[q].len==node[p].len+1)
		{
			node[np].pa=q;
		}
		else
		{
			nq=++tt;
			node[nq].pa=node[q].pa;
			memcpy(node[nq].to,node[q].to,sizeof(node[q].to));
			node[nq].len=node[p].len+1;
			node[q].pa=node[np].pa=nq;
			for(; p!=-1&&node[p].to[u]==q; p=node[p].pa) node[p].to[u]=nq;
		}
	}
}

inline bool cmp(int u,int v)
{
	return node[u].len>node[v].len;
}

inline ll lb(ll u)
{
	return u&(-u);
}
inline void ad(ll u,ll v)
{
	for(; u<=tt; u+=lb(u)) sz[u]=(sz[u]+v+M)%M;
}
inline ll ask(ll u)
{
	ll res=0;
	for(; u; u-=lb(u)) res=(res+sz[u]+M)%M;
	return res;
}

int main()
{
//	cout<<(char)('a'+27);
	ll i,j,p,q,t;
	for(i=1; i<=3; i++)
	{
		scanf("%s",str+1);
		t=strlen(str+1);
		n=min(n,t);
		for(j=1; j<=t; j++) add(str[j]-'a',i);
		if(i<3) add(25+i,0);
	}
//	cout<<tt;return 0;
	for(i=1; i<=tt; i++) num[i]=i;
	sort(num+1,num+tt+1,cmp);
	for(i=1; i<=tt; i++)
	{
		for(j=1; j<=3; j++) node[node[num[i]].pa].cs[j]=(node[node[num[i]].pa].cs[j]+node[num[i]].cs[j])%M;
		t=node[num[i]].cs[1]*node[num[i]].cs[2]%M*node[num[i]].cs[3]%M;
//		cout<<node[num[i]].len<<" "<<t<<endl;
		ad(node[node[num[i]].pa].len+1,t),ad(node[num[i]].len+1,-t);
	}
	for(i=1; i<=n; i++)
	{
		printf("%lld ",ask(i));
	}
}