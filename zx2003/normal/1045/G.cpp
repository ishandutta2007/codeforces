#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int xx[N],x[N],idx[N],r[N],q[N],n,k,i,j,a[N],rt[N],qq[N],idq[N];
struct node{
	int l,r,s;
}t[4000000];int tsz;
inline void ins(int&x,int l,int r,int k,int v){
	if(!x)x=++tsz;t[x].s+=v;if(l==r)return;
	int m=(l+r)>>1;
	if(k>m)ins(t[x].r,m+1,r,k,v);else ins(t[x].l,l,m,k,v);
}
int query(int x,int rl,int rr,int l,int r){
	if((l==rl && r==rr) || !x)return t[x].s;
	int m=(rl+rr)>>1;
	if(l>m)return query(t[x].r,m+1,rr,l,r);
		else if(r<=m)return query(t[x].l,rl,m,l,r);
				else return query(t[x].l,rl,m,l,m)+query(t[x].r,m+1,rr,m+1,r);
}
bool cmp(int p,int q){return r[p]<r[q];}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>x[i]>>r[i]>>q[i],xx[i]=x[i],a[i]=i,qq[i]=q[i];
	sort(xx+1,xx+n+1);sort(qq+1,qq+n+1);
	int xc=unique(xx+1,xx+n+1)-xx-1,qc=unique(qq+1,qq+n+1)-qq-1;
	long long ans=0;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;++i){
		idx[i]=lower_bound(xx+1,xx+xc+1,x[i])-xx;
		idq[i]=lower_bound(qq+1,qq+qc+1,q[i])-qq;
		ins(rt[idq[i]],1,xc,idx[i],1);
	}
	for(i=1;i<=n;++i){
		int z=a[i];
		int lb=lower_bound(xx+1,xx+xc+1,x[z]-r[z])-xx;
		int rb=upper_bound(xx+1,xx+xc+1,x[z]+r[z])-xx-1;
		ins(rt[idq[z]],1,xc,idx[z],-1);
		for(j=lower_bound(qq+1,qq+qc+1,q[z]-k)-qq;j<=qc && qq[j]<=q[z]+k;++j)
			ans+=query(rt[j],1,xc,lb,rb);
	}
	cout<<ans<<'\n';
	return 0;
}