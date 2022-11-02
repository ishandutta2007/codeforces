#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N]={},tot=0;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		a[++tot]=1;
		while(tot>=2 && a[tot]==a[tot-1])
			++a[--tot];
	}
	for(int i=1;i<=tot;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}