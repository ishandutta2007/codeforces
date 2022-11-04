#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
int mo;
struct COMPLEX{
	db r,i;
	COMPLEX(){}
	COMPLEX(db _r,db _i){r=_r,i=_i;}
	COMPLEX operator +(const COMPLEX &a)const{
		return COMPLEX(r+a.r,i+a.i);
	}
	COMPLEX operator -(const COMPLEX &a)const{
		return COMPLEX(r-a.r,i-a.i);
	}
	COMPLEX operator *(const COMPLEX &a)const{
		return COMPLEX(r*a.r-i*a.i,r*a.i+i*a.r);
	}
	COMPLEX conj()const{
		return COMPLEX(r,-i);
	}
};
const int FFTN=1<<16;
COMPLEX w[FFTN+2],a[FFTN+2],b[FFTN+2];
int R[FFTN],LEN;
const db pi=acos(-1);
void prepare(){
	For(i,0,FFTN-1) w[i]=COMPLEX(cos(2*pi*i/FFTN),sin(2*pi*i/FFTN));
}
void FFTinit(int sz){
	LEN=1; int L=0;
	for (;LEN<=sz;LEN<<=1,L++);
	For(i,0,LEN-1) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
}
void DFT(COMPLEX *a,int n){
	For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0;i<n;i+=d<<1)
			for (int j=i,p=0;j<i+d;j++,p+=len)
				a[j+d]=a[j]-a[j+d]*w[p],a[j]=a[j]+a[j]-a[j+d];
	}
}
const int N=30005;
int f[2][N],n,ans,mxv;
void solve(int mx){
	if (mx==1){
		f[0][0]=f[1][1]=ans=1;
		return;
	}
	solve(mx/2);
	For(i,0,LEN-1) a[i]=(i<=n?COMPLEX(f[0][i],f[1][i]):COMPLEX(0,0));
	DFT(a,LEN);
	For(i,0,LEN-1){
		int ano=(LEN-i)&(LEN-1);
		COMPLEX v0=(a[i]+a[ano].conj())*COMPLEX(0.5,0);
		COMPLEX v1=(a[i]-a[ano].conj())*COMPLEX(0,-0.5);
		b[ano]=(v0+v1)*v1+(v0+v1)*(v0-COMPLEX(1,0))*COMPLEX(0,1);
	}
	DFT(b,LEN);
	For(i,0,n){
		int v1=(ll)(b[i].r/LEN+0.49)%mo;
		int v0=(ll)(b[i].i/LEN+0.49)%mo;
		if (mx&2) swap(v0,v1);
		f[0][i]=(f[0][i]+v0)%mo;
		f[1][i]=(f[1][i]+v1)%mo;
	}
	if (mx&1)
		Rep(i,n,1)
			f[1][i]=(f[1][i]+f[1][i-1]+1ll*f[0][i-1])%mo;
	for (int i=1;i<=n;i+=2)
		ans=(ans+f[1][i])%mo; 
}
int main(){
	scanf("%d%d%d",&n,&mxv,&mo);
	if (mxv==1) return puts("0"),0;
	prepare(); FFTinit(2*n);
	solve(mxv/2);
	printf("%d\n",ans);
}