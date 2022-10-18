#include<iostream>
using namespace std;
const int I=1e9;
int n,k,A=I;
int main()
{
	cin>>n>>k;
	for(int i=1;i<k;i++)
		if(n%i==0)
			A=min(A,n/i*k+i);
	cout<<A;
	return 0;
}