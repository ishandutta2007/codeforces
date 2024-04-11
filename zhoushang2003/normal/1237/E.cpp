#include<iostream>
using namespace std;
int n,c;
int main()
{
	cin>>n;
	c=1;
	while(c<=n)
	{
		if(c==n||c+1==n)
		{
			cout<<1;
			return 0;
		}
		c=2*c+1+(c&1); 
	}
	cout<<0;
	return 0;
}