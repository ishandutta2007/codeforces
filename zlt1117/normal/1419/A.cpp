#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1005;
char s[maxn];
int main()
{
	int T=gi();
	while(T--)
	{
		int n=gi();
		scanf("%s",s+1);
		if(n%2==0)
		{
			bool ok=0;
			FOR(i,1,n)
			{
				if(i%2==0&&(s[i]-'0')%2==0)ok=true;
			}
			if(ok)printf("2\n");
			else printf("1\n");
		}
		else
		{
			bool ok=0;
			FOR(i,1,n)
			{
				if(i%2==1&&(s[i]-'0')%2==1)ok=true;
			}
			if(!ok)printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}