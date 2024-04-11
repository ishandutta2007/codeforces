#import<bits/stdc++.h>
using namespace std;
#define int long long
const int D=998244353;
int n,u,p,x,A;
main()
{
	for(cin>>n;cin>>n;)
	{
		map<int,int>c;
		u=0,p=A=1;
		for(int i=1;i<=n;i++)
			cin>>x,u=max(u,x),c[x]++,(p*=i)%=D;
		if(c[u]>1)
		{
			cout<<p<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			if(i!=c[u-1]+1)
				(A*=i)%=D;
		cout<<A*c[u-1]%D<<'\n'; 
	}
}