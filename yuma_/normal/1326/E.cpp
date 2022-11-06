#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#include<memory>
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
    
using namespace std;
    
using ll=long long;
using ld =long double;
    
#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
    
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
    os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
    for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
    for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
    for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
    int i=0;
    for(auto it:v){
        if(i > 0){os << ' ';}
        os << it;
        i++;
    } 
    return os;
}



using Value1=int;
using Value2=int;
const Value1 Zero1(int(-1e9));
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
	lazy_segtree(int n,vector<Value1>v) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = 0; i < v.size(); ++i) {
			dat[i+N].sum = v[i];
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}
 
	void lazy_func(const int k, const int a, const int b) {
		
        dat[k].sum+=dat[k].lazy;
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    vector<int>as(N),bs(N);
    vector<int>places(N);
    for(int i=0;i<N;++i){
        cin>>as[i];
        places[as[i]-1]=i;
    }
    for(int i=0;i<N;++i){
        cin>>bs[i];
        bs[i]--;
    }

    vector<int>anss(N);
    int ans=N-1;
    lazy_segtree seg(N,vector<int>(N,-1000000));
    WHATS(seg.get(0,N))

    seg.update(places[ans],places[ans]+1,1000000);
    WHATS(seg.get(0,N))

    seg.update(0,places[ans]+1,1);

    for(int i=0;i<N;++i){
        WHATS(i)
        while(true){
            WHATS(ans)
            WHATS(seg.get(0,N))
            for(int j=0;j<N;++j)WHATS(seg.get(j,j+1));

            if(seg.get(0,N)<=0){
                ans--;
               
                seg.update(places[ans],places[ans]+1,1000000);
                seg.update(0,places[ans]+1,1);
            }else{
                break;
            }
        }
        anss[i]=ans;
        for(int j=0;j<N;++j)WHATS(seg.get(j,j+1));

        seg.update(0,bs[i]+1,-1);

        for(int j=0;j<N;++j)WHATS(seg.get(j,j+1));
    }
    for(int i=0;i<N;++i){
        cout<<anss[i]+1<<' ';
    }
    return 0;
}