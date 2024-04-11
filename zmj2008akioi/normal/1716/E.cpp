#include <cstdio>
const int B=600,N=3e5+10;
int n,m,v,q,w,g,a[N],b[N];
struct node{
	long long l,r,s,mx;
	node():l(0),r(0),s(0),mx(0){};
}t[B][B];
template<typename T>T min(T x,T y){return x<y?x:y;}
template<typename T>T max(T x,T y){return x>y?x:y;}
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
node merge(node a,node b){
	node res;res.s=a.s+b.s;
	res.l=max(a.l,a.s+b.l);
	res.r=max(b.r,b.s+a.r);
	res.mx=max(a.r+b.l,max(a.mx,b.mx));
	return res;
}
long long calc(){
	node res=t[g][w];
	for(int i=1;i<v;++i)res=merge(res,t[g^i][w]);
	return res.mx;
}
int main(){
	scanf("%d",&n),m=1<<n;
	for(int i=0;i<m;++i)scanf("%d",&a[i]);
	int p=min(m,1<<9);v=m/p;
	for(int i=0;i<m;i+=p){
		int c=i/p;
		for(int j=0;j<p;++j){
			for(int k=0;k<p;++k)b[k^j]=a[i+k];
			long long ls=0,rs=0,rec=0;
			for(int k=0;k<p;++k)cmax(t[c][j].l,ls+=b[k]);
			for(int k=p-1;~k;--k)cmax(t[c][j].r,rs+=b[k]);
			for(int k=0;k<p;++k)t[c][j].s+=b[k];ls=0;
			for(int k=0;k<p;++k)cmin(rec,ls+=b[k]),cmax(t[c][j].mx,ls-rec);
		}
	}
	scanf("%d",&q);
	for(int t,i=0;i<q;++i){
		scanf("%d",&t);
		if((1<<t)<p)w^=1<<t;
		else g^=(1<<t)/p;
		printf("%lld\n",calc());
	}
	return 0;
}