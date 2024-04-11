#pragma GCC optimize(4)
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
const int maxn=1e6+5;
int n,k,base;
char s[maxn];
set<int>S;
int len[maxn];
inline void init()
{
	FOR(i,1,n)len[i]=0;
	S.clear();
}
inline void input()
{
	n=gi(),k=gi();
	scanf("%s",s+1);
	base=min(k,22);
}
inline void solve()
{
	len[0]=0;
	FOR(i,1,n)
	{
		if(s[i]=='1')len[i]=len[i-1]+1;
		else len[i]=0;
		s[i]='1'+'0'-s[i];
	}
	FOR(i,k,n)
	{
		int now=k-base;
		if(len[i-base]>=now)
		{
			int temp=0;
			for(int j=i,kk=0;j>=i-base+1;--j,++kk)
			{
				temp+=(s[j]-'0')<<kk;
			}
			S.insert(temp);
		}
	}
	FOR(i,0,(1<<base)-1)
	{
		if(!S.count(i))
		{
			printf("YES\n");
			vector<int>vec;
			FOR(j,1,k)
			{
				if(i&1)vec.pb(1);
				else vec.pb(0);
				i>>=1;
			}
			reverse(vec.begin(),vec.end());
			for(auto x:vec)printf("%d",x);
			printf("\n");
			return ;
		}
	}
	printf("NO\n");
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
///-std=c++17(64)