#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef unsigned long long ULL;
unordered_map<ULL,int> ma;
int n,m;
char s1[2010][2100],s2[2100][2010];
ULL H1[2010],H2[2100][2010],H3[2010];
ULL powx[3010];
const ULL X=131,Y=233;
ULL ghash(int l,int r,ULL *arr)
{
	return arr[l]-arr[r+1]*powx[r-l+1];
}
int main()
{
	int i,j;ULL now;
	powx[0]=1;
	for(i=1;i<=3000;i++)	powx[i]=powx[i-1]*X;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)	scanf("%s",s1[i]+1);
	for(i=1;i<=m;i++)	scanf("%s",s2[i]+1);
	for(i=1;i<=n;i++)
		for(j=m;j>=1;j--)
			H1[i]=H1[i]*X+s1[i][j];
	for(i=1;i<=m;i++)
		for(j=n;j>=1;j--)
			H2[i][j]=H2[i][j+1]*X+s2[i][j];
	for(i=1;i<=n-m+1;i++)
	{
		for(j=m;j>=1;j--)
			H3[i]=H3[i]*Y+H1[i+j-1];
		ma[H3[i]]=i;
	}
	for(j=1;j<=n-m+1;j++)
	{
		now=0;
		for(i=m;i>=1;i--)	now=now*Y+ghash(j,j+m-1,H2[i]);
		if(ma.count(now))
		{
			printf("%d %d",ma[now],j);
			return 0;
		}
	}
	return 0;
}