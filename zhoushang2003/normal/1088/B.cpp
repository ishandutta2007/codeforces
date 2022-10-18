#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+1;
int n,k,a[N];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1]&&k)
			cout<<a[i]-a[i-1]<<endl,k--;
	while(k--)
		cout<<0<<endl;
	return 0;
}