#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e6+7;
const ll INF=1e18;
int n,m;
ll a[N],P;
struct Segment_Tree{
    vector<ll>f[N<<2];
    ll t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    void build(int p,int l,int r){
	if(l==r){t[p]=a[l],f[p]={-INF,P-a[l],INF};return;}
	int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),t[p]=t[ls]+t[rs];
	f[p]=vector<ll>(r-l+3,INF),f[p][0]=-INF;int L=mid-l+1,R=r-mid;
	for(int i=0,j=0;i<=L;i++){
	    j=min(j,R);
	    for(;j<=R;j++){
		ll x=max(f[ls][i],f[rs][j]+i*P-t[ls]);
		ll y=min(f[ls][i+1],f[rs][j+1]+i*P-t[ls]);
		if(x>=y){j=max(j-1,0);break;}
		f[p][i+j]=min(f[p][i+j],x);
	    }
	}
    }
    void query(int p,int l,int r,int x,int y,ll &v){
	if(x<=l && r<=y){
	    int pos=upper_bound(f[p].begin(),f[p].end(),v)-f[p].begin()-1;
	    v+=t[p]-pos*P;return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)query(ls,l,mid,x,y,v);
	if(y>mid)query(rs,mid+1,r,x,y,v);
    }
}T;
int main(){
    n=read(),m=read(),P=read();
    for(int i=1;i<=n;i++)a[i]=read();
    T.build(1,1,n);
    while(m--){
	int l=read(),r=read();ll v=0;
	T.query(1,1,n,l,r,v),printf("%lld\n",v);
    }
    return 0;
}