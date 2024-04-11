#include<bits/stdc++.h>
#define maxn 500050
using namespace std;

int n,m;
int u[maxn],v[maxn];
int evis[maxn],vvis[maxn];

int main()	{
//	freopen("c.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--)	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n*3;++i) vvis[i]=0;
		for (int i=1;i<=m;++i) evis[i]=0; 
		
		int cnt=0;
		for (int i=1;i<=m;++i)	{
			scanf("%d%d",u+i,v+i);
			if (vvis[u[i]]||vvis[v[i]]) continue;
			++cnt;
			
			evis[i]=1;
			vvis[u[i]]=vvis[v[i]]=1;
		}
		
		if (cnt>=n)	{
			puts("Matching");
			cnt=n;
			for (int i=1;i<=m&&cnt;++i)
				if (evis[i])
					printf("%d ",i),--cnt;
			puts(""); 
		} else	{
			puts("IndSet");
			cnt=n;
			for (int i=1;i<=n*3&&cnt;++i)
				if (!vvis[i])
					printf("%d ",i),--cnt;
			puts("");
		} 
	}
	return 0;
}