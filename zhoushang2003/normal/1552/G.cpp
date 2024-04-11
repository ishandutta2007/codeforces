#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q[99],c[99],s[99][99],u,v,x;
void D(int x,int y)
{
	if(x>m)
	{
		y++,v|=((y&-y)!=y);
		return;
	}
	int z=__builtin_popcountll(y&s[x][q[x]]);
	y-=y&s[x][q[x]];
	for(int i=0;i<=c[x];i++)
		D(x+1,y|s[x][i+z]);
}
main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i];
		for(int j=1;j<=q[i];j++)
			cin>>x,c[i]+=!(u>>(x-1)&1),s[i][j]=s[i][j-1]+(1ll<<(x-1)),u|=(1ll<<(x-1));
	}
	D(1,0);
	cout<<(n>1&&(v||(u+1!=(1ll<<n)))?"REJECTED":"ACCEPTED");
}