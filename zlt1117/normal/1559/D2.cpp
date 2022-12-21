#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
const int maxn=1e5+5;
priority_queue<pair<int,int>>pq;
set<int>row[maxn],col[maxn];
map<int,int>mp[maxn];
struct DSU
{
	static const int maxn=1e5+5;
	int fa[maxn];
	inline void init(int x)
	{
		FOR(i,1,x)fa[i]=i;
	}
	inline int get(int x)
	{
		if(x==fa[x])return x;
		return fa[x]=get(fa[x]);
	}
	inline void merge(int x,int y)
	{
		x=get(x),y=get(y);
		fa[x]=y;
	}
}dsu1,dsu2;
int n,u,v,m1,m2;
inline void input()
{
	n=gi(),m1=gi(),m2=gi();
	dsu1.init(n),dsu2.init(n);
	FOR(i,1,m1)
	{
		u=gi(),v=gi();
		dsu1.merge(u,v);
	}
	FOR(i,1,m2)
	{
		u=gi(),v=gi();
		dsu2.merge(u,v);
	}
	if(m1<m2)swap(m1,m2),swap(dsu1,dsu2);
	FOR(i,1,n)
	{
		u=dsu1.get(i),v=dsu2.get(i);
		mp[u][v]=i;
		row[u].insert(v),col[v].insert(u);
	}
	//FOR(i,1,n)printf("fa[%d]=%d\n",i,dsu1.get(i));
	FOR(i,1,n)if(dsu1.get(i)==i)pq.push({sz(row[i]),i});
}
inline void merge_row(int x,int y)
{
	//if(sz(row[x])<sz(row[y]))swap(x,y);
	for(int v:row[y])
	{
		mp[x][v]=mp[y][v];
		row[x].insert(v);
		col[v].erase(y);
		col[v].insert(x);
	}
}
inline void merge_col(int x,int y)
{
	//if(sz(col[x])<sz(col[y]))swap(x,y);
	for(int v:col[y])
	{
		mp[v][x]=mp[v][y];
		col[x].insert(v);
		row[v].erase(y);
		row[v].insert(x);
	}
}
inline void solve()
{
	vector<pair<int,int>>answer;
	while(pq.size()>1)
	{
		int a=pq.top().second;pq.pop();
		int b=pq.top().second;pq.pop();
		if(sz(row[a])<sz(row[b]))swap(a,b);
		int c=*row[a].begin(),d=*row[b].begin();
		if(c==d)c=*++row[a].begin();
		if(sz(row[a])==1&&sz(row[b])==1&&m1!=m2)assert(0);
		answer.pb({mp[a][c],mp[b][d]});
		merge_row(a,b);
		if(sz(col[c])<sz(col[d]))swap(c,d);
		merge_col(c,d);
		pq.push({sz(row[a]),a});
	}
	printf("%d\n",sz(answer));
	for(auto [x,y]:answer)printf("%d %d\n",x,y);
}
int main()
{
	input();
	solve();
	return 0;
}