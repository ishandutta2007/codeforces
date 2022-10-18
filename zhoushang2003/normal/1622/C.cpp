#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[999999],A,s;
main()
{
	for(cin>>n;cin>>n>>k;)
	{
		s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i];
		sort(a+1,a+n+1),A=max(0ll,s-k);
		for(int i=n;i>1;i--)
			s-=a[i]-a[1],A=min(A,n-i+1+max(0ll,(int)ceil(1.0*(s-k)/(n-i+2))));
		cout<<A<<'\n';
	}
}