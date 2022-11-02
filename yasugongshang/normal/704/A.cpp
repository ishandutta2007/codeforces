#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
#define For(i,j,k)	for(int i=j;i<=k;i++)
#define Dow(i,j,k) 	for(int i=k;i>=j;i--)
using namespace std;
inline void read(int &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int n,q,bj[10000001],poi[10000001],nxt[10000001],f[10000001],cnt,ans,mx=1;
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;ans++;}
inline void del(int x){for(int i=f[x];i;i=nxt[i]){if(bj[i])	break;ans--;bj[i]=1;}}
inline void mmp(int x){For(i,mx,x)	if(!bj[i])	ans--,bj[i]=1;mx=max(mx,x);}
int main()
{
	read(n);read(q);
	For(i,1,q)
	{
		int opt,x;
		read(opt);
		if(opt==1)	read(x),add(x,i);
		if(opt==2)	read(x),del(x);
		if(opt==3)	read(x),mmp(x);
		writeln(ans);
	}
}