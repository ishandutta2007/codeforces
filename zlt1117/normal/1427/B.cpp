//#pragma GCC optimize(4)
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
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
const int maxn=1e5+5;
int T,n,k;
char s[maxn];
int main()
{
	T=gi();
	while(T--)
	{
		priority_queue<int,vector<int>,greater<int> >pq;
		int ans=0;
		n=gi(),k=gi();
		scanf("%s",s+1);
		int last=0;
		int now=0;
		FOR(i,1,n)if(s[i]=='W'){last=i;ans++;now++;break;}
		FOR(i,last+1,n)
		{
			if(s[i]=='W')
			{
				pq.push(i-last-1);
				last=i;
				ans++;
			}
		}
		while(!pq.empty())
		{
			int x=pq.top();
			pq.pop();
			if(k>=x)k-=x;
			else break;
			ans+=x*2+1;
			now++;
		}
		if(now&&k)ans+=k*2;
		else if(!now&&k)ans+=k*2-1;
		ans=min(ans,2*n-1);
		printf("%d\n",ans);
	}
	return 0;
}