#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int n,a[N],f[200001];

int main()
{
	scanf("%d",&n);
	int g=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),g=__gcd(g,a[i]);
	int s=0;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		s+=a[i]/g;
		for(int j=s;j>=a[i]/g;j--)
			f[j]|=f[j-a[i]/g];
	}
	if((s&1)||!f[s/2])
		puts("0");
	else
	{
		puts("1");
		for(int i=1;i<=n;i++)
			if((a[i]/g)&1)
			{
				printf("%d\n",i);
				break;
			}
	}
}