#include<iostream>
#include<cstdio>
using namespace std;

int n,ans;

int main()
{
	int i,j;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		if(n%i==0) ans++;
	}
	cout<<ans;
}