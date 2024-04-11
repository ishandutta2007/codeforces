#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],cnt[110];
bool check()
{
	for(int i=1;i<=m;i++)
	if(b[i]!=cnt[i])return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof cnt);
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if(check()){printf("YES");return 0;}
		}
	}
	printf("NO");
}