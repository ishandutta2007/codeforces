#include<bits/stdc++.h>
using namespace std;

long long a,b,T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(b==1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			if(b==2)
				cout<<a<<" "<<3*a<<" "<<4*a<<"\n";
			else
				cout<<a<<" "<<a*b-a<<" "<<b*a<<"\n";
		}
	}
}