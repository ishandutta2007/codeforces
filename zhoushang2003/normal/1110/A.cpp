#include<iostream>
using namespace std;
int b,k,x,A;
int main()
{
	cin>>b>>k;
	while(k--&&cin>>x)
		A=(A*b+x)&1;
	if(A&1)
		cout<<"odd";
	else
		cout<<"even";
	return 0;
}