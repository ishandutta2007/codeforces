#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[10010]={},b[10010]={},t[2][2]={};
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;++i)
		++t[0][a[i]],++t[1][b[i]];
	cout<<min(t[0][0],t[0][1])+min(t[1][0],t[1][1])<<endl;
}