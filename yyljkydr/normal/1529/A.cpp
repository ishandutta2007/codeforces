#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int mn=1e9,ct=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<mn)
				mn=a[i],ct=1;
			else if(a[i]==mn)
				ct++;
		}
		printf("%d\n",n-ct);
	}
}