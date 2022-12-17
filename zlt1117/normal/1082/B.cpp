//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
int n;
char s[maxn];
int pre[maxn],nxt[maxn],cnt1,cnt2;
inline void init()
{

}
inline void input()
{
	n=gi();
	scanf("%s",s+1);
	FOR(i,1,n)
	{
		if(s[i]==s[i-1]&&s[i]=='G')pre[i]=pre[i-1]+1;
		else if(s[i]=='G')pre[i]=1;
		if(s[i]=='G')cnt1++;
		else cnt2++;
	}
	for(int i=n;i>=1;--i)
	{
		if(s[i]==s[i+1]&&s[i]=='G')nxt[i]=nxt[i+1]+1;
		else if(s[i]=='G')nxt[i]=1;
	}
}
inline void solve()
{
	int ans=0;
	if(cnt2==0)ans=cnt1+cnt2;
	if(cnt1==0)ans=0;
	FOR(i,1,n)ans=max(ans,pre[i]+(pre[i]==cnt1?0:1));
	FOR(i,1,n)ans=max(ans,nxt[i]+(nxt[i]==cnt1?0:1));
	FOR(i,1,n)
	{
		if(s[i-1]!=s[i]&&s[i]=='S'&&s[i+1]!=s[i])
		{
			ans=max(ans,pre[i-1]+nxt[i+1]+((pre[i-1]+nxt[i+1]==cnt1)?0:1));
		}
	}
	printf("%d\n",ans);
}
int main()
{
	input();
	init();
	solve();
	return 0;
}