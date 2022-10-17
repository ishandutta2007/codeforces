#include<bits/stdc++.h>
#define N 1010
using namespace std;

int m,n,a[N][N],b[N][N];
map<int,int>cnt;

int main()
{
    int i,j;
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=n;j++)
	{
	    scanf("%d",&a[i][j]);
	}
    }
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=n;j++)
	{
	    scanf("%d",&b[i][j]);
	}
    }
    for(i=2;i<=m+n;i++)
    {
	for(j=1;j<i;j++)
	{
	    cnt[a[j][i-j]]++;
	}
	for(j=1;j<i;j++)
	{
	    if(!cnt[b[j][i-j]])
	    {
		puts("NO");
		return 0;
	    }
	    cnt[b[j][i-j]]--;
	}
    }
    puts("YES");
}