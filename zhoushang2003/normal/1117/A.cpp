#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N],M,c,A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		M=max(M,a[i]);
	for(int i=0;i<n;i++)
		if(a[i]==M)
			c++,A=max(A,c);
		else
			c=0;
	cout<<A;
	return 0;
}