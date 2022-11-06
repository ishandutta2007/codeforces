#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char c,a[52];
bool b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		getchar();
		b=1;
		for(int j=1;j<=(m>>1);j++)a[j]=getchar();
		for(int j=(m>>1)+1;j<=m;j++)
		{
			c=getchar();
			k=int(c-a[m+1-j]);
			if(k!=0&&k!=2&&k!=-2)b=0;
		}
		if(b)printf("YES\n");
		else printf("NO\n");
	}
}