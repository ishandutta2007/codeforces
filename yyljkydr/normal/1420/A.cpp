#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bool ok=0;
		for(int i=1;i<n;i++)
			ok|=a[i]<=a[i+1];
		puts(ok?"YES":"NO");
	}
}