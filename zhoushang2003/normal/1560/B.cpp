#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,a,b,c,x;
main()
{
	for(cin>>n;cin>>a>>b>>c;)
	{
		x=2*abs(a-b);
		cout<<(a<=x&&b<=x&&c<=x?(c+x/2-1)%x+1:-1)<<'\n';
	}
}