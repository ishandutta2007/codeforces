#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],c;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]%2==0)
			cout<<a[i]/2<<'\n';
		else if(c&1)
			cout<<(a[i]+1)/2<<'\n',c++;
		else
			cout<<(a[i]-1)/2<<'\n',c++;
	return 0;
}