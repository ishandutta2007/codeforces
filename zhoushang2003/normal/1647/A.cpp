#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		if(n%3==1)
			cout<<1;
		for(int i=1;i<=n/3;i++)
			cout<<21;
		if(n%3==2)
			cout<<2;
		puts("");
	}
}