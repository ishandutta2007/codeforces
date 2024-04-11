#include<bits/stdc++.h>
using namespace std;
const int D=1e9+7;
long long n,m,t;
long long P(long long a,long long b)
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
int main()
{
	cin>>n>>m;
	cout<<P(P(2,m)-1,n);
	return 0;
}