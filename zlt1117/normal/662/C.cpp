#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
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
const int maxn=20;
int n,m;
ll a[(1<<21)+1],b[(1<<21)];
inline void FWT(ll *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				ll v1=a[i+j],v2=a[i+j+l];
				a[i+j]=(v1+v2),a[i+j+l]=(v1-v2);
			}
		}
	}
}
inline void IFWT(ll *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				ll v1=a[i+j],v2=a[i+j+l];
				a[i+j]=(v1+v2)/2,a[i+j+l]=(v1-v2)/2;
			}
		}
	}
}
char s[21][100005];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)scanf("%s",s[i]+1);
}
inline void solve()
{
	FOR(i,1,m)
	{
		int x=0;
		FOR(j,1,n)if(s[j][i]=='1')x+=(1<<(j-1));
		a[x]++;
	}
	FOR(i,0,(1<<n)-1)
	{
		b[i]=__builtin_popcount(i);
		b[i]=min(b[i],n-b[i]);
	}
	FWT(a,n),FWT(b,n);FOR(i,0,(1<<n)-1)a[i]=a[i]*b[i];
	IFWT(a,n);ll ans=1e9;
	FOR(i,0,(1<<n)-1)ans=min(ans,a[i]);
	printf("%lld\n",ans);
}
int main() 
{
	input();
	solve();
	return 0;
}