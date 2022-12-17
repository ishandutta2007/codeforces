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
inline int getint()
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
const int maxn=3e5+5;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int T,n,k;
char s[maxn];
int main()
{
	T=getint();
	while(T--)
	{
		n=getint(),k=getint();
		scanf("%s",s+1);
		int cnt=0,cnt2=0;
		bool ok=true;
		FOR(i,1,k)
		{
			char typ=0;
			for(int j=i;j<=n;j+=k)
			{
				if(s[j]!='?')
				{
					if(typ==0)typ=s[j];
					else if(typ!=s[j])
					{
						ok=false;
						break;
					}
				}
			}
			s[i]=typ;
			if(!ok)break;
			if(s[i]=='1')cnt++;
			if(s[i]=='0')cnt2++;
		}
		if(ok&&cnt<=k/2&&cnt2<=k/2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}