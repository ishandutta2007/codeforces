#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,x;
main()
{
	for(cin>>n;cin>>n;)
		for(int i=1;i<N;i++)
			if((i-1)*(i-1)<n&&n<=i*i)
				if((x=n-(i-1)*(i-1))<=i)
					cout<<x<<' '<<i<<'\n';
				else
					cout<<i<<' '<<i*i-n+1<<'\n';
}