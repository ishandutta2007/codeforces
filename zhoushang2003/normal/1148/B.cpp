#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,x,y,k,a[N],b[N],l,r,A;
int main()
{
	cin>>n>>m>>x>>y>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		a[i]+=x;
	if(n<=k)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(i<=k+1)
		{
			l=1,r=m;
			while(l<r)
				if(b[(l+r)/2]<a[i])
					l=(l+r)/2+1;
				else
					r=(l+r)/2;
			if(b[l]<a[i]||l+k-i+1>m)
			{
				cout<<-1;
				return 0;
			}
			A=max(A,b[l+k-i+1]+y);
		}
	cout<<A;
	return 0;
}