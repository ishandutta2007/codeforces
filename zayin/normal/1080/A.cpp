#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	
	LL n,k;
	cin>>n>>k;
	
	LL ans=(2*n-1)/k+1+(5*n-1)/k+1+(8*n-1)/k+1;
	cout<<ans<<endl;
	return 0;
}