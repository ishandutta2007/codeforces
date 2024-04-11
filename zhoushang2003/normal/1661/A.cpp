#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[99],b[99],A;
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
			if(a[i]>b[i])
				swap(a[i],b[i]);
		A=0;
		for(int i=1;i<n;i++)
			A+=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
		cout<<A<<'\n';
	}
}