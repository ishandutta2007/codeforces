#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N]={};
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int s=accumulate(a+1,a+n+1,0),ans=0;
	for(int i=1;i<=5;++i)
		ans+=bool((s+i)%(n+1)!=1);
	cout<<ans<<endl;
}