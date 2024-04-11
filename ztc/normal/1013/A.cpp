#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,s=0xfffffff,t,a;
int main()
{
	scanf("%d",&m);
	for(i=1;i<=2;i++)
	{
		t=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a);
			t+=a;
		}
		if(t>s)
		{
			printf("No");
			return 0;
		}
		s=t;
	}
	printf("Yes");
}