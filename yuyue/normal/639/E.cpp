#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#pragma GCC optimize(2) 
#define ldb long double 
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
const LL inf=1e15;
struct node{
	int a,t,o;
}b[M];
ldb mi[M<<3],mx[M<<3];
int n;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1) 
void pu(int x){
	mi[x]=min(mi[lc],mi[rc]);
	mx[x]=max(mx[rc],mx[lc]);
} 
void build(int x,int l,int r){
	mx[x]=0; mi[x]=inf;
	if (l==r) return ;
	build(lc,l,mid); build(rc,mid+1,r);
	pu(x); 
}
void upd(int x,int l,int r,int p,ldb mdx,ldb mdi){
	if (l==r){
		mx[x]=max(mdx,mx[x]); mi[x]=min(mi[x],mdi);
		return ;
	}
	if (p<=mid) upd(lc,l,mid,p,mdx,mdi);
	else upd(rc,mid+1,r,p,mdx,mdi);
	pu(x);
}
ldb qmx(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return mx[x];
	if (rr<=mid) return qmx(lc,l,mid,ll,rr);
	if (ll>mid) return qmx(rc,mid+1,r,ll,rr);
	return max(qmx(lc,l,mid,ll,mid),qmx(rc,mid+1,r,mid+1,rr));
}
ldb qmi(int x,int l,int r,int ll,int rr){	
	if (l==ll && r==rr) return mi[x];
	if (rr<=mid) return qmi(lc,l,mid,ll,rr);
	if (ll>mid) return qmi(rc,mid+1,r,ll,rr);
	return min(qmi(lc,l,mid,ll,mid),qmi(rc,mid+1,r,mid+1,rr));
}
bool cmp(node A,node B){
	return 1ll*A.a*B.t>1ll*A.t*B.a;
}
bool eq(node A,node B){
	return 1ll*A.a*B.t==1ll*A.t*B.a;
}
int N,t[M];
LL T;
bool chk(ldb c){
	build(1,1,N);
//	cout<<c<<"     yy\n";
	int lst=1;
	LL ti=0,sumt=0;
	b[n+1].a=1e9; b[n+1].t=1;
	F(i,1,n){
		if (eq(b[i],b[i+1])) {
			sumt+=b[i].t;
			continue;
		}
//		cout<<lst<<" "<<i<<" "<<b[i].a<<" "<<b[i].t<<"   range\n";
		sumt+=b[i].t;
		F(j,lst,i){
			ldb X=1.0*b[j].a*(1.0-c*(ti+b[j].t)/(1.0*T)),Y=1.0*b[j].a*(1.0-c*(ti+sumt)/(1.0*T)); 
			upd(1,1,N,b[j].o,X,Y);
//			cout<<X<<" "<<Y<<"   fuck\n";
		}
		F(j,lst,i){
			ldb X=1.0*b[j].a*(1.0-c*(ti+b[j].t)/(1.0*T)),Y=1.0*b[j].a*(1.0-c*(ti+sumt)/(1.0*T)); 
			ldb XX=qmx(1,1,N,1,b[j].o-1),YY=qmi(1,1,N,b[j].o+1,N); 
//			cout<<XX<<" "<<YY<<" "<<X<<" "<<Y<<"    fuckyou\n";
			if (YY<X || XX>Y) return 0;
		}
		ti+=sumt; sumt=0;
		lst=i+1;
	}
	return 1;
}
int main(){
//	freopen("score.in","r",stdin);
//	freopen("score.out","w",stdout);
	n=read(); 
	F(i,1,n) b[i].a=read(),t[i]=b[i].a;
	F(i,1,n) b[i].t=read(),T+=b[i].t;
	int oo=n; t[++oo]=-1e9; t[++oo]=1e9;
	sort(t+1,t+oo+1);
	N=unique(t+1,t+oo+1)-t-1;
	F(i,1,n){
		b[i].o=lower_bound(t+1,t+N+1,b[i].a)-t;
	}
	sort(b+1,b+n+1,cmp);
//	cout<<chk(0.5)<<"  oo\n";
	ldb l=0,r=1,ans=0;
	F(i,1,40){
		ldb md=(l+r)/2.0;
		if (chk(md)) l=md,ans=md; 
		else r=md;
	}
	cout<<fixed<<setprecision(11)<<ans<<"\n";
    return 0;
}