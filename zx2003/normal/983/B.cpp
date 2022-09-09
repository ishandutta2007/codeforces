#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=81970;
int n,a[N],q,l,r,f[N][N],i,b[M];
inline void FWT(int*a,int l){
	int i,j,k,m;
	for(i=1;i<l;i<<=1);
	memset(a+l+1,0,(i-l)<<2);l=i;
	for(i=2;i<=l;i<<=1)
		for(j=0,m=i>>1;j<l;j+=i)
			for(k=0;k<m;++k)
				a[j+k+m]^=a[j+k];
}
int Max(int a,int b){return a>b?a:b;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i){
		memcpy(b,a+i,(n-i+1)<<2);
		FWT(b,n-i+1);
		int j;
		for(j=i;j<=n;++j)
			f[i][j]=Max(f[i][j-1],b[j-i]);
	}
	for(i=n;i>1;--i)
		for(int j=i;j<=n;++j)
			f[i-1][j]=Max(f[i-1][j],f[i][j]);
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<f[l][r]<<'\n';
	}
	return 0;
}