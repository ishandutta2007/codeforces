#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll BE=1ll<<50;
const int N=1e5+5;
int n,m,a[N],lgn,i,j;
int bi[N];
inline void add(int x){for(;x<=n;x+=x&-x)--bi[x];}
inline int ask1(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
inline int ask2(int k){
	int i=0,j=lgn,ni;
	for(;j>=0;--j)if(ni=i+(1<<j),ni<n && bi[ni]<k)
		k-=bi[ni],i=ni;
	return i+1;
}
struct que{ll k;int x,i;}qu[N];
ll kk[N],ans[N];int xx[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(;1<<lgn+1<n;++lgn);
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=m;++i)cin>>qu[i].x>>qu[i].k,qu[i].i=i;
	sort(qu+1,qu+m+1,[&](const que&a,const que&b){return a.x<b.x;});
	ll z=BE,step=0;for(i=1;i<=n;++i)bi[i]=i&-i;
	for(i=m,j=n;i;--i){
		auto opt=[&](ll id,int tp){
			ll ns=z<=id?0:(z-id+j-1)/j;
			z-=j*ns;step+=ns;
			int ret=ask2(id-z+1);
			if(tp==1)
				add(ret);
			return ret;
		};
		for(;j && a[j]>qu[i].x;opt(a[j],1),--j);
		if(a[1]>qu[i].x)kk[qu[i].i]=0,ans[qu[i].i]=qu[i].x;
			else xx[qu[i].i]=opt(qu[i].x,0),kk[qu[i].i]=step-qu[i].k;
	}
	for(i=1;i<=m;++i)qu[i]=(que){kk[i],xx[i],i};
	sort(qu+1,qu+m+1,[&](const que&a,const que&b){return a.k<b.k;});
	z=BE;step=0;for(i=1;i<=n;++i)bi[i]=i&-i;
	for(i=1;i<=m && qu[i].k==0;++i);
	for(j=n;j;--j){
		ll ns=(z-a[j]+j-1)/j;
		for(;i<=m && qu[i].k<=ns+step;++i)ans[qu[i].i]=z-(qu[i].k-step)*j+ask1(qu[i].x)-1;
		z-=j*ns;step+=ns;
		add(ask2(a[j]-z+1));
	}
	for(i=1;i<=m;++i)cout<<ans[i]<<'\n';
	return 0;
}