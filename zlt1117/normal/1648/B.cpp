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
const int maxn=2e6+5;
int a[maxn],n,C;
int sum[maxn];
inline void init()
{
	FOR(i,1,C*2)sum[i]=0;
}
inline void input()
{
	n=gi(),C=gi();
	FOR(i,1,n)a[i]=gi(),sum[a[i]]++;
	FOR(i,1,C*2)sum[i]+=sum[i-1];
}
inline void solve()
{
	FOR(i,1,C)
	{
		if(sum[i]-sum[i-1]==0)
		{
			for(int j=1;j*i<=C;++j)
			{
				if(sum[j]-sum[j-1])
				{
					if(sum[(i+1)*j-1]-sum[i*j-1]!=0)return puts("No"),void();
				}
			}
		}
	}
	puts("Yes");
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