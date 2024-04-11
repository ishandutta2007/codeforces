#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,s,u,c,a[999999],l,r,d;
int C(int x)
{
	if(x>=2*c-1&&x/2*2+(x+1)/2>=n*u-s)
		return 1;
	return x>=2*(n-c)-1&&x/2*2+(x+1)/2>=n*(u+1)-s;
}
main()
{
	for(cin>>n;cin>>n;)
	{
		s=u=c=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i],u=max(u,a[i]);
		l=0,r=1e18;
		for(int i=1;i<=n;i++)
			if((a[i]+u)&1)
				c++;
		while(l<r)
			C(d=(l+r)/2)?r=d:l=d+1;
		cout<<l<<'\n';
	}
}