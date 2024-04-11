#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,a[N],b[N],x=1; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	if(n==3)
		cout<<"1 2 3";
	else
		for(int i=1;i<=n;i++)
		{
			cout<<x<<" ";
			if(a[a[x]]==b[x]||b[a[x]]==b[x])
				x=a[x];
			else
				x=b[x];
		}
	return 0;
}