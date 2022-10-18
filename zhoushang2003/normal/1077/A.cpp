#include<iostream>
using namespace std;
int t;
long long a,b,k;
int main()
{
	cin>>t;
	while(t--&&cin>>a>>b>>k)
		cout<<(k+1)/2*a-k/2*b<<endl;
	return 0;
}