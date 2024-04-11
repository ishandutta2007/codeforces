#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
int main()
{	
	int n,a1,a2,b1,b2,c1,c2;
	cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
	cout<<min(n-b1-c1,a2)<<' ';
	n-=min(n-b1-c1,a2);
	cout<<min(n-c1,b2)<<' ';
	n-=min(n-c1,b2);
	cout<<n<<endl;
	return 0;
}