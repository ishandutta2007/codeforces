#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,l[N],r[N],k,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	cin>>k;
	for(int i=1;i<=n;i++)
		if(k<=r[i])
			A++;
	cout<<A;
	return 0;
}