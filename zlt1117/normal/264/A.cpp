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
const int maxn=1e6+5;
int id[maxn],n,now[maxn]; 
char s[maxn];
inline void init()
{

}
inline void input()
{
	scanf("%s",s+1);
}
inline void solve()
{
	n=strlen(s+1);
	int cnt=0;
	FOR(i,1,n)
	{
		if(s[i]=='l')id[i]=n-i+cnt+1;
		else id[i]=cnt+1,cnt++;
	}
	FOR(i,1,n)now[id[i]]=i;
	FOR(i,1,n)printf("%d\n",now[i]);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}