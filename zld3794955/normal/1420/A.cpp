#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,a[N]={};
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		bool flag=(n==1);
		for(int i=1;i<n && !flag;++i)
			flag|=(a[i]<=a[i+1]);
		puts(flag ? "YES" : "NO");
	}
}