#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n*2+1);
		int f=0,g=n*2+1;
		for(int i=1;i<=n*2;i++)
			if(i&1)
				printf("%d ",a[++f]);
			else
				printf("%d ",a[--g]);
		puts("");
	}
}