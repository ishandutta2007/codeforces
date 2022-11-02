#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n,a=0,b=0,c=0;
	cin>>n;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x;
		a^=x;
	}
	for(int i=2,x=0;i<=n;++i)
	{
		cin>>x;
		b^=x;
	}
	for(int i=3,x=0;i<=n;++i)
	{
		cin>>x;
		c^=x;
	}
	cout<<(a^b)<<endl<<(b^c)<<endl;
	return 0;
}