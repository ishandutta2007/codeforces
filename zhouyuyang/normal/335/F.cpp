#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

int n;
ll ans;
map<int,int> mp;
multiset<int> s;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		mp[x]++; ans+=x;
	}
	map<int,int>::IT it;
	for (it=mp.end();it!=mp.begin();){
		multiset<int> now; it--;
		int x=it->fi,cnt=it->se;
		for (;cnt&&s.size()&&!*s.begin();)
			now.insert(x),s.erase(s.begin()),cnt--;
		for (;cnt>1&&s.size();){
			int y=*s.begin(); if (y>=2*x) break;
			s.erase(s.begin()); cnt-=2;
			if (y<x) now.insert(x),now.insert(x);
			else now.insert(2*x-y),now.insert(y);
		}
		if (cnt&&s.size()&&*s.begin()<x)
			s.erase(s.begin()),now.insert(x),now.insert(0),cnt--;
		for (;cnt;cnt--) now.insert(0);
		for (;now.size();) s.insert(*now.begin()),now.erase(now.begin());
	}
	set<int>::IT it2;
	for (it2=s.begin();it2!=s.end();it2++) ans-=*it2;
	printf("%lld\n",ans);
}