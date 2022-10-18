#include<iostream>
using namespace std;
long long n,m,a,b,x,y;
int main()
{
	cin>>n;
	m=2*n;
	while(m--&&cin>>x>>y)
		a+=x,b+=y;
	cout<<a/n<<" "<<b/n;
	return 0;
}