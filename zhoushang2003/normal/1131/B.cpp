#include<iostream>
using namespace std;
int n,a,b,x,y,A=1;
int main()
{
	cin>>n;
	while(n--&&cin>>x>>y)
		A+=max(0,min(x,y)-max(a,b)+(a!=b)),a=x,b=y;
	cout<<A;
	return 0;
}