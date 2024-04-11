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
const int M=(1<<17)+10,mod=998244353,inv2=(mod+1)/2;
int lim;
void FWT(LL *f,int op){
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
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL f[M],h[10][M],t[10],a[10];
int n,k,p[M][10];
int main(){
	n=read(); k=read(); lim=(1<<k);
	LL x=read(),y=read(),z=read();
	a[0]=x+y+z; a[1]=x-y+z; a[2]=x+y-z; a[3]=x-y-z; 
	F(i,0,3) a[i]=(a[i]+2*mod)%mod;
	int org=0;
	F(i,1,n){
		F(j,0,2)
		p[i][j]=read();
		F(j,1,2) p[i][j]^=p[i][0];
		org^=p[i][0];
//		cout<<p[i][1]<<"\n";
	}
	F(i,1,3){
		F(j,1,n){
			int tmp=0;
			if (i&1) tmp^=p[j][1];
			if (i&2) tmp^=p[j][2];
			h[i][tmp]++;
//			cout<<tmp<<"   cnm\n";
		}
		FWT(h[i],1);
//		cout<<h[i][0]<<" "<<h[i][1]<<"     omg\n";
	}
	F(i,0,(1<<k)-1){
		t[0]=n;
		F(j,1,3) t[j]=h[j][i];
//		F(j,0,3){
//			cout<<t[j]<<" o ";
//		}
//		cout<<"\n";
		lim=4; 
		FWT(t,-1);
//		F(j,0,3){
//			cout<<t[j]<<" o ";
//		}
//		cout<<"\n";
		f[i]=1;
		F(j,0,3){
			f[i]=f[i]*fast(a[j],t[j])%mod;
		}
	}
	lim=(1<<k); FWT(f,-1);
	F(i,0,lim-1){
		cout<<f[i^org]<<" ";
	}
	return 0;
}