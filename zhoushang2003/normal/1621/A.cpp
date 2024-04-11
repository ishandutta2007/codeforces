#include<bits/stdc++.h>
using namespace std;
int n,k;
main()
{
	for(cin>>n;cin>>n>>k;)
	{
		if((n+1)/2<k)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
				cout<<(i==j&&i&1&&(i+1)/2<=k?'R':'.');
	}
}