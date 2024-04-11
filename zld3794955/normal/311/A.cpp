#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
int main()
{	
	int n,k;
	cin>>n>>k;
	if(n*(n-1)/2<=k)
		puts("no solution");
	else
		for(int i=1;i<=n;++i)
			cout<<i<<' '<<i*n<<endl;
	return 0;
}