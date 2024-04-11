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
const int M=4e5+10;
int a[M],b[M],R[M];
namespace SGT{
	#define mid (l+r>>1)
	#define lc (x<<1)
	#define rc (x<<1|1)
	int tg[M<<3],mi[M<<3],mx[M<<3];
	void pu(int x){
		mi[x]=min(mi[lc],mi[rc]);
		mx[x]=max(mx[lc],mx[rc]);
	}
	void build(int x,int l,int r){
		if (l==r){
			mi[x]=1e9; mx[x]=-1e9;
			return ;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pu(x);
	}
	void xiu(int x,int l,int r,int ll,int rr,int d){
		if (ll>r || rr<l) return ;
		if (ll<=l && r<=rr) {
			mx[x]=max(mx[x],d);
			return ;
		}
		xiu(lc,l,mid,ll,rr,d);
		xiu(rc,mid+1,r,ll,rr,d);
		pu(x);
	}
	LL q1(int x,int l,int r,int ll,int rr){
		if (ll>rr) return -1e9;
		if (ll>r || rr<l) return -1e9;
		if (ll<=l && r<=rr) return mx[x];
		return max(q1(lc,l,mid,ll,rr),q1(rc,mid+1,r,ll,rr));
	}
	LL q2(int x,int l,int r,int ll,int rr){
		if (ll>rr) return 1e9;
		if (ll>r || rr<l) return 1e9;
		if (ll<=l && r<=rr) return mi[x];
		return min(q2(lc,l,mid,ll,rr),q2(rc,mid+1,r,ll,rr));
	}
}
int n,val[M],suf[M]; 
int main(){
	n=read();
	int c0=0,c1=0;
	F(i,1,n){
		a[i]=read(); b[i]=read();
		if (a[i]>b[i]) swap(a[i],b[i]),val[a[i]]=1,c1++;
		else val[a[i]]=-1; 
		R[a[i]]=b[i]; 
		if (a[i]>n || b[i]<=n){
			puts("-1");
			return 0;
		}
	}
	DF(i,n,1) suf[i]=max(suf[i+1],R[i]);
	SGT::build(1,0,2*n);
	SGT::xiu(1,0,2*n,0,0,0);
	int len=0;
	int a1=0,ans=0;
	int tmi=1e9;
	F(i,1,n){
		int x=R[i];
		tmi=min(tmi,x);
//		cout<<x<<"\n";
		int tmp=SGT::q1(1,0,2*n,0,x);
		if (tmp+1>2){
			puts("-1");
			return 0;
		}
		SGT::xiu(1,0,2*n,x,x,tmp+1);
		c0+=(val[i]==-1); len++;
		if (tmp+1==2){
			a1+=val[i];
		}
		if (tmi>suf[i+1]){
			ans+=min(a1+c0,len-a1-c0);
			c0=a1=len=0;
		}
	}
	
//	cout<<len<<" "<<a1<<" "<<c0<<"\n";
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/