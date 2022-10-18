#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n,a[N],k,v,A;
int main()
{
	cin>>T;
	while(T--&&cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		v=A=0;
		for(int i=1;i<=n;i++)
			if(a[i]==k)
				v=1;
		if(!v)
		{
			cout<<"no"<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=min(n,i+2);j++)
				if(a[i]>=k&&a[j]>=k)
					A=1;
		if(A||n==1)
			cout<<"yes"<<'\n';
		else
			cout<<"no"<<'\n';
	}
	return 0;
}