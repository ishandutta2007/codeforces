#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int main()
{
	cin>>t;
	while(t--&&cin>>x>>y)
		cout<<(x?x+2*y+1:1)<<'\n';
}