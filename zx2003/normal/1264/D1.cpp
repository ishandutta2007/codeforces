#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mo=998244353;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 0<=m && m<=n?1ll*vf[m]*vf[n-m]%mo*fac[n]%mo:0;}
char c[N];
int i,ans,c1,c2,c3,c4,a[N],b[N],j,k;
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%s",c+1);
	for(i=1;c[i];++i)c3+=c[i]==')',c4+=c[i]=='?';
	for(i=1;c[i+1];++i){
		c3-=c[i]==')';c4-=c[i]=='?';
		c1+=c[i]=='(';c2+=c[i]=='?';
		ans=(ans+1ll*c2*C(c2+c4-1,c1+c2-c3)+1ll*c1*C(c2+c4,c1+c2-c3))%mo;
	}
	printf("%d\n",ans);
	return 0;
}