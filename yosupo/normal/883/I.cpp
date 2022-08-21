#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

struct segtree{
	using D = int;

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	bool get(int k){
		k+=N;
		while(k>0){
			if(val[k]) return 1;
			k/=2;
		}
		return 0;
	}
	void add(int a,int b){		//non-commutative & unrecursive
		a+=N,b+=N;
		while(a<b){
			if(a&1) val[a] = 1,a++;
			if(b&1) --b,val[b] = 1;
			a/=2,b/=2;
		}
	}
};

int N,K;
int a[310000];

bool can(int lim){
	segtree seg(N+2);
	seg.add(0,1);
	rep(i,N) if(seg.get(i)){
		int l = i+K;
		int r = upper_bound(a,a+N,a[i]+lim) - a + 1;
		chmin(r,N+1);
		if(l<r) seg.add(l,r);
	}
	return seg.get(N);
}

int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	sort(a,a+N);
	int ub = 1e9, lb = -1;
	while(ub-lb>1){
		int m = (ub+lb)/2;
		if(can(m)) ub = m;
		else lb = m;
	}
	cout<<ub<<endl;
}