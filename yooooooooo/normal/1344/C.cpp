#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,x,y,h,dr[2][200005],dy[2][200005],q[200005],l,r,v,mi[2][200005],ans=0;
vector<int>s[2][200005];
//cr;
void topo(int nw)
{
	int tot=0;
	for(int i=1;i<=n;i++)dr[0][i]=dy[0][i],dr[1][i]=dy[1][i];
	l=r=1;
	for(int i=1;i<=n;i++)if(dr[nw][i]==0)q[r++]=i;
	while(l<r)
	{
		v=q[l++];tot++;
		for(int i=0;i<s[!nw][v].size();i++)
		{
			h=s[!nw][v][i];
			mi[nw][h]=min(mi[nw][h],mi[nw][v]);
			dr[nw][h]--;
			if(dr[nw][h]==0)q[r++]=h;
		}
	}
	if(tot<n)
	{
		printf("-1\n");
		exit(0);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)mi[0][i]=mi[1][i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		s[0][x].push_back(y);
		s[1][y].push_back(x);
		dr[0][x]++;dy[0][x]++;
		dr[1][y]++;dy[1][y]++;
	}
	topo(0);
	topo(1);
	for(int i=1;i<=n;i++)if(mi[0][i]==i&&mi[1][i]==i)ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(min(mi[0][i],mi[1][i])<i)printf("E");
		else printf("A");
	}
	printf("\n");
	return 0;
}