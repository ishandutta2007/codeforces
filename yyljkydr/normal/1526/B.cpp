#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int f[N];

int main()
{
	scanf("%d",&T);
	f[0]=1;
	for(int i=1;i<=20000;i++)
	{
		for(int j=11;j<=i;j=j*10+1)
			f[i]|=f[i-j];
	}
	while(T--)
	{
		scanf("%d",&n);
		if(n>=20000)
			puts("YES");
		else
			puts(f[n]?"YES":"NO");
	}
}