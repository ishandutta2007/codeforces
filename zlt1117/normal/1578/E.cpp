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
int n,m;
string s[maxn];
int b[maxn];
inline bool cmp (const int &a,const int &b)
{
	FOR(i,0,m-1)
	{
		if(s[a][i]==s[b][i])continue;
		if(i&1)return s[a][i]>s[b][i];
		else return s[a][i]<s[b][i];
	}
}
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)cin>>s[i],b[i]=i;
}
inline void solve()
{
	sort(b+1,b+n+1,cmp);
	FOR(i,1,n)printf("%d ",b[i]);
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