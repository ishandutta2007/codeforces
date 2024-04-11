#include<bits/stdc++.h>
using namespace std;
int t,x,y,z;
int main()
{
	cin>>t;
	while(t--&&cin>>x>>y)
		z=sqrt(x*x+y*y),puts(x+y==0?"0":(z*z==x*x+y*y?"1":"2"));
}