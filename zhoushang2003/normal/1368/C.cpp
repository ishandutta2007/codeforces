#include<bits/stdc++.h>
using namespace std;
const int X[]={0,0,1,1,2,2,2},Y[]={1,2,0,2,0,1,2};
int n;
int main()
{
	cin>>n;
	cout<<7*n+8<<'\n'<<0<<' '<<0<<'\n';
	for(int i=0;i<=n;i++)
		for(int j=0;j<7;j++)
			cout<<2*i+X[j]<<' '<<2*i+Y[j]<<'\n';
	return 0;
}