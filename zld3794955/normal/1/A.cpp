#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a;
int main()
{	
	cin>>n>>m>>a;
	cout<<(n/a+!!(n%a))*(m/a+!!(m%a))<<endl;
	return 0;
}