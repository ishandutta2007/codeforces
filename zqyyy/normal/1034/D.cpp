#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=3e5+7,inf=0x3f3f3f3f;
struct seg{int l,r;}a[N];
struct node{
	int l,r,id;
	bool operator <(const node &q) const {return l^q.l?l<q.l:(r^q.r?r<q.r:id<q.id);}
};
set<node>s;
vector<pair<int,int> >vec[N];
int n,K;
ll ans,d[N];
inline bool check(int mid){
	fill(d+1,d+n+1,0);
	ll sum=0,res=0,cnt=0,sum1=0;
	for(int i=1,j=0;i<=n;i++){
		sum+=a[i].r-a[i].l;
		res+=(ll)(a[i].r-a[i].l)*j,d[i+1]=a[i].l-a[i].r;
		for(auto x:vec[i])
			if(x.fi<j)res-=(ll)x.fi*x.se;
			else{
				sum-=x.se,res-=(ll)j*x.se;
				d[x.fi+1]+=x.se;
			}
		while(j<i && sum+d[j+1]>mid)
			sum+=d[++j],res+=sum;
		cnt+=j,sum1+=res;
	}
	if(cnt>=K)return 0;
	ans=sum1+(K-cnt)*mid;
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i].l=read(),a[i].r=read();
	s.insert({a[1].l,a[1].r,1});
	for(int i=2;i<=n;i++){
		auto L=s.lower_bound({a[i].l,0,0});
		if(L!=s.begin()){
			L--;
			if(L->r>a[i].l){
				int l1=L->l,r1=L->r,id=L->id;
				s.erase(L);
				s.insert({l1,a[i].l,id});
				s.insert({a[i].l,r1,id});
			}
		}
		auto R=s.upper_bound({a[i].r,0,0});
		if(R!=s.begin()){
			R--;
			if(R->r>a[i].r){
				int l1=R->l,r1=R->r,id=R->id;
				s.erase(R);
				s.insert({l1,a[i].r,id});
				s.insert({a[i].r,r1,id});
			}
		}
		L=s.lower_bound({a[i].l,0,0}),R=s.upper_bound({a[i].r,0,0});
		for(auto it=L;it!=R;it++)
			vec[i].push_back({it->id,it->r-it->l});
		s.erase(L,R),s.insert({a[i].l,a[i].r,i});
	}
	int l=1,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}