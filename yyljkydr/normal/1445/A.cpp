#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int a[N],b[N];

int T,n,m;

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1,greater<int>());
		int ok=1;
		for(int i=1;i<=n;i++)
			ok&=(a[i]+b[i]<=m);
		puts(ok?"YES":"NO");
	}
}