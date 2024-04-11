#include<iostream>
#include<cmath>
using namespace std;
const int N=100,I=1e9;
int n,a[N],s,A=I;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		s=0;
		for(int j=0;j<n;j++)
			s+=2*a[j]*(i+j+abs(i-j));
		A=min(A,s);
	}
	cout<<A;
	return 0;
}