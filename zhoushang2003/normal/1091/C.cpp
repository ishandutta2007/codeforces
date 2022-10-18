#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5;
int c;
long long n,A[N];
int main()
{
	cin>>n;
	for(long long i=1;i*i<=n;i++)
		if(n%i==0)
			A[c++]=(n-i+2)*n/i/2,A[c++]=(n-n/i+2)*i/2;
	sort(A,A+c);
	cout<<A[0]<<" ";
	for(int i=1;i<c;i++)
		if(A[i]!=A[i-1])
			cout<<A[i]<<" ";
	return 0;
}