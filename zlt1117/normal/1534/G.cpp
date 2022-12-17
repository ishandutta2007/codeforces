#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=8e5+5;
int n,x[maxn],y[maxn],id[maxn];
ll ans;
inline void input()
{
	n=gi();
	FOR(i,1,n)
	{
		int u=gi(),v=gi();
		x[i]=(u+v),y[i]=(u-v);
		id[i]=i;
	}
	sort(id+1,id+n+1,[](int i,int j){return x[i]==x[j]?y[i]<y[j]:x[i]<x[j];}); 
}
inline void solve()
{
	priority_queue<int>pl;
	priority_queue<int,vector<int>,greater<int>>pr;
	int now=0;
	//FOR(i,1,n+5)pl.push(0),pr.push(0);
	pl.push(y[id[1]]),pr.push(y[id[1]]);
	FOR(i,2,n)
	{
		now+=x[id[i]]-x[id[i-1]];
		int L=pl.top()-now,R=pr.top()+now;
		if(L<=y[id[i]]&&y[id[i]]<=R)pl.push(y[id[i]]+now),pr.push(y[id[i]]-now);
		else if(y[id[i]]<L)
		{
			ans+=L-y[id[i]];
			pl.push(y[id[i]]+now),pl.push(y[id[i]]+now);
			pl.pop();pr.push(L-now);
		}
		else
		{
			ans+=y[id[i]]-R;
			pr.push(y[id[i]]-now),pr.push(y[id[i]]-now);
			pr.pop(),pl.push(R+now);
		}
	}
	printf("%lld\n",ans/2);
}
int main()
{
	input();
	solve();
	return 0;
}