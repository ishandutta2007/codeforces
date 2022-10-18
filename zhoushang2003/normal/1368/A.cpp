#include<bits/stdc++.h>
using namespace std;
int T,A,n,a,b;
int main()
{
	cin>>T;
	while(T--&&cin>>a>>b>>n)
	{
		A=0;
		while(a<=n&&b<=n)
		{
			if(a>b)
				swap(a,b);
			a+=b,A++;
		}
		cout<<A<<'\n';
	}
	return 0;
}