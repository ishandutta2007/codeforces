#include <cstdio>
const int N=3e5+10,P=998244353;
const int b[1]={1};
int n,m,a[N];
template<typename T>T sq(T x){return x*x;}
template<typename T>T min(T x,T y){return x<y?x:y;}
template<typename T>T max(T x,T y){return x>y?x:y;}
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
int psqrt(int x){return x;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=1ll*nw*nw%P)if(rm&pw)rm^=pw,rs=1ll*rs*nw%P;
	return rs;
}
namespace IO{
	int lt,nw,res,dig[30];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using IO::read;using IO::write;
namespace NTT{
	int len,pa[N],pb[N],pc[N],rev[N],cyc[N];
	int cir(int k,int t){return cyc[(k<0?k+t:k)*(len/t)];}
	void init(){
		int w=len>>1,d=qpow(3,(P-1)/len);cyc[0]=1;
		for(int i=1;i<len;++i)cyc[i]=1ll*cyc[i-1]*d%P;
		for(int i=1;i<len;++i)rev[i]=(rev[i>>1]>>1)|(w*(i&1));
	}
	void ntt(int *a,int p){
		for(int i=1;i<len;++i)if(rev[i]<i)swp(a[rev[i]],a[i]);
		for(int t=2;t<=len;t<<=1){
			int s=t>>1;
			for(int i=0;i<len;i+=t){
				for(int j=0;j<s;++j){
					int x=a[i+j],y=1ll*a[i+j+s]*cir(p*j,t)%P;
					a[i+j]=(x+y)%P,a[i+j+s]=(x-y+P)%P;
				}
			}
		}
	}
	void work(int n,int m,int *a,int *b,int *c){
		len=1;while(len<=n+m+1)len<<=1;init();
		for(int i=0;i<len;++i)pa[i]=pb[i]=0;
		for(int i=0;i<=n;++i)pa[i]=a[i];for(int i=0;i<=m;++i)pb[i]=b[i];
		ntt(pa,1),ntt(pb,1);for(int i=0;i<len;++i)pc[i]=1ll*pa[i]*pb[i]%P;
		ntt(pc,-1);for(int iv=qpow(len,P-2),i=0;i<=n+m;++i)c[i]=1ll*pc[i]*iv%P;
	}
}
struct poly{
	int n,*a;poly(){};
	poly(int n,const int *b=NULL):n(n){
		a=new int[n+1];
		for(int i=0;i<=n;++i){
			if(b==NULL)a[i]=0;
			else a[i]=b[i];
		}
	}
	int& operator[](int x)const{return a[x];}
	poly operator>>(int x)const{
		poly res(x);
		for(int i=0;i<=min(n,x);++i)res[i]=a[i];
		return res;
	}
	poly operator*(int w)const{
		poly res(n);
		for(int i=0;i<=n;++i)res[i]=1ll*a[i]*w%P;
		return res;
	}
	poly operator+(poly nxt)const{
		poly res(max(n,nxt.n));
		for(int i=0;i<=n;++i)res[i]=a[i];
		for(int i=0;i<=nxt.n;++i)res[i]=(res[i]+nxt[i])%P;
		return res;
	}
	poly operator-(poly nxt)const{
		poly res(max(n,nxt.n));
		for(int i=0;i<=n;++i)res[i]=a[i];
		for(int i=0;i<=nxt.n;++i)res[i]=(res[i]-nxt[i]+P)%P;
		return res;
	}
	poly operator*(poly nxt)const{
		poly res(n+nxt.n);
		NTT::work(n,nxt.n,a,nxt.a,res.a);
		return res;
	}
	poly operator~()const{
		poly res(0);res[0]=qpow(a[0],P-2);
		for(int t,i=2;i<=(n<<1);i<<=1)t=i-1,res=(res*2-(*this>>t)*(sq(res)>>t))>>t;
		return res>>n;
	}
	void print(int l,int r){for(int i=l;i<=r;++i)write(a[i]);}
};
const poly I=poly(0,b);
poly sqrt(poly A){
	poly res(0);res[0]=psqrt(A[0]);
	for(int t,i=2;i<=(A.n<<1);i<<=1)t=i-1,res=(~((res*2)>>t)*((A>>t)+(sq(res)>>t)))>>t;
	return res>>A.n;
}
int main(){
	n=read(),m=read();for(int i=1;i<=n;++i)++a[read()];
	(~(I+sqrt(I-poly(m,a)*4))*2).print(1,m);return 0;
}