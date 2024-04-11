#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,now,l,r;

int main()
{
	int i,j;
	cin>>n>>now>>l>>r;
	if(l==1)
	{
		if(r==n)
		{
			cout<<0;
			return 0;
		}
		cout<<abs(r-now)+1;
		return 0;
	}
	if(r==n)
	{
		cout<<abs(l-now)+1;
		return 0;
	}
	cout<<min(abs(r-now),abs(l-now))+(r-l)+2;
}