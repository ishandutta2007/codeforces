#import<bits/stdc++.h>
using namespace std;
const int N=3e3; 
int n,k,x,y,a,b,c,d,A[N][N];
pair<int,int>p[N*N];
main()
{
	ios::sync_with_stdio(0),cin>>n>>k,a=b=c=d=-1e9;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>x,p[x]={i,j};
	for(int i=n*n;i;i--)
		if(a<=(x=p[i].first)+(y=p[i].second)+k&&b<=x-y+k&&c<=-x+y+k&&d<=-x-y+k)
			a=max(a,x+y),b=max(b,x-y),c=max(c,-x+y),d=max(d,-x-y),A[x][y]=1;
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=n;j++)
			cout<<(A[i][j]?"M":"G");
}