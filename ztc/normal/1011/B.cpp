#include<bits/stdc++.h>
using namespace std;
int n,m,i,j=0,c,a[102],cnt=0;
int main()
{
	cin>>n>>m;
	c=getchar();
	for(i=1;i<=m;i++)
	{
		cin>>c;
		a[c]+=1;
	}
	for(i=1;;i++)
	{
		cnt=0;
		for(j=1;j<=100;j++)cnt+=a[j]/i;
		if(cnt<n)
		{
			printf("%d",i-1);
			return 0;
		}
	}
}