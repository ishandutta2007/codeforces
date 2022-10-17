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
const int M=2e5+10;
int n,q;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int tg[M<<3],s[M<<3],len[M<<3];
void pu(int x){
	s[x]=s[lc]+s[rc];
}
char t[M],c[M];
void build(int x,int l,int r){
	tg[x]=-1; s[x]=0; len[x]=r-l+1; 
	if (l==r){
		s[x]=t[l]-'0';
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pu(x);
}
void cv(int x,int o){
	s[x]=(o ? len[x] :0);
	tg[x]=o;
}
void pd(int x){
	if (tg[x]!=-1){
		cv(lc,tg[x]);
		cv(rc,tg[x]);
		tg[x]=-1;
	}
}
void upd(int x,int l,int r,int ll,int rr,int o){
	if (l==ll && r==rr){
		cv(x,o);
		return;
	}
	pd(x);
	if (rr<=mid) upd(lc,l,mid,ll,rr,o);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr,o);
	else upd(lc,l,mid,ll,mid,o),upd(rc,mid+1,r,mid+1,rr,o);
	pu(x);
}
int qry(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return s[x];
	pd(x);
	if (rr<=mid) return qry(lc,l,mid,ll,rr);
	if (ll>mid) return qry(rc,mid+1,r,ll,rr);
	return qry(lc,l,mid,ll,mid)+qry(rc,mid+1,r,mid+1,rr);
}
int a[M],b[M];
void work(){
	n=read(); q=read();
	scanf("%s%s",c+1,t+1);
	build(1,1,n);
	F(i,1,q){
		a[i]=read(); b[i]=read();
	}
	DF(i,q,1){
		int len=b[i]-a[i]+1,tmp=qry(1,1,n,a[i],b[i]);
		if (len%2==0 && tmp==len/2){
			puts("NO");
			return ;
		}
		if (tmp>len/2){
			upd(1,1,n,a[i],b[i],1);
		}
		else{
			upd(1,1,n,a[i],b[i],0);
		}
	}
	F(i,1,n){
		int tmp=qry(1,1,n,i,i);
//		cout<<tmp<<"  gfff\n";
		if (tmp!=(c[i]-'0')){
			puts("NO");
			return ;
		}
	}
	puts("YES");
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
1
5 1
11111
00000
1 5
*/