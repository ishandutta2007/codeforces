#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=505;
int n,k,m,a[maxn];
inline void init()
{
	
}
inline PII query(vector<int>&vec)
{
	printf("? ");
	FOR(i,0,k-1)printf("%d ",vec[i]);
	printf("\n");
	fflush(stdout);
	PII ret;
	scanf("%d%d",&ret.first,&ret.second);
	return ret;
//	vector<int>v;
//	FOR(i,0,k-1)v.pb(a[vec[i]]);
//	sort(v.begin(),v.end());
//	PII ret;ret.second=v[m-1];
//	FOR(i,0,k-1)if(a[vec[i]]==v[m-1])ret.first=vec[i];
//	return ret;
}
inline void report(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
inline void input()
{
	scanf("%d%d",&n,&k);
//	cin>>m;
//	FOR(i,1,n)cin>>a[i];
}
map<int,int>mp;
inline void solve()
{
	FOR(i,1,k+1)
	{
		vector<int>vec;
		FOR(j,1,k+1)if(i!=j)vec.pb(j);
		PII now=query(vec);
		mp[now.second]++;
	}
	auto x=mp.end();x--;
	report((*x).second);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///