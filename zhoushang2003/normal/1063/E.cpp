#import<bits/stdc++.h>
using namespace std;
const int N=2000;
char A[N][N];
int n,p[N],x,c,v[N];
void W(int x,int y)
{
	if(x<y)
		A[c][x]='/',A[c--][y]='/';
	else
		A[c][x]='\\',A[c--][y]='\\';
}
main()
{
	cin>>n,c=n;
	for(int i=1;i<=n;i++)
		cin>>x,p[x]=i;
	x=p[1];
	while(x!=1)
		W(p[x],x),v[x]=1,x=p[x];
	for(int i=2;i<=n;i++)
		if(!v[i]&&p[i]!=i)
		{
			A[c][1]='\\',x=i;
			while(p[x]!=i)
				W(p[x],x),x=p[x],v[x]=1;
			W(1,x);
		}
	cout<<n-(c<n)<<'\n';
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			cout<<(A[i][j]?A[i][j]:'.');
}