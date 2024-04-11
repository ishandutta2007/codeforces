#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void print(ll x){
	printf("%lld\n",x);
}

using vi=vector<int>;
using pi=pair<int,int>;
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back

const int inf=LLONG_MAX/3;

struct SegmentTree{
	vi mx,lz;
	int s;
	void Init(int n){
		s=1;
		while(s<n)s*=2;
		mx.resize(s*2,0);
		for(int i=0;i<s;i++)
			mx[i+s]=i;
		for(int i=s-1;i>=1;i--)
			mx[i]=max(mx[i*2],mx[i*2+1]);
		lz.resize(s*2,0);
	}
	int GetNodeMax(int i){
		return mx[i]+lz[i];
	}
	void Propagate(int i){
		mx[i]+=lz[i];
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
		lz[i]=0;
	}
	void Update(int i){
		assert(lz[i]==0);
		mx[i]=max(GetNodeMax(i*2),GetNodeMax(i*2+1));
	}
	void Add(int b,int e,int v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			lz[i]+=v;
			return;
		}
		Propagate(i);
		Add(b,e,v,l,(l+r)/2,i*2);
		Add(b,e,v,(l+r)/2,r,i*2+1);
		Update(i);
	}
	int Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return -inf;
		if(b<=l&&r<=e)return GetNodeMax(i);
		Propagate(i);
		return max(Get(b,e,l,(l+r)/2,i*2),Get(b,e,(l+r)/2,r,i*2+1));
	}
	void Add(int b,int e,int v){
		if(b<e)Add(b,e,v,0,s,1);
	}
	int Get(int b,int e){
		if(b<e)return Get(b,e,0,s,1);
		else return -inf;
	}
};

struct BIT{
	vi buf;
	void Init(int n){
		buf.resize(n,0);
	}
	void Add(int i,int v){
		for(;i>=0;i-=((i+1)&(-i-1)))
			buf[i]+=v;
	}
	int Get(int i){
		int res=0;
		for(;i<int(buf.size());i+=((i+1)&(-i-1)))
			res+=buf[i];
		return res;
	}
};

signed main(){
	int q=read();
	SegmentTree seg;
	seg.Init(1000010);
	BIT bit;
	bit.Init(1000010);
	vector<pi> knights(q);
	REP(_,q){
		char str[10];
		scanf("%s",str);
		if(str[0]=='+'){
			int t=read(),d=read();
			knights[_]=pi(t,d);
			seg.Add(0,t+1,d);
			bit.Add(t,d);
		}else if(str[0]=='-'){
			int i=read()-1;
			int t=knights[i].first,d=knights[i].second;
			seg.Add(0,t+1,-d);
			bit.Add(t,-d);
		}else{
			int t=read();
			int mx=seg.Get(0,t+1);
			mx-=bit.Get(t+1);
			mx-=t;
			print(mx);
		}
	}
}