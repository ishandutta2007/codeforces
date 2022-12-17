#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define A(x) ((x)%mod)
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5;
int fa[maxn],a[maxn],n;
inline void init()
{

}
inline int get(int x){if(x==fa[x])return x;else return fa[x]=get(fa[x]);}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),fa[i]=i;
	FOR(i,1,n)
	{
		int x=get(i),y=get(a[i]);
		if(x!=y)fa[x]=y;
	}
}
int vis[maxn];
int cnt=0;
vector<pair<int,int> >answer;
inline void solve()
{
	FOR(i,1,n)vis[get(i)]++;
	FOR(i,1,n)if(vis[i]>=1)cnt++;
	bool judge=0;
	while(cnt%2==1)
	{
		int pos=0;
		FOR(i,1,n)
		{
			if(vis[i]>=3||vis[i]==1)
			{
				pos=i;
				break;
			}
		}
		if(vis[pos]==1){vis[pos]=0;break;}
		if(pos==0)
		{
			judge=1;
			break;
		}
		vis[pos]=0;
		vector<int>vec;
		int now=pos;
		while(1)
		{
			vec.pb(now);
			now=a[now];
			if(now==pos)break;
		}
		answer.pb({vec[0],vec[1]});
		FOR(i,2,sz(vec)-2)answer.pb({vec[0],vec[i]});
		answer.pb({vec.back(),vec[1]});
		answer.pb({vec.back(),vec[0]});
		answer.pb({vec[0],vec[1]});
		cnt--;
		break;
	}
	vector<int>vec;
	FOR(i,1,n)if(vis[i]>=1)vec.pb(i);
	for(int i=0;i<sz(vec);i+=2)
	{
		int j=i+1;if(j>=sz(vec))break;
		vector<int>v1,v2;
		int val1=vec[i],val2=vec[j];
		int temp1=val1,temp2=val2;
		while(1)
		{
			v1.pb(val1);
			val1=a[val1];
			if(val1==temp1)break;
		}
		while(1)
		{
			v2.pb(val2);
			val2=a[val2];
			if(val2==temp2)break;
		}
		answer.pb({v1[0],v2[0]});
		FOR(i,1,sz(v2)-1)answer.pb({v1[0],v2[i]});
		FOR(i,1,sz(v1)-1)answer.pb({v1[i],v2[0]});
		answer.pb({v1[0],v2[0]});
	}
	if(judge)
	{
		int i=1;
		vector<int>v1;
		int val1=vec.back(),temp1=val1;
		while(1)
		{
			v1.pb(val1);
			val1=a[val1];
			if(val1==temp1)break;
		}
		while(i==v1[0]||i==v1[1])i++;
		answer.pb({v1[1],i});
		answer.pb({i,v1[0]});
		answer.pb({v1[1],i});
	}
	printf("%d\n",sz(answer));
	for(auto x:answer)printf("%d %d\n",x.first,x.second);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}