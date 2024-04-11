#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

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
		for(int i=1;i<=n;i++)
		{
			int q=sqrt(a[i]);
			while(q*q>a[i])
				q--;
			while((q+1)*(q+1)<=a[i])
				q++;
			ok|=q*q!=a[i];
		}
		puts(ok?"YES":"NO");
	}
}