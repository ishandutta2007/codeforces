//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
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
const int maxn=2e5+5,mod=1e9+3;
int n,q,t1,t2,len,cnt[maxn];
char s[maxn];
ll ha[2][maxn],pw[maxn];
inline void init()
{

}
inline ll get(int l,int r)
{
	if(l&1)
	{
		ll val=ha[1][r]-(ha[1][l-1]*pw[cnt[r]-cnt[l-1]])%mod;
		val%=mod;val=(val+mod)%mod;
		return val;
	}
	else
	{
		ll val=ha[0][r]-(ha[0][l-1]*pw[cnt[r]-cnt[l-1]])%mod;
		val%=mod;val=(val+mod)%mod;
		return val;
	}
}
inline void input()
{
	n=gi();
	scanf("%s",s+1);
	q=gi();
	pw[0]=1;
	///0 stay ,1 change
	FOR(i,1,n)
	{
		pw[i]=pw[i-1]*131%mod;
		cnt[i]=cnt[i-1]+'1'-s[i];
		if(s[i]!='0')ha[1][i]=ha[1][i-1],ha[0][i]=ha[0][i-1];
		else
		{
			ha[0][i]=(ha[0][i-1]*131)%mod;
			ha[1][i]=(ha[1][i-1]*131)%mod;
			ha[0][i]=(ha[0][i]+(i&1)+131)%mod;
			ha[1][i]=(ha[1][i]+((i&1)^1)+131)%mod;
		}
	}
}
inline void solve()
{
	t1=gi(),t2=gi(),len=gi();
	if(get(t1,t1+len-1)==get(t2,t2+len-1))printf("Yes\n");
	else printf("No\n");
}
int main()
{
//	freopen("1.in","r",stdin);
	init();
	input();
	while(q--)solve();
	return 0;
}
/*
3
010
1
3 2 1
*/