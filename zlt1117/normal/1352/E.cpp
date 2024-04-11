#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<bitset>
#define ll long long
#define ull unsigned long long
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
const int maxn=8005;
int T,a[maxn],pre[maxn],n;
bitset<maxn*maxn>s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		s.reset();
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
		for(int i=1;i<=n-1;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				s.set(pre[j]-pre[i-1]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)if(s.test(a[i]))ans++;
		printf("%d\n",ans);
	}
	return 0;
}