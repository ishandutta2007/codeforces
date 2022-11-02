#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	int d=0,ans=0;
	while(n<m)
	{
		n<<=1;
		++d;
	}
	for(int i=d;i>=0;--i)
	{
		ans+=(n-m)/(1<<i);
		n=m+(n-m)%(1<<i);
	}
	cout<<ans+d<<endl;
	return 0;
}