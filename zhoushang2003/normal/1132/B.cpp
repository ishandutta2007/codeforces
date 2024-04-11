#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long n,a[N],s,m,x;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		s+=a[i];
	cin>>m;
	while(m--&&cin>>x)
		cout<<s-a[n-x]<<endl;
	return 0;
}