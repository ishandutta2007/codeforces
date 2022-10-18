#include<bits/stdc++.h>
using namespace std;
int t,l,r,a,x;
int main()
{
	cin>>t;
	while(t--&&cin>>l>>r>>a)
		x=(r+1)/a*a-1,l<=x?cout<<x/a+x%a<<'\n':cout<<r/a+r%a<<'\n';
}