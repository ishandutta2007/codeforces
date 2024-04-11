#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e2+3;
int a[MAX];
bool b[MAX][MAX];
LL rin()
{
	LL s=0;
	bool bj=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')bj=1,c=getchar();
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
	if(bj)return -s;
	return s;
}
int main()
{
	int i,j,k;
	int n,m;
	int ans=0x3f3f3f3f;
	n=rin();m=rin();
	for(i=1;i<=n;i++)a[i]=rin();
	int x,y;
	for(i=1;i<=m;i++)x=rin(),y=rin(),b[x][y]=b[y][x]=true;
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	for(k=j+1;k<=n;k++)
	if(b[i][j]&&b[j][k]&&b[i][k])
	ans=min(ans,a[i]+a[j]+a[k]);
	if(ans==0x3f3f3f3f)printf("-1");
	else printf("%d",ans);
	return 0;
}