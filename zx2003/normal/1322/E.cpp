#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,i,j,k,a[N],ans[N],mx,x,y,c[N],dis[N];
pair<int,int>aa[N];
struct seg{int l,r;};
inline bool operator<(const seg&a,const seg&b){return a.r<b.r;}
set<seg>s0,s1;
set<int>s2;
inline void del0(int x){
	auto it=s0.lower_bound((seg){x,x});
	if(it!=s0.end() && it->l<=x){
		int l=it->l,r=it->r;s0.erase(it);
		if(l<x-1)s0.insert((seg){l,x-1});
		if(x+1<r)s0.insert((seg){x+1,r});
	}
}
inline void ins1(int x){
	c[x]=1;if(x==1)c[0]=1;if(x==n)c[n+1]=1;
	int lb=x,rb=x;
	if(c[x+1]==1){
		auto it=s1.lower_bound((seg){x,x});
		if(it==s1.end() || it->l>x+1)rb=x+1;else rb=it->r,s1.erase(it);
	}
	if(c[x-1]==1){
		auto it=s1.upper_bound((seg){x,x});
		if(it==s1.begin() || (--it)->r<x-1)lb=x-1;else lb=it->l,s1.erase(it);
	}
	if(lb<rb)s1.insert((seg){lb,rb});
}
inline void do1(int x,int y){
	int lb,rb;
	auto it=s0.lower_bound((seg){y,y});
	if(it!=s0.end()){
		auto it2=--s1.upper_bound((seg){it->l,it->l});
		rb=it->l+it2->r>>1;
	}else rb=n;
	if(it!=s0.begin()){
		--it;
		auto it2=s1.upper_bound((seg){it->r,it->r});
		lb=it->r+it2->l+1>>1;
	}else lb=1;
	for(auto itt=s2.lower_bound(lb);itt!=s2.end() && *itt<=rb;s2.erase(itt++))
		ans[*itt]=x;
}
inline void do2(int y,int z){
	auto it=s1.upper_bound((seg){y,y}),it2=it;int ri=N,le=-1;
	if(it2!=s1.end())ri=min(ri,it2->l);
	for(;it2!=s1.begin() && (it2==s1.end() || it2->r>=y);--it2);
	if(it2!=s1.end() && it2->r<y)le=max(le,it2->r);
	if(it2=s0.upper_bound((seg){y,y}),it2!=s0.end())ri=min(ri,it2->l);
	for(;it2!=s0.begin() && (it2==s0.end() || it2->r>=y);--it2);
	if(it2!=s0.end() && it2->r<y)le=max(le,it2->r);
	if(ri<N)mx=max(mx,ri-y>>1);if(le>-1)mx=max(mx,z-le>>1);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i],aa[i]={a[i],i},s2.insert(i);
	s0.insert((seg){0,n+1});
	sort(aa+1,aa+n+1);
	for(i=1;i<=n;++i){
		tie(x,y)=aa[i];
		del0(y);ins1(y);
		auto it=s1.lower_bound((seg){y,y});
		if(it!=s1.end())do1(x,it->r);
		if(it!=s1.begin())do1(x,(--it)->r);
		if(i==n || aa[i+1].first>x)for(int j=i;j && aa[j].first==x;--j){
			it=s1.lower_bound((seg){aa[j].second,aa[j].second});
			if(it!=s1.end())do2(it->r,it->l);
			it=s0.lower_bound((seg){aa[j].second,aa[j].second});
			if(it!=s0.end())do2(it->r,it->l);
			if(it!=s0.begin())--it,do2(it->r,it->l);
		}
	}
	cout<<mx<<'\n';for(i=1;i<=n;++i)cout<<ans[i]<<(i==n?'\n':' ');
}