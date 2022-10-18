#include<bits/stdc++.h>
using namespace std;
#define int long long
const int D=1e9+7;
int T,n,m,l,r,x,A,t;
int P(int a,int b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		A=0;
		while(m--&&cin>>l>>r>>x)
			A|=x;
		cout<<A*P(2,n-1)%D<<'\n';
	}
	return 0;
}