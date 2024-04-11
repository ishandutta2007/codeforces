#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,a[N],b[N],s,A,I=99,v[21][N];
pair<int,int>p[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<N;j++)
			p[j]=make_pair(0,j);
		for(int j=1;j<=n;j++)
			p[a[j]].first+=min(b[j],i);
		sort(p+1,p+N),s=0;
		for(int j=N-1;j>=N-i;j--)
			s+=p[j].first,v[i][p[j].second]=1;
		if(s*I>A*i)
			A=s,I=i;
	}
	cout<<I<<'\n';
	for(int i=1;i<N;i++)
		if(v[I][i])
			cout<<i<<' ';
	return 0;
}