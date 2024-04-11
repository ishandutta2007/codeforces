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
    
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
    
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
using Graph=vector<vector<int>>;
 using Value1=int;
using Value2=int;
const Value1 Zero1= 0;
const Value2 Zero2(0);
struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
#include<vector>
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
void say(lazy_segtree seg){
    int kk=seg.N;
    for(int i=0;i<kk;++i){
        WHATS(seg.get(i,i+1))
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int H,W,K;cin>>H>>W>>K;
    vector<vector<int>>field(H+1,vector<int>(W));
    vector<vector<int>>sums(H+1,vector<int>(W+1));

    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            cin>>field[y][x];
            sums[y][x+1]=sums[y][x]+field[y][x];
        }
    }
    if(H==1){
        int nans=0;
        for(int l=0;l<=W-K;++l){
            nans=max(nans,sums[0][l+K]-sums[0][l]);
        }
        cout<<nans<<endl;
        return 0;
    }
    lazy_segtree seg(W-K+1,vector<Value1>());
    for(int x=0;x<W;++x){
        int l=max(0,x-K+1);
        int r=min(W-K+1,x+1);
        seg.update(l,r,field[0][x]+field[1][x]);
    }
    //say(seg);
        vector<Value1>anss;

    for(int y=2;y<=H;++y){
        
        //say(seg);
        anss.clear();
        for(int bl=-K;bl<=W-K;++bl){
            if(bl>=0){
                anss.push_back(seg.get(0,W-K+1));
                anss.back()+=sums[y][bl+K]-sums[y][bl]+sums[y-1][bl+K]-sums[y-1][bl];
            }
            int in_r=bl+K;
            int out_l=bl;
            if(in_r<W){
                int l=max(0,in_r-K+1);
                int r=min(W-K+1,in_r+1);
                seg.update(l,r,-field[y-1][in_r]);
            }
            if(out_l>=0){
                int l=max(0,out_l-K+1);
                int r=min(W-K+1,out_l+1);
                seg.update(l,r,field[y-1][out_l]);
            }
            //say(seg);
        }
        seg=lazy_segtree(W-K+1,anss);
       // WHATS(anss)
    }
    cout<<*max_element(anss.begin(),anss.end())<<endl;
    
    return 0;
}