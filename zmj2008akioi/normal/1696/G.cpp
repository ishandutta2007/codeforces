#include <cstdio>
#include <cstring>
const int N=2e5+10;
int n,q,x,y;
double d[3];
namespace basic{
	int res;char cdc;
	template<typename T>T md(T x,T y){return (x+y)/2;}
	template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
	template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
}using basic::md;using basic::cmax;using basic::swp;using basic::read;
struct matrix{
	double mx[3][3];
	matrix(){memset(mx,0,sizeof(mx));};
	matrix(int x){memset(mx,0,sizeof(mx)),mx[1][1]=d[1]*x,mx[2][2]=d[2]*x;}
	double operator()(){
		double res=0;
		for(int i=0;i<3;++i)for(int j=0;j<3;++j)cmax(res,mx[i][j]);
		return res;
	}
	matrix operator+(const matrix &nxt){
		matrix res;
		for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int p=0;p<3;++p)for(int q=0;p+q<3;++q)cmax(res.mx[i][j],mx[i][p]+nxt.mx[q][j]);
		return res;
	}
};
namespace SGT{
	const int L=1,R=5e5;
	matrix t[N<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return (x<<1)+1;}
	void pushup(int x){t[x]=t[lc(x)]+t[rc(x)];}
	void modify(int l,int r,int u,int g,int d){
		if(l==r)t[u]=matrix(d);
		else{
			if(md(l,r)>=g)modify(l,md(l,r),lc(u),g,d);
			else modify(md(l,r)+1,r,rc(u),g,d);
			pushup(u);
		}
	}
	matrix query(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)return t[u];
		else{
			if(md(l,r)<tl)return query(md(l,r)+1,r,rc(u),tl,tr);
			if(md(l,r)+1>tr)return query(l,md(l,r),lc(u),tl,tr);
			return query(l,md(l,r),lc(u),tl,tr)+query(md(l,r)+1,r,rc(u),tl,tr);
		}
	}
	void fm(int g,int d){modify(L,R,1,g,d);}
	double fq(int tl,int tr){return query(L,R,1,tl,tr)();}
}
int main(){
	n=read(),q=read(),x=read(),y=read();
	if(x>y)swp(x,y);d[1]=(double)1/(x+y),d[2]=(double)1/y;
	for(int i=1;i<=n;++i)SGT::fm(i,read());
	for(int opt,x,y,i=1;i<=q;++i){
		opt=read(),x=read(),y=read();
		if(opt==1)SGT::fm(x,y);
		if(opt==2)printf("%.10lf\n",SGT::fq(x,y));
	}
	return 0;
}