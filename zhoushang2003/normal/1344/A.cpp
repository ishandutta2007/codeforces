#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int t,n,a[N],A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i],a[i]=(a[i]%n+n+i)%n;
		sort(a,a+n),A=1;
		for(int i=1;i<n;i++)
			if(a[i]==a[i-1])
				A=0;
		if(A)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}