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
const int M=2e5+10;  
int n,k,a[M],b[M];
LL sa[M],sb[M],t[M];
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
LL mi[M<<3],mx[M<<3]; 
void pu(int x){
	mx[x]=max(mx[lc],mx[rc]);
	mi[x]=min(mi[lc],mi[rc]);
}
void build(int x,int l,int r){
	if (l==r){
		mx[x]=mi[x]=t[l];
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pu(x);
}
LL Mi,Mx;
void qry(int x,int l,int r,int ll,int rr){
	if (r<ll || l>rr) return ;
	if (ll<=l && r<=rr){
		Mi=min(Mi,mi[x]);
		Mx=max(Mx,mx[x]);
		return ;
	}
	qry(lc,l,mid,ll,rr);
	qry(rc,mid+1,r,ll,rr);
	pu(x);
}
int main(){
	n=read(); int m=read();
	F(i,1,n) a[i]=read(),sa[i]=sa[i-1]+a[i];
	F(i,1,n) b[i]=read(),sb[i]=sb[i-1]+b[i];
	F(i,1,n) t[i]=sb[i]-sa[i];
	build(1,1,n);
	F(i,1,m){
		int l=read(),r=read();
		if (t[l-1]==t[r]){
			Mx=-1e18; Mi=1e18; qry(1,1,n,l,r);
			if (Mi==t[r]){
				cout<<Mx-t[r]<<"\n";
			}
			else puts("-1");
		}
		else puts("-1");
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/