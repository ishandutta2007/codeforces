#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10; 
int n,q,b[M];
char ch[M]; 
struct node{
	int l0,r1,al,ar,s,len;
	node (){
		l0=r1=al=ar=s=len=0; 
	}
}a[M<<3],c[M<<3];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
bool tg[M<<3];
node pu(node A,node B,bool out){
	node C;
	C.s=max(A.s,max(B.s,max(A.r1+B.l0,max(A.ar+B.l0,max(A.al,max(B.al+A.r1,B.ar))))));
	C.l0=(A.len==A.l0 ? A.l0+B.l0 : A.l0);
	C.r1=(B.len==B.r1 ? B.r1+A.r1 : B.r1);
	C.al=(A.len==A.r1 ? A.r1+max(B.al,B.l0) : (A.len==A.al ? A.len+B.l0 : A.al));
//	if (out) cout<<A.al<<" "<<C.al<<" "<<C.s<<"  pu\n"; 
	C.ar=(B.len==B.l0 ? B.l0+max(A.ar,A.r1) : (B.len==B.ar ? B.len+A.r1 : B.ar));
	C.len=A.len+B.len; 
	return C; 
}
int tot; 
void build(int x,int l,int r){
	c[x].len=a[x].len=r-l+1;
	if (l==r){
		if (b[l]) a[x].al=a[x].r1=a[x].s=1,c[x].ar=c[x].l0=c[x].s=1;
		else a[x].ar=a[x].l0=a[x].s=1,c[x].al=c[x].r1=c[x].s=1;
		return ;
	}
	build(lc,l,mid); build(rc,mid+1,r);
	a[x]=pu(a[lc],a[rc],0); 
	c[x]=pu(c[lc],c[rc],0);
}
void rev(int x){
	tg[x]^=1;
	swap(a[x],c[x]); 
}
void pd(int x){
	if (tg[x]){
		rev(lc); rev(rc);
		tg[x]=0; 
	}
}
void upd(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr){
		rev(x);
		return ; 
	}
	pd(x); 
	if (rr<=mid)upd(lc,l,mid,ll,rr);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr);
	else upd(lc,l,mid,ll,mid),upd(rc,mid+1,r,mid+1,rr);	
//	cout<<"A "<<l<<" "<<r<<"   ggsdg\n";
	a[x]=pu(a[lc],a[rc],0); 	
	c[x]=pu(c[lc],c[rc],0);
}
node qry(int x,int l,int r,int ll,int rr){
//	cout<<x<<" "<<l<<" "<<r<<" ipipi "<<"\n"; 
	if (l==ll && r==rr){
		return a[x]; 
	}
	pd(x); 
	if (rr<=mid)return qry(lc,l,mid,ll,rr);
	if (ll>mid) return qry(rc,mid+1,r,ll,rr);
	node TA=qry(lc,l,mid,ll,mid),TB=qry(rc,mid+1,r,mid+1,rr);
//	cout<<TA.s<<" "<<TB.s<<" "<<l<<" "<<r<<"   hhh\n"; 
	return pu(TA,TB,0); 
}
int rt; 
int main(){
	n=read(); q=read();
	scanf("%s",ch+1); 
	F(i,1,n) b[i]=(ch[i]=='<' ? 0 : 1);
	build(1,1,n);
//	cout<<a[rt].s<<"  ggsb\n"; 
	while (q--){
		int x=read(),y=read(); 
		upd(1,1,n,x,y);
		node tmp=qry(1,1,n,x,y);
		cout<<max(tmp.s,max(tmp.l0,tmp.r1))<<"\n";
//		F(i,1,n) cout<<qry(1,1,n,i,i).r1; cout<<"\n"; 
	}
	return 0;
}