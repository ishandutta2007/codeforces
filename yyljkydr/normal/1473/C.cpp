#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)
			a[i]=i;
		reverse(a+2*k-n,a+k+1);
		for(int i=1;i<=k;i++)
			printf("%d%c",a[i]," \n"[i==k]);
	}
}