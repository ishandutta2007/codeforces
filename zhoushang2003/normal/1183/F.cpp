#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int t,n,a[N],A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		A=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]%a[j]==0)
					continue;
				for(int k=j-1;k>=1;k--)
					if(a[i]%a[k]!=0&&a[j]%a[k]!=0)
					{
						A=max(A,a[i]+a[j]+a[k]);
						break;
					}
				A=max(A,a[i]+a[j]);
				break;
			}
			A=max(A,a[i]);
		}
		cout<<A<<'\n';
	}
	return 0;
}