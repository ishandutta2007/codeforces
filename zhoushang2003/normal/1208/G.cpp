#import<bits/stdc++.h>
using namespace std;
int n,k,a[9999999];
main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=2;i<=n;i++)
		if(a[i]==i)
			for(int j=i;j<=n;j+=i)
				a[j]=a[j]/i*(i-1);
	sort(a+3,a+n+1);
	cout<<accumulate(a+3,a+k+3,1ll+(k>1));
}