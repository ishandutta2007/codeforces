#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,a,b,o=1;
main()
{
	cin>>n,x=y=1;
	while(o)
	{
		cout<<min(n,a+x)<<' '<<min(n,b+y)<<'\n';
		cin>>o;
		if(o==1)
			a+=x,x*=2;
		else if(o==2)
			b+=y,y*=2;
		else
			x=max(1ll,x/2),y=max(1ll,y/2);
	}
}