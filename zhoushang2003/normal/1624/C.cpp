#import<bits/stdc++.h>
using namespace std;
int n,a[99],v;
int C(int x,int y)
{
	while(x/2>=y)
		x/=2;
	return x==y;
}
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i;i--)
			for(int j=1;j<=n;j++)
				if(C(a[j],i))
					a[j]=0,v++,j=n;
		puts(v==n?"YES":"NO"),v=0;
	}
}