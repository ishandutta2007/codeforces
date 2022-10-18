#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
int t,n,a[N],c[N],A[N],l,r;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			c[i]=A[i]=0;
		l=1,r=n,A[n]=1;
		for(int i=1;i<=n;i++)
			cin>>a[i],c[a[i]]++;
		for(int i=1;i<=n;i++)
		{
			if(!c[i])
				break;
			A[i]=1;
			if(c[i]>1||(a[l]!=i&&a[r]!=i))
				break;
			if(a[l]==i)
				l++;
			else
				r--;
		}
		for(int i=1;i<=n;i++)
			if(c[i]!=1)
				A[n]=0;
		for(int i=n;i>=1;i--)
			cout<<A[i];
		cout<<'\n';
	}
	return 0;
}