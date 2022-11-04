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
const int N=2005;
const int mo=998244353;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
namespace NTT{
	const int FFTN=1<<13;
	int w[FFTN+2],a[FFTN+2],b[FFTN+2];
	int c[FFTN+2],R[FFTN],LEN;
	void FFTpre(){
		w[0]=1; w[1]=power(3,(mo-1)/FFTN);
		For(i,2,FFTN-1) w[i]=1ll*w[i-1]*w[1]%mo;
	}
	void FFTinit(int sz){
		for (LEN=1;LEN<=sz;LEN<<=1);
		For(i,0,LEN-1) R[i]=(R[i>>1]>>1)|((i&1)?LEN/2:0);
	}
	void DFT(int *a,int n){
		For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
		for (int d=1,len=FFTN/2;d<n;d<<=1,len>>=1)
			for (int i=0;i<n;i+=d<<1)
				for (int j=i,p=0;j<i+d;j++,p+=len)
					a[j+d]=(a[j]+mo-1ll*a[j+d]*w[p]%mo)%mo,a[j]=(2ll*a[j]+mo-a[j+d])%mo;
	}
	void Mult(int *A,int *B,int *ans,int sza,int szb){
		FFTinit(sza+szb-2);
		For(i,0,LEN-1) a[i]=(i<sza?A[i]:0);
		For(i,0,LEN-1) b[i]=(i<szb?B[i]:0);
		DFT(a,LEN); DFT(b,LEN); 
		For(i,0,LEN-1) c[(LEN-1)&(LEN-i)]=1ll*a[i]*b[i]%mo;
		DFT(c,LEN);
		int v=power(LEN,mo-2);
		For(i,0,sza+szb-2)
			ans[i]=1ll*c[i]*v%mo;
	}	
}
int fac[N],inv[N],n;
int P[N],f[N],g[N][N];
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
/*
f[i][j]:i,j 
f[i][j]:sigma C(j,k)*(-1)^k*(i-k)!
*/ 
int tmp1[N*3],tmp2[N*3],tmp3[N*3];
void init(){
	P[0]=1; f[1]=0; f[2]=1; f[3]=2; fac[0]=1;
	For(i,4,n) f[i]=1ll*(i-1)*(f[i-1]+f[i-2])%mo;
	For(i,1,n) P[i]=1ll*P[i-1]*f[n]%mo;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,0,n) inv[i]=power(fac[i],mo-2);
	For(i,0,n){
		CLR(tmp1,0); CLR(tmp2,0); CLR(tmp3,0);
		For(j,0,i) tmp1[j]=1ll*(j&1?mo-fac[i-j]:fac[i-j])*inv[j]%mo;
		For(j,0,i) tmp2[j]=inv[j];
		NTT::Mult(tmp1,tmp2,tmp3,i+1,i+1);
		For(j,0,i) g[i][j]=1ll*tmp3[j]*fac[j]%mo;
	}
}
int vis[N],Vis[N];
int a[N][N];
int calc1(){
	int ans=0;
	For(i,1,n){
		int cnt=0;
		For(j,1,a[1][i]-1)
			if (!vis[j]) cnt++;
		ans=(ans+1ll*fac[n-i]*cnt)%mo;
		vis[a[1][i]]=1;
	}
	return ans;
}
struct Tarr{
	int t[N];
	void change(int x,int v){
		for (;x<=n;x+=x&(-x)) t[x]+=v;
	}
	int ask(int x){
		int ans=0;
		for (;x;x-=x&(-x)) ans+=t[x];
		return ans;
	}
	void init(){
		memset(t,0,sizeof(t));
	}
}t[2];
int calc2(int id){
	int ans=0,cnt=n;
	memset(vis,0,sizeof(vis));
	memset(Vis,0,sizeof(Vis));
	t[0].init(); t[1].init();
	For(i,1,n) t[0].change(i,1);
	for (int i=1;i<=n;i++){
		Vis[a[id-1][i]]=1;
		vis[a[id][i]]=1;
		cnt-=1-vis[a[id-1][i]];
		int lasv=(vis[a[id-1][i]]?0:1);
		if (lasv) t[0].change(a[id-1][i],-1);
		if (cnt) ans=(ans+1ll*g[n-i][cnt-1]*t[0].ask(a[id][i]-1))%mo;
		ans=(ans+1ll*g[n-i][cnt]*t[1].ask(a[id][i]-1))%mo;
		if (lasv) t[1].change(a[id-1][i],1);
		t[Vis[a[id][i]]].change(a[id][i],-1);
		cnt-=1-Vis[a[id][i]];
	}
	return ans;
}
//<=a[id][i],preunvisited,differfrom now
//exist in pre
int main(){
	NTT::FFTpre();
	scanf("%d",&n);
	init();
	For(i,1,n) For(j,1,n)
		scanf("%d",&a[i][j]);
	int ans=1ll*calc1()*P[n-1]%mo;
	For(i,2,n)
		ans=(ans+1ll*calc2(i)*P[n-i])%mo;
	printf("%d\n",ans);
}