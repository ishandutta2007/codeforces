#include"bits/stdc++.h"
using namespace std;
#pragma warning(disable:4996)
using pa=pair<int,int>;
using Value=pa;

typedef int Value1;
typedef int Value2;
const Value1 Zero1(-10000000);
const Value2 Zero2(0);

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
		for (int i = N; i < 2*N; ++i) {
			dat[i].sum = 0;
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}

	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy)dat[k].sum +=dat[k].lazy;

	}

	Value1 connect(const Value1 l, const Value1 r) {
		return max(l,r);

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
int MAX_N=1<<20;

int solve(int k,int a,int b,lazy_segtree&seg){
    seg.lazy_evaluate_node(k,a,b);
    if(a+1==b){
        return a;
    }else{
        if(seg.dat[2*k+1].sum+seg.dat[2*k+1].lazy>0){
            return solve(2*k+1,(a+b)/2,b,seg);
        }else{
            return solve(2*k,a,(a+b)/2,seg);
        }
    }
}
int main() {
    int N,M;cin>>N>>M;
    lazy_segtree seg(MAX_N);
    vector<int>dishes(N),pupils(M);
    for(int i=0;i<N;++i){
        int a;scanf("%d",&a);
        seg.update(0,a,1);
        dishes[i]=a;
    }
    for(int i=0;i<M;++i){
        int a;scanf("%d",&a);
        seg.update(0,a,-1);
        pupils[i]=a;
    }

    int Q;cin>>Q;
    while(Q--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        b--;
        if(a==1){
            seg.update(0,dishes[b],-1);
            dishes[b]=c;
            seg.update(0,dishes[b],1);
        }else{
            seg.update(0,pupils[b],1);
            pupils[b]=c;
         
            seg.update(0,pupils[b],-1);
        }
        int answer=-2;
        if(seg.get(0,MAX_N)>0){
            answer=solve(1,0,MAX_N,seg);
        }
        printf("%d\n",answer+1);

    }
    
	return 0;
}