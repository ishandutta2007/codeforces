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
int n,a[M];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int mx[M<<3];
void build(int x,int l,int r){
	mx[x]=0;
	if (l==r) return ;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void upd(int x,int l,int r,int ll,int rr,int d){
	if (l==ll && r==rr){
		mx[x]=max(mx[x],d); 
		return ;
	}
	if (ll>mid) upd(rc,mid+1,r,ll,rr,d);
	else if (rr<=mid) upd(lc,l,mid,ll,rr,d);
	else upd(lc,l,mid,ll,mid,d),upd(rc,mid+1,r,mid+1,rr,d);
	mx[x]=max(mx[lc],mx[rc]);
}
int qry(int x,int l,int r,int ll,int rr){
	if (ll>rr) return -1e9; 
	if (l==ll && r==rr) return mx[x];
	if (ll>mid) return qry(rc,mid+1,r,ll,rr);
	if (rr<=mid) return qry(lc,l,mid,ll,rr); 
	return max(qry(lc,l,mid,ll,mid),qry(rc,mid+1,r,mid+1,rr));
}
int s[M];
bool cmp(int x,int y){
	return a[x]==a[y] ? x<y : a[x]<a[y];
}
int L[M],p[M];
void work(){
	n=read(); 
	F(i,1,n){
		a[i]=read();
	}
	int tp=1;
	s[1]=0; a[0]=INT_MAX;
	F(i,1,n){
		while (tp>1 && a[i]>=a[s[tp]]) tp--;
		L[i]=s[tp];
		s[++tp]=i;
		p[i]=i;
	}
	build(1,0,n);
	sort(p+1,p+n+1,cmp);
	F(i,1,n){
		int x=p[i];
		int oa=qry(1,0,n,L[x],x)+1;
		int ob=qry(1,0,n,0,L[x]-1)+2;
		upd(1,0,n,x,x,max(oa,ob));
//		cout<<x<<" "<<max(oa,ob)<<"    gg\n";
	}
	cout<<qry(1,0,n,1,n)<<"\n";
}
int main(){
	int T=read();
	while (T--) work(); 
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/