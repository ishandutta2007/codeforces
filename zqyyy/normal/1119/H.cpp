#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1<<17,mod=998244353,inv2=(mod+1)>>1,inv4=mod-(mod-1)/4;
inline void inc(int &x,int y){x+=y;if(x>=mod)x-=mod;}
inline void dec(int &x,int y){x-=y;if(x<0)x+=mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;	
}
inline void FWT(int n,int *f){
	for(int len=2,p=1;len<=n;p=len,len<<=1)
		for(int i=0;i<n;i+=len)
			for(int j=0;j<p;j++){
				int l=i|j,r=l|p,t=f[l];
				f[l]+=f[r],f[r]=t-f[r];
			}
}
inline void IFWT(int n,int *f){
	for(int len=2,p=1;len<=n;p=len,len<<=1)
		for(int i=0;i<n;i+=len)
			for(int j=0;j<p;j++){
				int l=i|j,r=l|p,t=f[l];
				inc(f[l],f[r]),f[r]=(t+mod-f[r])%mod;
			}
	int inv=mod-(mod-1)/n;
	for(int i=0;i<n;i++)f[i]=1ll*f[i]*inv%mod;
}
int n,m,K,x,y,z,All;
int pw1[N],pw2[N],pw3[N],pw4[N];
int f[N],f1[N],f2[N],f3[N];
int main(){
	m=read(),K=read(),n=1<<K,z=read(),x=read(),y=read();
	for(int i=1,x,a,b;i<=m;i++){
		x=read(),a=read()^x,b=read()^x;
		All^=x,f1[a]++,f2[b]++,f3[a^b]++;
	}
	FWT(n,f1),FWT(n,f2),FWT(n,f3);
	/*
		1:x+y+z
		2:x-y+z
		3:-x+y+z
		4:-x-y+z
		x1+x2+x3+x4=m;
		x1+x2-x3-x4=f1[i]
		x1-x2+x3-x4=f2[i]
		x1-x2-x3+x4=f3[i]
	*/
	pw1[0]=pw2[0]=pw3[0]=pw4[0]=1;
	const int A=((ll)x+y+z)%mod,B=((ll)x+mod-y+z)%mod,C=((ll)mod-x+y+z)%mod,D=((ll)(mod<<1)-x-y+z)%mod;
	for(int i=1;i<=m;i++){
		pw1[i]=1ll*pw1[i-1]*A%mod;
		pw2[i]=1ll*pw2[i-1]*B%mod;
		pw3[i]=1ll*pw3[i-1]*C%mod;
		pw4[i]=1ll*pw4[i-1]*D%mod;
	}
	for(int i=0;i<n;i++){
		int x1=(m+f1[i]+f2[i]+f3[i])>>2;
		int x2=(m+f1[i]-2*x1)>>1;
		int x3=(m+f2[i]-2*x1)>>1;
		int x4=(m+f3[i]-2*x1)>>1;
		f[i]=1ll*pw1[x1]*pw2[x2]%mod*pw3[x3]%mod*pw4[x4]%mod;
	}
	IFWT(n,f);
	for(int i=0;i<n;i++)
		printf("%d%c",f[i^All]," \n"[i==n-1]);
	return 0;
}