#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

long long a,b,c,d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		if(a>b*c)
			cout<<"-1\n";
		else
		{
			long long t=a/(d*b);
			cout<<a*(t+1)-(t*(t+1))/2*b*d<<"\n";
		}
	}
}