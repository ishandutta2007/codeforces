#include<bits/stdc++.h>
#define maxn 500050
using namespace std;

int n,a[maxn],b[maxn];

int sz,ls[maxn<<2],rs[maxn<<2];
int mp[maxn<<2],pos[maxn];

int deg[maxn<<2];
vector<int> G[maxn<<2];

int build(int l,int r)	{
	int id=++sz;
	ls[id]=rs[id]=mp[id]=0;
	if (l==r)
		mp[pos[l]=id]=l;
	else	{
		int mid=(l+r)>>1;
		ls[id]=build(l,mid);
		rs[id]=build(mid+1,r);
	}
//	cout<<l<<" "<<r<<":"<<id<<" "<<ls[id]<<" "<<rs[id]<<endl;
	return id;
}

void join(int u,int v)	{
	if (v)
//		cout<<u<<" -> "<<v<<endl,
		G[u].push_back(v),++deg[v];
}

void connect(int k,int l,int r,int a,int b,int u)	{
	if (l>r)	return ;
	if (a<=l&&r<=b)
		join(u,k);
	else	{
		int mid=(l+r)>>1;
		if (a<=mid)
			connect(ls[k],l,mid,a,b,u);
		if (b>mid)
			connect(rs[k],mid+1,r,a,b,u);
	}
}

void init()	{
	sz=0;
	
	scanf("%d",&n);
	build(1,n);
	for (int i=1;i<=sz;++i)
		G[i].clear(),deg[i]=0;
		
	for (int i=1;i<=sz;++i)
		join(i,ls[i]),join(i,rs[i]);
	for (int i=1;i<=n;++i)	{
		scanf("%d",a+i);
		if (!~a[i])	continue;
		connect(1,1,n,i+1,a[i]-1,pos[i]);
		if (a[i]<=n)
			join(pos[a[i]],pos[i]);
	}
}

bool vis[maxn<<2];
queue<int> q;

bool solve()	{
	for (int i=1;i<=sz;++i)	vis[i]=0;
	for (int i=1;i<=sz;++i)
		if (!deg[i])
			q.push(i);
	int N=n;
	while (!q.empty())	{
		int i=q.front();	q.pop();
		vis[i]=1;
		if (mp[i])	
//			cout<<"find:"<<mp[i]<<" "<<N<<endl,
			b[mp[i]]=N--;
		for (int j:G[i])	
			if (!--deg[j])
				q.push(j);
	}
	for (int i=1;i<=n;++i)
		if (!vis[pos[i]])
			return puts("-1"),0;
	for (int i=1;i<=n;++i)
		printf("%d%c",b[i]," \n"[i==n]);
	return 1;
}

int main()	{
	int T;
	scanf("%d",&T);
	while (T--)	{
		init();
		solve();
	}
	return 0;
}