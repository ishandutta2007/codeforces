#include<bits/stdc++.h>
using namespace std;
int main()
{	
	long long k,n,w;
	cin>>k>>n>>w;
	cout<<max(0ll,w*(w+1)/2*k-n)<<endl;
	return 0;
}