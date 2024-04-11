#include<bits/stdc++.h>
using namespace std;
const int N=505,M=505;
int n,m,s1[N][M]={},s2[N][M]={};
char ch[N][M]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("\n%s",ch[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s1[i][j]=s1[i][j-1]+s1[i-1][j]-s1[i-1][j-1]+(ch[i][j]=='.' && ch[i-1][j]=='.');
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s2[i][j]=s2[i][j-1]+s2[i-1][j]-s2[i-1][j-1]+(ch[i][j]=='.' && ch[i][j-1]=='.');
	}
void work()
{
	int q,x1,x2,y1,y2;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=s1[x2][y2]-s1[x2][y1-1]-s1[x1][y2]+s1[x1][y1-1];
		ans+=s2[x2][y2]-s2[x2][y1]-s2[x1-1][y2]+s2[x1-1][y1];
		printf("%d\n",ans);
	}
}
int main()
{	
	init();
	work();
	return 0;
}