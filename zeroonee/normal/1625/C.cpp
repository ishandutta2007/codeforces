#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=502;
int d[N],a[N],f[N][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k,i,j,l;
	cin>>n>>m>>k;k=n-k;
	for (i=0;i<n;i++) cin>>d[i];d[n]=m;
	for (i=0;i<n;i++) cin>>a[i];
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) for (l=0;l<i;l++) f[i][j]=min(f[i][j],f[l][j-1]+a[l]*(d[i]-d[l]));
	//for (j=0;j<=n;j++) cerr<<f[n][j]<<'\n';
	cout<<*min_element(f[n]+k,f[n]+n+1)<<endl;
}