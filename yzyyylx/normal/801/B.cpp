#include<iostream>
#include<cstdio>
using namespace std;

string a,b;

int main()
{
	int i,j;
	cin>>a>>b;
	for(i=0;i<a.size();i++)
	{
		if(a[i]<b[i])
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<b;
}