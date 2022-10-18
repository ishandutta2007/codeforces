#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,e,f;
int main()
{
	cin>>t;
	while(t--&&cin>>a>>b>>c>>d>>e>>f)
		if(b==d&&b>f)
			cout<<abs(a-c)<<'\n';
		else if(d==f&&d>b)
			cout<<abs(c-e)<<'\n';
		else if(f==b&&f>d)
			cout<<abs(e-a)<<'\n';
		else
			puts("0");
}