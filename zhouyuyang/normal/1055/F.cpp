#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define inf (1ll<<60) 
using namespace std;

namespace FastInput{
	const int LBC=2333333;
	char LZH[LBC],*SSS=LZH,*TTT=LZH;
	inline char gc(){
		if (SSS==TTT){
			TTT=(SSS=LZH)+fread(LZH,1,LBC,stdin);
			if (SSS==TTT) return EOF;
		}
		return *SSS++;
	}
	inline ll read(){
		ll x=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			x=x*10-48+ch;
		return x;
	}
}
using namespace FastInput;
const ll N=1000005;
ll all,ans,k;
ll f[N],b[N],q[N];
int n;
void work(int x){
	ll rest=all^(1ll<<x);
	for (int j=1,l,r;j<=n;j=r){
		l=r=j+1;
		for (;l<=n&&(b[l]&all)==(b[j]&all);l++);
		for (;r<=n&&(b[r]&rest)==(b[j]&rest);r++);
		int tmp=j;
		For(k,l,r-1) q[tmp++]=b[k];
		For(k,j,l-1) q[tmp++]=b[k];
		For(k,j,r-1) b[k]=q[k];
	}
}
int main(){
	n=read(); k=read();
	For(i,2,n){
		int x=read();
		f[i]=f[x]^read();
	}
	sort(f+1,f+n+1);
	For(i,1,n) b[i]=f[i];
	Rep(i,61,0){
		all|=1ll<<i;
		ll s=0;
		int l=1,r=1;
		For(j,1,n){
			ll t=(b[j]^ans)&all;
			for (;l<=n&&(f[l]&all)<t;l++);
			for (;r<=n&&(f[r]&all)<=t;r++);
			s+=r-l;
		}
		if (s<k){
			ans|=1ll<<i;
			work(i);
			k-=s;
		}
	}
	printf("%lld",ans);
}