#include"bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
typedef long long int Value1;
typedef pair<bool,long long  int>Value2;
const Value1 Zero1(0);
const Value2 Zero2(make_pair(false, 0));

struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		

		if(r.first){
			return r;
		}else if(l.first){
			return make_pair(true,l.second+r.second);
		}else{
			return make_pair(false,l.second+r.second);
		}
	}

	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy.first)dat[k].sum = dat[k].lazy.second;
		else {
			dat[k].sum += dat[k].lazy.second*(b - a);
		}
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return l + r;

	}

	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	//.
			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		dat[k].lazy = Zero2;
	}

	inline void update_node(int k) { // k. if.
		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);

	}

	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r < 0)assert(false);
		lazy_evaluate_node(k, a, b); 	// .

		if (b <= l || r <= a) //[a,b)[l,r)
			return;
		if (l <= a && b <= r) { // [l,r)[a,b)
			dat[k].lazy = lazy_connect(dat[k].lazy, v);
			lazy_evaluate_node(k, a, b); //.
			return;
		}

		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	//get(l,r) := [l,r). 0-indexed.
	Value1 get(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;

		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); // .

		if (b <= l || r <= a) //[a,b)[l,r)
			return Zero1;

		if (l <= a && b <= r) { // [l,r)[a,b)
			return dat[k].sum;
		}

		int m = (a + b) / 2;
		Value1 vl = get(l, r, 2 * k, a, m);
		Value1 vr = get(l, r, 2 * k + 1, m, b);
		update_node(k);
		return connect(vl, vr);
	}
};
int main() {
	int N;cin>>N;
	vector<long long int>vs(N);
	vector<long long int >melts(N);
	for(int i=0;i<N;++i)cin>>vs[i];
	for(int i=0;i<N;++i)cin>>melts[i];

	vector<long long int>sums(N+1);
	for(int i=0;i<N;++i){
		sums[i+1]=sums[i]+melts[i];
	}


	lazy_segtree seg(N);

	vector<pair<int,int>>ps;
	vector<int>bugs(N);
	for(int i=0;i<N;++i){
		int amin=i-1;
		int amax=N+1;

		while(amin+1!=amax){
			int amid=(amin+amax)/2;
			if(sums[amid]-sums[i]<=vs[i]){
				amin=amid;
			}else{
				amax=amid;
			}
		}
		bugs[i]=amax;
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;

	
	for(int i=0;i<N;++i){
		long long int ans=0;
		que.push(make_pair(bugs[i],i));

		ans+=que.size()*melts[i];
		while(!que.empty()){
			auto q(que.top());
			if(q.first==i+1){
				long long int num=sums[i+1]-sums[q.second];
				ans-=num-vs[q.second];
				que.pop();
			}else{
				break;
			}
		}
		cout<<ans;
		if(i==N-1)cout<<endl;
		else cout<<" ";
	}
	
	return 0;
}