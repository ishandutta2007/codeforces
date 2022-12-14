#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long t,n,m,a[N],s,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=m;i++)
			cin>>a[i];
		s=0;
		for(int i=1;i<=m;i++)
			s+=a[i];
		if(s<n)
		{
			cout<<-1<<'\n';
			continue;
		}
		sort(a+1,a+m+1),A=0;
		while(m)
			if(a[m]<=n)
				n-=a[m],s-=a[m--];
			else if(s-a[m]<n)
				a[m]/=2,a[m+1]=a[m],m++,A++;
			else
				s-=a[m--];
		cout<<A<<'\n';
	}
	return 0;
}