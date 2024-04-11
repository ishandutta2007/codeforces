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
const int maxn=150005;
int T,n;
char s[maxn];
vector<int>vec;
inline void init()
{
	vec.clear();
	FOR(i,1,n)s[i]=0;
}
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
}
inline void solve()
{
	FOR(i,1,n)
	{
		if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
		{
			if(s[i+3]=='n'&&s[i+4]=='e')
			{
				vec.pb(i+2);
				i=i+4;
			}
			else 
			{
				vec.pb(i+1);
				i=i+2;
			}
		}
		else if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
		{
			vec.pb(i+1);
			i=i+2;
		}
	}	
	printf("%d\n",sz(vec));
	for(auto x:vec)printf("%d ",x);
	printf("\n");
}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}