#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1001000
using namespace std;

ll n,m,last,tt,num[N<<1];
char str[N];
struct Node
{
	ll to[26],pa,vis,len,cs;
	Node()
	{
		memset(to,-1,sizeof(to));
		pa=-1;
	}
}node[N<<1];

inline void add(ll u)
{
	ll p=last,np=++tt,q,nq;
	node[np].len=node[p].len+1;
	for(;p!=-1&&node[p].to[u]==-1;p=node[p].pa) node[p].to[u]=np;
	last=np;
	node[np].cs=1;
//	cout<<node[np].len<<" ";
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
			for(;p!=-1&&node[p].to[u]==q;p=node[p].pa) node[p].to[u]=nq;
		}
	}
}

inline ll find(ll v)
{
	ll res=0,now=0,l=0,i,k,u;
	for(i=1;i<=n*2;i++)
	{
		u=str[i]-'a';
		for(;now&&node[now].to[u]==-1;now=node[now].pa,l=node[now].len);
		if(node[now].to[u]!=-1) now=node[now].to[u],l++;
		if(l>=n)
		{
			for(k=now;k&&n<=node[node[k].pa].len;k=node[k].pa);
			if(node[k].vis!=v)
			{
				node[k].vis=v;
				res+=node[k].cs;
			}
		}
	}
	return res;
}

inline bool cmp(ll u,ll v)
{
	return node[u].len>node[v].len;
}

int main()
{
	ll i,j,t;
	scanf("%s",str+1);
	for(i=1,t=strlen(str+1);i<=t;i++)
	{
		add(str[i]-'a');
	}
	for(i=1;i<=tt;i++) num[i]=i;
	sort(num+1,num+tt+1,cmp);
	for(i=1;i<=tt;i++)
	{
//		cout<<node[num[i]].len<<" "<<node[num[i]].pa<<endl;
		node[node[num[i]].pa].cs+=node[num[i]].cs;
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		for(j=1;j<=n;j++) str[j+n]=str[j];
		printf("%lld\n",find(i));
	}
}