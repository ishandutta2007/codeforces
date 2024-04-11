#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 1050
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int n;

char s[10];

int p[maxn],c[maxn];

int cost[maxn];

int main()
{
//	freopen("c.in","r",stdin);
	memset(cost,0x3f,sizeof(cost));
	cost[0]=0;
	
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%s",&p[i],s);
		for (int j=0;s[j];++j)
			c[i]|=1<<(s[j]-'A');
//		cout<<c[i]<<" "<<p[i]<<endl;
//		printf("%d %d\n",c[i],p[i]);
		cost[c[i]]=min(cost[c[i]],p[i]);
	}
	
	for (int s=1;s<(1<<3);++s)
	{
		for (int t=0;t<=s;++t)
			for (int p=0;p<=s;++p)
				if ((p|t)==s)
					cost[s]=min(cost[s],cost[p]+cost[t]);
//		printf("%d %d\n",s,cost[s]);
	}
	
	if (cost[7]==inf)
		puts("-1");
	else
		printf("%d\n",cost[7]);
	return 0;
}