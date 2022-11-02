#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
const int N=1000005;
int vis[N],index,low[N],num[N],sta[N],q[N],top,x,y,ins[N];
int szb[N],nxt[N],head[N],cnt,tot,n,in[N],dp[N],ans,m;
char s[N];
inline void insert(int x,int y){szb[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void gg(){puts("-1"); exit(0);}
inline void dfs(int x)
{
	low[x]=1;vis[x]=1;
	for(int i=head[x];i;i=nxt[i])if(low[szb[i]])gg(); else if(!vis[szb[i]])dfs(szb[i]);
	low[x]=0;
}
inline void solve()
{
	For(c,'a','z')
	{
		memset(in,0,sizeof(in)); memset(dp,0,sizeof(dp));
		For(i,1,n)for(int j=head[i];j;j=nxt[j])in[szb[j]]++;
		int l=1,r=0;
		For(i,1,n)if(in[i]==0){q[++r]=i; dp[i]=(c==s[i]?1:0);}
		while(l<=r)
		{
			int x=q[l];
			for(int i=head[x];i;i=nxt[i]){
				dp[szb[i]]=max(dp[szb[i]],dp[x]+(c==s[szb[i]]?1:0));
				in[szb[i]]--;
				if(in[szb[i]]==0)	q[++r]=szb[i];
			}
			++l;
		}
		For(i,1,n)	ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}
int main()
{
	n=read();m=read();
	scanf("%s",s+1);
	For(i,1,m){x=read(); y=read(); insert(x,y);}
	For(i,1,n)if(!vis[i])	dfs(i);
	solve();
}