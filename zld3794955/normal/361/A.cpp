#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cout<<(i==j ? k : 0)<<endl;
	return 0;
}