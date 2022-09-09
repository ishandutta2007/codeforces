#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int l,r,m,tg,s;
}t[N<<2];
inline void upd(int x){
	t[x].s=t[x].tg?0:t[x<<1].s+t[x<<1|1].s;
}
inline void build(int i,int l,int r){
	t[i]=node{l,r,l+r>>1,0,r-l+1};if(l==r)return;
	build(i<<1,l,t[i].m);build(i<<1|1,t[i].m+1,r);
}
void mdy(int i,int l,int r,int v){
	if(l<=t[i].l && t[i].r<=r){
		t[i].tg+=v;t[i].s=t[i].tg?0:t[i].l==t[i].r?1:t[i<<1].s+t[i<<1|1].s;
		return;
	}
	if(l<=t[i].m)mdy(i<<1,l,r,v);if(t[i].m<r)mdy(i<<1|1,l,r,v);upd(i);
}
int n,a[N],i,p[N];
long long ans;
vector<int>ve[N];
inline void mdy(int x,int i,int v){
	if(p[x]<ve[x].size()){
		if(p[x]+2<ve[x].size()){
			int i1=ve[x][p[x]],i2=ve[x][p[x]+2],i3=p[x]+3<ve[x].size()?ve[x][p[x]+3]:n+1;
			mdy(1,i1,i2-1,v);
			if(i3<=n)mdy(1,i3,n,v);
		}else mdy(1,ve[x][p[x]],n,v);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i],ve[a[i]].push_back(i);build(1,1,n);
	for(i=1;i<=n;++i)mdy(i,1,1);
	for(i=1;i<=n;++i){
		ans+=t[1].s,i<n?mdy(a[i],i,-1),++p[a[i]],mdy(a[i],i+1,1),mdy(1,i,i,1),0:0;
		cerr<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
}