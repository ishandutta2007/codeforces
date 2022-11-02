#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	if(k==n)
		puts("-1");
	else
	{
		for(int i=1;i<n-k;++i)
			cout<<i+1<<' ';
		cout<<1;
		for(int i=n-k+1;i<=n;++i)
			cout<<' '<<i;
		cout<<endl;
	}
	return 0;
}