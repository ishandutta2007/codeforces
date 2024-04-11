#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,k,a[N],r,s,A,B;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		r=s=B=0,A=1;
		for(int i=1;i<=n;s-=a[i++])
		{
			if(r<i)
				r=i-1,s=0;
			while(r<n&&s+a[r+1]+k>=0)
			{
				s+=a[++r];
				if(r-i>B-A)
					A=i,B=r;
			}
		}
		if(A>B)
			cout<<-1<<'\n';
		else
			cout<<A<<' '<<B<<'\n';
	}
}