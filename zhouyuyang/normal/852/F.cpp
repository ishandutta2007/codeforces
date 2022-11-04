
 #include<bits/stdc++.h>
#define inv(x) (((x)==0)?1:ksm(x,mod-2,mod))
#define N 3000009
#define ll long long
using namespace std;

int n,m,A,Q,mod,f[N],fac[N];
int ksm(int x,int y,int p){
	int z=1; for (; y; y>>=1,x=(ll)x*x%p) if (y&1) z=(ll)z*x%p;
	return z;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&A,&Q);
	int i;
	for (i=A%Q,mod=1; i!=1; mod++) i=(ll)i*A%Q;
	fac[0]=1;
	for (i=1; i<mod; i++) fac[i]=(ll)fac[i-1]*i%mod;
	f[0]=1;
	for (i=1; i<=m; i++)
		f[i]=(f[i-1]+(ll)fac[m]*inv(fac[i])%mod*inv(fac[m-i]))%mod;
	for (i=m+1; i<=n; i++) f[i]=f[i-1];
	for (i=n; i; i--)
		printf("%d%c",ksm(A,f[i-1],Q),(i>1)?' ':'\n');
}