#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1005,mod=998244353;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n;
pair <int,int> a[N];
int Fac[N];
int C[N][N],S[N][N];
void prework(){
	Fac[0]=1;
	For(i,1,n)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	C[0][0]=S[0][0]=1;
	For(i,1,n){
		C[i][0]=1;
		For(j,1,i){
			C[i][j]=Add(C[i-1][j-1]+C[i-1][j]);
			S[i][j]=((LL)(i-1)*S[i-1][j]+S[i-1][j-1])%mod;
		}
	}
}
int pre[N],nxt[N],vis[N],isfi[N],isla[N];
int ans[N];
int F[N],G[N],H[N];
void Mul(int *a,int *b,int *c){
	static int res[N];
	clr(res);
	For(i,0,n)
		For(j,0,n)
			res[i+j]=(res[i+j]+(LL)a[i]*b[j])%mod;
	For(i,0,n)
		c[i]=res[i];
}
int main(){
	n=read();
	prework();
	//  0->0,0->x,x->0,x
	int va=0,vb=0,vc=0,vd=0;
	For(i,1,n)
		a[i].fi=read();
	For(i,1,n)
		a[i].se=read();
	For(i,1,n){
		if (a[i].fi&&a[i].se){
			pre[a[i].se]=a[i].fi;
			nxt[a[i].fi]=a[i].se;
		}
		else if (a[i].fi)
			isla[a[i].fi]=1;
		else if (a[i].se)
			isfi[a[i].se]=1;
		else
			va++;
	}
//	outarr(isfi,1,n);outarr(isla,1,n);
	For(i,1,n){
		if (vis[i])
			continue;
		vis[i]=1;
		int s=i,t=i;
		while (pre[s]&&!vis[pre[s]])
			s=pre[s],vis[s]=1;
		while (nxt[t]&&!vis[nxt[t]])
			t=nxt[t],vis[t]=1;
		if (pre[s]==t)
			vd++;
		else if (isfi[s]&&!isla[t])
			vb++;
		else if (!isfi[s]&&isla[t])
			vc++;
		else if (isfi[s]&&isla[t])
			va++;
	}
//	outval(va),outval(vb),outval(vc),outval(vd);
	For(i,0,va)
		F[i]=(LL)S[va][i]*Fac[va]%mod;
	For(i,0,vb)
		For(j,i,vb)
			G[i]=(G[i]+(LL)S[j][i]*C[vb][j]%mod
				*(j==vb?1:C[va-1+vb-j][va-1])%mod*Fac[vb-j])%mod;
	For(i,0,vc)
		For(j,i,vc)
			H[i]=(H[i]+(LL)S[j][i]*C[vc][j]%mod
				*(j==vc?1:C[va-1+vc-j][va-1])%mod*Fac[vc-j])%mod;
//	outarr(F,0,n);outarr(G,0,n);outarr(H,0,n);
	Mul(F,G,F);
	Mul(F,H,F);
	For(i,0,va+vb+vc)
		ans[n-(i+vd)]=F[i];
	For(i,0,n-1)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}