#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=505;
int a[maxn],b[maxn],n;
map<int,int>cnt;
inline void init()
{
	cnt.clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),cnt[a[i]]++;
}
inline void solve()
{
	for(auto x:cnt)if(x.second&1)return puts("-1"),void();
	int now=0,ends=n;
	vector<pair<int,int>>answer;
	vector<int>poi;
	while(ends)
	{
		int p=2;
		while(a[p]!=a[1]&&p<=n)p++;
		FOR(j,2,p-1)answer.pb({now+p+j-2,a[j]});
		now+=2*p-2;
		poi.pb((p-1)*2);
		int t=0;
		for(int j=p-1;j>=2;--j)b[++t]=a[j];
		FOR(j,p+1,ends)b[++t]=a[j];
		ends=t;
		FOR(j,1,ends)a[j]=b[j];
	}
	printf("%d\n",sz(answer));
	for(auto x:answer)printf("%d %d\n",x.first,x.second);
	printf("%d\n",sz(poi));
	for(int x:poi)printf("%d ",x);
	puts(""); 
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}