#include<stdio.h>
bool r[300002];
int Last[300002],Next[600002],End[600002];
int q[300002];
int maxx[300002],cnt[300002];
int n;
void dfs(int p,int fp)
{
	if(p!=1&&r[p]==0)
	{
		cnt[p]=maxx[p]=1;
		return;
	}
	int i=Last[p];cnt[p]=maxx[p]=0;
	while(i)
	{
		if(End[i]!=fp)
		{
			dfs(End[i],p);
			cnt[p]+=cnt[End[i]];
			if(q[p]&&(maxx[End[i]]<maxx[p]||!maxx[p]))maxx[p]=maxx[End[i]];
			if(!q[p])maxx[p]+=maxx[End[i]];
		}
		i=Next[i];
	}
}
int a,cntt;
main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		if(!r[a])r[a]=1;
		End[i]=i;Next[i]=Last[a];Last[a]=i;
	}
	dfs(1,0);
	printf("%d",cnt[1]-maxx[1]+1);
}