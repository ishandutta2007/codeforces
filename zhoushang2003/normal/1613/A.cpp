#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t;
double x,p,X,P,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>x>>p>>X>>P)
	{
		A=log10(x/X)+p-P;
		if(!A)
			cout<<'='<<'\n';
		else if(A<0)
			cout<<'<'<<'\n';
		else
			cout<<'>'<<'\n';
	}
}