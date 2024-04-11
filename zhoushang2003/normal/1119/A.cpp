#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
int n,c[N],l,r;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		if(c[i]!=c[1])
			r=i;
	for(int i=n;i>=1;i--)
		if(c[i]!=c[n])
			l=i;
	cout<<max(r-1,n-l); 
	return 0;
}