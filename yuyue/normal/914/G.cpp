#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=1e9+7,lim=(1<<17),M=1e6+10,N=lim+10,inv2=(mod+1)/2;

void FWTxor(LL *f,int op){
	for (int p=2;p<=lim;p<<=1){
		int len=p>>1;
		for (int k=0;k<lim;k+=p){
			for (int l=k;l<k+len;l++){
				LL x=(f[l]+f[l+len])%mod,y=(f[l]+mod-f[l+len])%mod;
				f[l]=x; f[l+len]=y;
				if (op==-1) f[l]=f[l]*inv2%mod,f[l+len]=f[l+len]*inv2%mod; 
			}
		}
	}
}
void FWTor(LL *f,int op){
	for (int p=2;p<=lim;p<<=1){
		int len=p>>1;
		for (int k=0;k<lim;k+=p){
			for (int l=k;l<k+len;l++){
				f[l+len]=(f[l]*op+f[l+len]+mod)%mod;
			}
		}
	}
}
void FWTand(LL *f,int op){
	for (int p=2;p<=lim;p<<=1){
		int len=p>>1;
		for (int k=0;k<lim;k+=p){
			for (int l=k;l<k+len;l++){
				f[l]=(f[l]+f[l+len]*op+mod)%mod;
			}
		}
	}
}
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int a[M];
LL f1[18][N],f2[N],f3[N],t[18][N],f4[N];
LL f[N];
int sz[N];
int n;
int main(){
	n=read();
	F(i,0,lim-1) sz[i]=sz[i>>1]+(i&1);
	F(i,1,n) {
		a[i]=read();
		f1[sz[a[i]]][a[i]]++;
		f2[a[i]]++; f3[a[i]]++;
	}
	f[0]=0; f[1]=1; 
	F(i,2,lim) f[i]=(f[i-1]+f[i-2])%mod;
	F(i,0,17){
		FWTor(f1[i],1);
	}
	F(i,0,17){
		F(k,0,lim-1)
		F(j,0,i){
			t[i][k]=(t[i][k]+f1[j][k]*f1[i-j][k])%mod;
		}
		FWTor(t[i],-1);
	}
	F(i,0,lim-1){
		f4[i]=t[sz[i]][i]*f[i]%mod;
	}
	FWTxor(f3,1);
	F(i,0,lim-1) f3[i]=f3[i]*f3[i]%mod; 
	FWTxor(f3,-1);
	F(i,0,lim-1){
		f2[i]=f2[i]*f[i]%mod;
		f3[i]=f3[i]*f[i]%mod;
	}
	FWTand(f2,1); FWTand(f3,1); FWTand(f4,1);
	F(i,0,lim-1) f2[i]=f2[i]*f3[i]%mod*f4[i]%mod;
	FWTand(f2,-1);
	LL ans=0;
	F(i,0,17) ans=(ans+f2[1<<i])%mod;
	cout<<ans<<"\n";
	return 0;
}