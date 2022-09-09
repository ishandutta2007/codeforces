#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ibuf[1<<23],*ih=ibuf,obuf[1<<22],*oh=obuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
inline void out(ll x){
	if(!x){*oh++='0';return;}
	static int buf[30];int xb=0;
	for(;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
const int N=2e5+5;
int n,a[N],l,r,k,i,x,lst[N],L[N],R[N],va[N];ll la;
inline ll C2(int x){return x>0?1ll*(x+1)*x>>1:0;}
inline ll F(int a,int b,int c,int d){return C2(min(d,b)-max(c,a)+1);}
struct atom{
	int x1,x2,y1,y2,s3;ll s1,s2;
	inline void setv(const atom&pre){
		x1=max(x1,++y1);y2=min(y2+1,x2);
		s1=pre.s1+1ll*(x2-x1+1)*(y2-y1+1)-C2(y2-x1);
		s2=pre.s2+1ll*(y1-1)*(x2-x1+1);
		s3=pre.s3+x2-x1+1;
	}
	inline ll calcv(int l,int r)const{
		int x3=x2,y3=y2,x4=x1,y4=y1;
		if(x2==-1)x3=i,y3+=y2!=-1,x4=max(x4,y4=y1+1);if(y2==-1)y3=min(i,x3),x4=max(x4,y4=y1+1);
		int a=max(l,x4),b=min(r,x3),c=max(l,y4),d=min(r,y3);
		return a<=b && c<=d?1ll*(b-a+1)*(d-c+1)-F(x4+1,y3,l+1,r):0;
	}
};
vector<atom>v[N];
int T[N<<2],M;
bool bbb[N];int ppp;
inline void mdy(int x,int v){for(T[x+=M]=v;x>>=1;T[x]=min(T[x<<1],T[x<<1|1]));}
inline int ask(int x){
	int v=T[x+=M];
	for(;x;x>>=1)if(!(x&1) && T[x^1]<v)break;
	if(!x)return N;for(x^=1;x<M;)x=x<<1|(T[x<<1]>v);
	return x-M;
}
inline void lk(int x,int y){R[x]=y;L[x]=L[y];R[L[y]]=x;L[y]=x;}
inline void ope(int x){v[a[x]].push_back((atom){i,-1,x,R[x]==n+1?-1:R[x]-1});}
inline void clos(int u){
	v[a[u]].back().x2=i-1;if(-1==v[a[u]].back().y2)v[a[u]].back().y2=i-1;
	v[a[u]].back().setv(v[a[u]].size()==1?(atom){}:*----v[a[u]].end());
}
inline void ins(int u){
	int x=u,en=R[u],y;
	for(;;lk(x=y,en))if(y=ask(x),y>i || y==en)break;
	for(x=R[u];x!=en;x=R[x])ope(x);
}
inline ll query(const vector<atom>&v,int x,int y){
	if(v.empty())return 0;
	int l,r,m,p3,p4;ll ass;
	for(l=0,r=v.size()-1;l<r;){
		m=l+r+1>>1;
		if(v[m].x1<=y)l=m;else r=m-1;
	}
	p4=l;ass=v[l].calcv(x,y);
	if(l==0)return ass;
	for(l=0,r=p4-1;l<r;){
		m=l+r>>1;
		if(x-1<=v[m].y2)r=m;else l=m+1;
	}
	p3=l;ass+=v[l].calcv(x,y);
	if(l+1==p4 || v[l].y2<x-1)return ass;
	for(l=p3,r=p4-1;l<r;){
		m=l+r+1>>1;
		if(v[m].y1<x)l=m;else r=m-1;
	}
	ass+=v[p4-1].s1-v[l].s1;
	ass+=v[l].s1-v[p3].s1+v[l].s2-v[p3].s2-1ll*(v[l].s3-v[p3].s3)*(x-1);
	return ass;
}
int main(){
	fread(ibuf,1,1<<23,stdin);
	read(n);ppp=0;for(M=1;M<n+2;M<<=1);R[0]=n+1;ope(0);
	for(i=1;i<=n;++i){
		bool fl=0;
		read(a[i]);read(l);read(r);read(k);
		a[i]=(a[i]+la)%(n+1);l=(l+la)%i+1;r=(r+la)%i+1;if(l>r)swap(l,r);k=(k+la)%(n+1);
		mdy(i,a[i]);bbb[a[i]]=1;
		if(a[i]==ppp){for(;bbb[ppp];++ppp);mdy(0,ppp);fl=1;}
		if(x=lst[a[i]]){mdy(x,N);if(R[x])L[R[x]]=L[x],R[L[x]]=R[x],clos(x),ins(L[x]),clos(L[x]),ope(L[x]),fl&=L[x];}
		if(fl)clos(0),ins(0),a[0]=ppp,ope(0);if(a[i]<a[L[n+1]])lk(i,n+1),ope(i);
		lst[a[i]]=i;
		out(la=query(v[k],l,r));*oh++='\n';
	}
	fwrite(obuf,1,oh-obuf,stdout);
	return 0;
}