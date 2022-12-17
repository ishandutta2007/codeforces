//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define iter auto
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int T,n,ans;
char s[maxn];
int main()
{
	T=gi();
	while(T--)
	{
		set<int>s_A,s_B;
		scanf("%s",s+1);
		n=strlen(s+1);ans=n;
		FOR(i,1,n)if(s[i]=='A')s_A.insert(i);else s_B.insert(i);
		while(!s_A.empty()&&!s_B.empty())
		{
			iter it=s_B.end();--it;
			iter it1=s_A.end();--it1;
			if((*it)>(*it1))s_A.erase(it1),s_B.erase(it),ans-=2;
			else s_A.erase(it1);
		}
		ans-=(s_B.size()/2)*2;
		printf("%d\n",ans);
	}
	return 0;
}