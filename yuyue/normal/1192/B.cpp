#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=4e5+10; 
const LL inf=1e16;
int to[M],cnt,nxt[M],head[M]; 
LL w[M];
void add(int x,int y,LL z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z; 
}
LL dep[M],wei[M]; 
int wn[M],fir[M],bid[M],tot,ed[M]; 
bool ip[M];
void dfs(int x,int fa){
	fir[x]=++tot; wn[tot]=x;  ip[tot]=1;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i]; 
		if (y==fa) continue;
		dep[y]=dep[x]+w[i]; bid[(i>>1)]=y;  
		dfs(y,x); 
		wn[++tot]=x; 
	}
	ed[x]=tot; 
}
#define mid (l+r>>1) 
#define lc (x<<1)
#define rc (x<<1|1)
LL s[M<<3],mx[M<<3],mi[M<<3],ls[M<<3],rs[M<<3],tg[M<<3];
void pu(int x){
	mx[x]=max(mx[lc],mx[rc]);
	mi[x]=min(mi[lc],mi[rc]);
	s[x]=max(max(s[lc],s[rc]),max(ls[lc]+mx[rc],rs[rc]+mx[lc]));
	ls[x]=max(max(ls[lc],ls[rc]),mx[lc]-2ll*mi[rc]); 
	rs[x]=max(max(rs[lc],rs[rc]),mx[rc]-2ll*mi[lc]); 
}  
void build(int x,int l,int r){
	if (l==r){
		mx[x]=rs[x]=ls[x]=-inf; s[x]=0;
		mi[x]=dep[wn[l]];
		if (ip[l]) mx[x]=dep[wn[l]],rs[x]=ls[x]=-dep[wn[l]];
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pu(x); 
}
void rel(int x,LL d){
	mi[x]+=d; mx[x]+=d; ls[x]-=d; rs[x]-=d;
	tg[x]+=d;
}
void pd(int x){
	if (tg[x]){
		rel(lc,tg[x]);
		rel(rc,tg[x]); 
		tg[x]=0;
	}
}
void upd(int x,int l,int r,int ll,int rr,LL d){
	if (l==ll && r==rr){
		rel(x,d); 
		return ;
	}
	pd(x); 
	if (rr<=mid) upd(lc,l,mid,ll,rr,d);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr,d);
	else upd(lc,l,mid,ll,mid,d),upd(rc,mid+1,r,mid+1,rr,d); 
	pu(x); 
//	cout<<l<<" "<<r<<" "<<s[x]<<" "<<mx[x]<<" "<<mi[x]<<"   nnj\n";
}
int n,m;
LL W,val[M]; 
int main(){
	n=read(); m=read(); W=read(); cnt=1; 
	F(i,1,n-1){
		int x=read(),y=read();
		LL z=read();
		add(x,y,z); add(y,x,z); val[i]=z;
	}
	dfs(1,0); 
	build(1,1,tot);
	LL lst=0; 
	while (m--){
		LL x=read(),y=read(); 
		x=(x+lst)%(n-1)+1; y=(y+lst)%W;
//		cout<<x<<" "<<y<<"   fuck \n"; 
		int u=bid[x];
//		cout<<fir[u]<<" "<<ed[u]<<" "<<y-val[x]<<"   mdzz\n";
		upd(1,1,tot,fir[u],ed[u],y-val[x]); 
		val[x]=y;
		cout<<(lst=s[1])<<"\n";
	}
	return 0;
}