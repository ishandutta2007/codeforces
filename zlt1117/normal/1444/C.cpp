#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=5e5+5;
int n,m,k,u,v,bel[maxn],tot,v1,v2,b[maxn];
map<PII,int>mp;
vector<PII>e[maxn];
vector<PII>temp1;
bool ok[maxn];
ll ans;
int fa[maxn],rev[maxn],dis[maxn],siz[maxn];///if it need to change the value or not(it refers to the value) 
///1 refers to it is odd otherwise it is even
///dis[x] refers to the distant to the root so that you can check if there is a odd circle or not
struct state
{
	int x,y,sizy;
	state(int xx=0,int yy=0,int ss=0){x=xx,y=yy,sizy=ss;}
};
stack<state>stk;
inline int getf(int x)
{
	if(fa[x]==x){dis[x]=0;return x;}
	int fath=getf(fa[x]);
	dis[x]=dis[fa[x]]^rev[x];
	return fath;
}
inline int merge(int x,int y)
{
	int f1=getf(x),f2=getf(y);
	if(f1!=f2)
	{
		if(siz[f1]<siz[f2])swap(f1,f2),swap(x,y);
		stk.push(state(f2,f1,siz[f1]));
		fa[f2]=f1;rev[f2]=dis[y]^dis[x]^1;///must be even
		siz[f1]+=siz[f2];
		return 2;///successful merge
	}
	else
	{
		if(dis[x]==dis[y])return 0;///wrong
		else return 1;///right
	}
}
inline void cancel()///delete the operations
{
	state x=stk.top();stk.pop();
	fa[x.x]=x.x,rev[x.x]=0,dis[x.x]=0,siz[x.y]=x.sizy;
}
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	FOR(i,1,n)bel[i]=gi();
	temp1.push_back(PII(0,0));
	FOR(i,1,m)
	{
		u=gi(),v=gi();
		if(bel[u]>bel[v])swap(u,v);
		if(bel[u]==bel[v])
		{
			int res=merge(u,v);
			if(res==0)ok[bel[u]]=1;
		}
		if(!mp.count(PII(bel[u],bel[v])))mp[PII(bel[u],bel[v])]=++tot,temp1.push_back(PII(bel[u],bel[v]));
		e[mp[PII(bel[u],bel[v])]].push_back(PII(u,v));
	}
}
inline void solve()
{
	int cnt=0;
	FOR(i,1,n)if(ok[i])cnt++;
	cnt=k-cnt;
	ans=cnt;ans=ans*(cnt-1);ans/=2;
	FOR(i,1,tot)
	{
		if(ok[temp1[i].first]||ok[temp1[i].second])continue;
		int cnt=0;
		for(auto x:e[i])
		{
			int u=x.first;
			int v=x.second;
			int res=merge(u,v);
			if(res==2)cnt++;
			else if(res==0){ans--;break;}
		}
		FOR(i,1,cnt)cancel();
	}
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}