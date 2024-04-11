#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int n,a[N],M,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		M=max(M,a[i]);
		if(M==i)
			A++;
	}
	cout<<A;
	return 0;
}