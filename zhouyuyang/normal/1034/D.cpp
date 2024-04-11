#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define inf ((1<<30)-233)
using namespace std;

struct data{
	int l,r,rk;
	bool operator <(const data &a)const{
		return l!=a.l?l<a.l:r<a.r;
	}
};
set<data> s;
void work(int p){
	auto ed=s.upper_bound((data){p+1,0,0});
	data x=*(--ed); s.erase(ed);
	if (x.l<p) s.insert((data){x.l,p-1,x.rk});
	if (p<=x.r) s.insert((data){p,x.r,x.rk});
}
int val[300005],n,k;
vector<pii > q[300005];
pll calc(int v){
	ll ans=0,sum=0,cnt=0,ans2=0;
	memset(val,0,sizeof(val));
	for (int i=1,r=0;i<=n;i++){
		for (int j=0;j<q[i].size();j++)
			if (q[i][j].se<=r){
				sum+=q[i][j].fi;
				cnt+=1ll*q[i][j].fi*(r-q[i][j].se+1);
			}
			else val[q[i][j].se]+=q[i][j].fi;
		for (;sum+val[r+1]>=v;)
			cnt+=(sum+=val[++r]);
		ans+=r; ans2+=cnt;
	}
	return pll(ans,ans2);
}
int main(){
	scanf("%d%d",&n,&k);
	s.insert((data){1,inf-1,0});
	s.insert((data){inf,inf,0});
	set<data>::iterator ed,it; 
	for (int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r); r--;
		work(l); work(r+1);
		ed=s.lower_bound((data){l,0,0});
		for (;ed->r<=r;){
			int delta=ed->r-ed->l+1;
			q[i].push_back(pii(delta,ed->rk+1));
			it=ed++; s.erase(it);
		}
		q[i].push_back(pii(-(r-l+1),i+1));
		s.insert((data){l,r,i});
	}
	int l=1,r=inf,val;
	pll ans;
	while (l<=r){
		int mid=(l+r)/2;
		pll v=calc(mid);
		if (v.fi<k) r=mid-1;
		else val=mid,ans=v,l=mid+1;
	}
	printf("%lld",ans.se-1ll*val*(ans.fi-k));
}