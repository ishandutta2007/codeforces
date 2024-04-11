//#pragma GCC optimize("Ofast")
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
int n;
char s[(1<<21)+5]; 
ll a[(1<<21)+5],b[(1<<21)+5],c[(1<<21)+5];
inline void FWT(ll *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)a[i+j+l]=(a[i+j+l]+a[i+j]);
		}
	}
}
inline void IFWT(ll *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)a[i+j+l]=(a[i+j+l]-a[i+j]);
		}
	}
}
inline void input()
{
	n=gi();
	scanf("%s",s);
	FOR(i,0,(1<<n)-1)a[i]=s[i]-'0',a[i]<<=(__builtin_popcount(i)<<1);
	scanf("%s",s);
	FOR(i,0,(1<<n)-1)b[i]=s[i]-'0',b[i]<<=(__builtin_popcount(i)<<1);
}
inline void solve()
{
	FWT(a,n),FWT(b,n);
	FOR(i,0,(1<<n)-1)c[i]=a[i]*b[i];
	IFWT(c,n);
	FOR(i,0,(1<<n)-1)printf("%lld",c[i]>>(__builtin_popcount(i)<<1)&3);
}
int main()
{
	input();
	solve();
	return 0;
}