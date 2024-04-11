#include<iostream>
#include<cstdio>
using namespace std;
long long a=0,s=45*18,l=0,r=1000000000000000000ll;
int main()
{	
	cin>>a;
	for(int i=1;i<=17;++i)
		s=s*10%a;
	cout<<l+a-s<<' '<<r+a-s-1<<endl;
	return 0;
}