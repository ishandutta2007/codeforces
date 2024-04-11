#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],b[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=n;i;i--)
		a[i]-=a[i-1],b[i]-=b[i-1];
	sort(a+2,a+n+1),sort(b+2,b+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
		{
		    cout<<"No";
		    return 0;
		}
	cout<<"Yes";
	return 0;
}