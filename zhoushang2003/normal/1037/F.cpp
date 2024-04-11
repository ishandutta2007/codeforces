#import<bits/stdc++.h>
using namespace std;
const int N=1e6+1,M=20,D=1e9+7;
int n,k,a[N],u[N][M],l,A;
long long f[N];
int H(int x,int y)
{
	return a[x]>a[y]?x:y;
}
int U(int x,int y)
{
	l=log2(y-x+1);
	return H(u[x][l],u[y-(1<<l)+1][l]);
}
void S(int l,int r)
{
	if(r-l+1<k)
		return;
	int d=U(l,r);
	(A+=(f[r-l+1]-f[d-l]-f[r-d])%D*a[d]%D)%=D,S(l,d-1),S(d+1,r);
}
main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],u[i][0]=i,f[i]=f[i-1]+(i-1)/(k-1);
	for(int i=1;i<M;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			u[j][i]=H(u[j][i-1],u[j+(1<<(i-1))][i-1]);
	S(1,n);
	cout<<A;
}