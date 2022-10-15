#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=1e5+7;
int n,Q;
double P[N];
struct Segment_Tree{
    double t[N<<2],mul[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    inline void upd(int p){
	mul[p]=mul[ls]*mul[rs];
	t[p]=t[ls]+t[rs]*mul[ls];
    }
    void build(int p,int l,int r){
	if(l==r){t[p]=mul[p]=(1-P[l])/P[l];return;}
	int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),upd(p);
    }
    void modify(int p,int l,int r,int x,double v){
	if(l==r){t[p]=mul[p]=(1-v)/v;return;}
	int mid=(l+r)>>1;x<=mid?modify(ls,l,mid,x,v):modify(rs,mid+1,r,x,v);upd(p);
    }
    pair<double,double>query(int p,int l,int r,int x,int y){
	if(x<=l && r<=y)return {mul[p],t[p]};
	int mid=(l+r)>>1;
	if(y<=mid)return query(ls,l,mid,x,y);
	if(x>mid)return query(rs,mid+1,r,x,y);
	auto A=query(ls,l,mid,x,y),B=query(rs,mid+1,r,x,y);
	return {A.fi*B.fi,A.se+A.fi*B.se};
    }
}T;
int main(){
    n=read(),Q=read();
    for(int i=1;i<=n;i++){
	int x=read(),y=read();
	P[i]=1.*x/y;
    }
    T.build(1,1,n);
    while(Q--){
	int opt=read();
	if(opt==1){
	    int i=read(),a=read(),b=read();
	    T.modify(1,1,n,i,1.*a/b);
	}else{
	    int l=read(),r=read();
	    printf("%.9lf\n",1/(1+T.query(1,1,n,l,r).se));
	}
    }
    return 0;
}