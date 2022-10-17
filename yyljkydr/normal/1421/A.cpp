#include<bits/stdc++.h>
using namespace std;

int T,a,b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		cout<<(a^b)<<"\n";
	}
}