#include<bits/stdc++.h>
using namespace std;
int n,m,i,j=0,cnt=0;
bool a[28];
char c;
int main()
{
	cin>>n>>m;
	c=getchar();
	for(i=1;i<=n;i++)
	{
		c=getchar();
		a[c-'a'+1]=1;
	}
	for(i=1;i<=m;i++)
	{
		while(!a[j]&&j<=27)j++;
		if(j>=27)
		{
			printf("-1");
			return 0;
		}
		cnt+=j;
		j+=2;
	}
	printf("%d",cnt);
}