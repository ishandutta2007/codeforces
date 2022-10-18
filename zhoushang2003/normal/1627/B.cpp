#import<bits/stdc++.h>
using namespace std;
int n,m,A[9999999],t;
int D(int x,int y,int z,int w)
{
	return abs(x-z)+abs(y-w);
}
main()
{
	for(cin>>n;cin>>n>>m;)
	{
		t=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				A[++t]=max(max(D(i,j,1,1),D(i,j,1,m)),max(D(i,j,n,1),D(i,j,n,m)));
		sort(A+1,A+t+1);
		for(int i=1;i<=t;i++)
			cout<<A[i]<<' ';
		puts("");
	}
}