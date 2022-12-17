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
const int M=3e6,maxn=3e6+5;
char s[maxn],t[maxn];
int n,len,nxt[maxn];
inline int get(int x){if(x==nxt[x])return x;return nxt[x]=get(nxt[x]);}
inline void init()
{

}
inline void input()
{
	FOR(i,1,M)nxt[i]=i;
	n=gi();
}
inline void insert(char *s,int n,int x)
{
	int now=x;
	len=max(len,n+x-1);
	while(1)
	{
		now=get(now);
		if(now-x+1>n)return ;
		nxt[now]=get(nxt[now+1]);
		t[now]=s[now-x+1];
		now++;
	}
}
inline void solve()
{
	FOR(i,1,n)
	{
		scanf("%s",s+1);
		int k=gi();int l=strlen(s+1);
		FOR(j,1,k)
		{
			int x=gi();
			insert(s,l,x);
		}
	}
	FOR(i,1,len)if(t[i]==0)t[i]='a';
	printf("%s\n",t+1);
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