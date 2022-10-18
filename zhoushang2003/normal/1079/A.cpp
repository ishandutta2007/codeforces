#include<iostream>
using namespace std;
const int N=101;
int n,k,A,x,M,c[N],s;
int main()
{
	cin>>n>>k;
	A=n;
	while(n--&&cin>>x)
		c[x]++;
	for(int i=1;i<N;i++)
		if(c[i]>0)
			s++,M=max(M,c[i]);
	cout<<((M-1)/k+1)*k*s-A;
	return 0;
}