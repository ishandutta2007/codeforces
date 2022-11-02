#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
#define For(i,j,k)	for(ll i=j;i<=k;i++)
#define Dow(i,j,k)	for(ll i=k;i>=j;i--)
using namespace std;
inline void read(ll &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
ll n,son[10000001][2],q[51],cnt[10000001],tot;
char c,s[51];
inline void add(char s[],ll k)
{
	memset(q,0,sizeof q);
	ll top=0;ll len=strlen(s+1);
	Dow(i,1,len)	q[++top]=(s[i]-'0')%2;	
	ll now=0;
	For(i,1,32)
	{
		if(!son[now][q[i]])	son[now][q[i]]=++tot;
		cnt[now]+=k;
		now=son[now][q[i]];
	}
	cnt[now]+=k;
}
inline ll ask(char s[])
{
	memset(q,0,sizeof q);
	ll top=0;ll len=strlen(s+1);
	Dow(i,1,len)	q[++top]=s[i]-'0';
	ll now=0;
	For(i,1,32)
	{
		if(!son[now][q[i]])	return 0;
		now=son[now][q[i]];
	}
	return cnt[now];
}
int main()
{
	scanf("%I64d",&n);
	For(i,1,n)
	{
		scanf("\n%c",&c);
		if(c=='+'){scanf("%s",s+1);add(s,1);}
		if(c=='-'){scanf("%s",s+1);add(s,-1);}
		if(c=='?'){scanf("%s",s+1);writeln(ask(s));}
	}
}