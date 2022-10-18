#import<bits/stdc++.h>
using namespace std;
int n,x,c[999],A;
main()
{
	for(cin>>n;cin>>n;)
	{
		memset(c,0,sizeof(c)),A=0;
		for(int i=1;i<=n;i++)
			cin>>x,c[abs(x)]++;
		for(int i=1;i<=100;i++)
			A+=min(2,c[i]);
		cout<<A+(c[0]>0)<<'\n';
	}
}