//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
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
const int maxn=3e5+5;
int a[maxn],b[maxn],n;
bool prime[maxn];
vector<int>vec;
inline void init()
{
	for(ll i=2;i<=maxn-5;++i)
	{
		if(prime[i])continue;
		vec.push_back(i);
		for(ll j=i;j<=(maxn-5);j+=i)prime[j]=1;
	}
}
inline void insert(int x)
{
	for(ll i=2;i*i<=x;++i)
	{
		while(x%i==0)x/=i;
	}
	if(x!=1)vec.push_back(x);
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
	insert(a[1]);insert(b[1]);
	for(auto x:vec)
	{
		bool ok=1;
		FOR(j,1,n)
		{
			if((a[j]%x!=0)&&(b[j]%x!=0)){ok=0;break;}
		}
		if(ok){printf("%d\n",x);return ;}
	}
	printf("-1\n");
}
inline void solve()
{

}
int main()
{
	init();
	input();
	solve();
	return 0;
}