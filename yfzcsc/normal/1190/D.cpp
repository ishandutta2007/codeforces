#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,xi[maxn],yi[maxn],lsh[maxn],s[maxn<<2];
map<int,vector<int> >st;
void sol(int* xi){
	for(int i=1;i<=n;++i)lsh[i]=xi[i];
	sort(lsh+1,lsh+n+1);
	for(int i=1;i<=n;++i)xi[i]=lower_bound(lsh+1,lsh+n+1,xi[i])-lsh;
}
ll cal(ll x){
	return x*(x+1)/2;
}
void mdy(int o,int l,int r,int x){
	if(l==r){
		s[o]=1;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)mdy(o<<1,l,mid,x);
	else mdy(o<<1|1,mid+1,r,x);
	s[o]=s[o<<1]+s[o<<1|1];
}
ll qry(int o,int l,int r,int ql,int qr){
	if(ql>qr)return 0;
	if(ql<=l&&r<=qr)return s[o];
	int mid=l+r>>1;
	ll ans=0;
	if(ql<=mid)ans+=qry(o<<1,l,mid,ql,qr);
	if(qr>mid)ans+=qry(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d%d",&xi[i],&yi[i]);
	}
	sol(xi),sol(yi);
	for(int i=1;i<=n;++i){
		st[n+1-yi[i]].push_back(xi[i]);
	}
	long long ans=0;
	for(auto a:st){
		auto&v=a.second;
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i){
			mdy(1,1,n,v[i]);
			ll L=qry(1,1,n,1,v[i]-1),R=qry(1,1,n,v[i]+1,i==v.size()-1?n:v[i+1]-1);
			ll ALL=qry(1,1,n,1,i==v.size()-1?n:v[i+1]-1);
			ans+=cal(ALL)-cal(L)-cal(R);
		//	printf("[%lld(%lld,%lld,%lld)]",ans,ALL,L,R);
		}
	}
	printf("%lld",ans);
}