#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
#define pb push_back
#define iter set<PII>::iterator
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
const int maxn=2e5+5;
int T,n;
char s[maxn];
int a[maxn],num[maxn];
int main()
{
//	freopen("1.out","w",stdout);
	T=gi();
	while(T--)
	{
		n=gi();
		scanf("%s",s+1);
		int last=1;
		int tot=0;
		set<PII>se;
		set<int>use;
		se.clear(),use.clear();
		FOR(i,2,n)
		{
			if(s[i]!=s[i-1])
			{
				a[++tot]=i-last;
				last=i;
				if(a[tot]>=2)se.insert(PII(i-1,a[tot]));
				num[i-1]=a[tot];
				use.insert(i-1);
			}
		}
		num[n]=n-last+1;
		a[++tot]=n-last+1;
		if(a[tot]>=2)se.insert(PII(n,a[tot]));
		use.insert(n);
		int ans=0;
		while(use.size())
		{
			int x=*use.begin();
			use.erase(x);
			if(se.count(PII(x,num[x])))
			{
				ans++;
				se.erase(PII(x,num[x]));
			}
			else
			{
				ans++;
				iter it=se.lower_bound(PII(x,num[x]));
				if(it==se.end())
				{
					if(use.size())use.erase(use.begin());
					continue;
				}
				se.erase(it);
				num[(*it).first]--;
				if(num[(*it).first]>=2)se.insert(PII((*it).first,num[(*it).first]));
			}
		}
		FOR(i,1,n)num[i]=0,a[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}
///