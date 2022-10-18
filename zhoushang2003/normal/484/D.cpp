#include<iostream>
using namespace std;
const int I=1e9;
long long n,x,f=-I,g=-I,A;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		f=max(f,A-x);
		g=max(g,A+x);
		A=max(A,max(f+x,g-x));
	}
	cout<<A;
	return 0;
}