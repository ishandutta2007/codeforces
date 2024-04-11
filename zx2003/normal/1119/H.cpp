#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=14e4,iv2=(mo+1)>>1;
int n,nn,i,j,x,y,z,a,b,c,s,A[N],B[N],C[N],mu[N];
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
inline void FWT(int*a){
	int i,j,k,m,x,y;
	for(i=1;i<=nn;++i)for(j=0,m=1<<(i-1);j<1<<nn;j+=1<<i)
		for(k=0;k<m;++k)x=a[j+k],y=a[j+k+m],a[j+k]=(x+y)%mo,a[j+k+m]=(x+mo-y)%mo;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>nn>>x>>y>>z;
	for(i=0;i<n;++i)cin>>a>>b>>c,s^=a,++A[b^a],++B[c^a],++C[c^b];
	FWT(A);FWT(B);FWT(C);
	for(i=0;i<1<<nn;++i){
		int p=1ll*iv2*(A[i]+n)%mo,q=1ll*iv2*(B[i]+n)%mo,r=1ll*iv2*(C[i]+n)%mo,
			u=(1ll*p+q+r+mo-n)*iv2%mo,v=(r+mo-u)%mo;
		A[i]=1ll*poww((1ll*x+y+z)%mo+mo,u)*
		poww((1ll*x+y-z)%mo+mo,p-u)%mo*
		poww((1ll*x-y+z)%mo+mo,n-p-v)%mo*
		poww((1ll*x-y-z)%mo+mo,v)%mo;
	}
	x=poww(iv2,nn);
	FWT(A);for(i=0;i<1<<nn;++i)B[i^s]=1ll*A[i]*x%mo;
	for(i=0;i<1<<nn;++i)cout<<B[i]<<' ';
	return 0;
}