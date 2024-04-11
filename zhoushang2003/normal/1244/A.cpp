#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k;
main()
{
	for(cin>>a;cin>>a>>b>>c>>d>>k;)
		(a=(a-1)/c+1)+(b=(b-1)/d+1)>k?cout<<"-1\n":cout<<a<<' '<<b<<'\n';
}