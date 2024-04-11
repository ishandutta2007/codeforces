
 #include<bits/stdc++.h>
#define ll long long
#define db double
#define N 110
using namespace std;

int n,m,ha[N],lie[N],t,ans[N][N];

int main()
{
	int i,j;
	cin>>m>>n;
	for(i=1;i<=m;i++) scanf("%d",&ha[i]),t^=ha[i];
	for(i=1;i<=n;i++) scanf("%d",&lie[i]),t^=lie[i];
	if(t)
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<m;i++) ans[i][1]=ha[i],t^=ha[i];
	ans[m][1]=t^lie[1];
	for(i=2;i<=n;i++) ans[m][i]=lie[i];
	puts("YES");
	for(i=1;i<=m;i++)//
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
}