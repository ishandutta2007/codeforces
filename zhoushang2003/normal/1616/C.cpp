#import<bits/stdc++.h>
using namespace std;
int n,a[999],A,c;
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n==1)
		{
			puts("0");
			continue;
		}
		A=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				c=0;
				for(int k=1;k<=n;k++)
					c+=a[k]*(j-i)+(i-k)*(a[j]-a[i])==a[i]*(j-i);
				A=max(A,c);
			}
		cout<<n-A<<'\n';
	}
}