#include "bits/stdc++.h"
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}


using ll = long long int;
// 1 3 3 5 6 6
// 3 4 5 6 7 8
// 1 0 1 0 0 1 
// 2 1 2 1 1 1
// 3 2 3 2 2 1
// 4 3 4 3 2 1
// 5 4 4 3 2 1
// 6 5 4 3 2 1

// 36 32 7 4 3 2 1


// l3 r4 l5 r2 l3 r4
// l3 r5 l2 r9

// l 34...57 r

struct aa{
    //l
    //r
    //ll
    //lr
    //rl
    //rr
    int answer;
    int len;
    
    // >>>><<<<<    ...     >>>>><<<<<
    int l_r;
    int l_l;

    int r_r;
    int r_l;
};

//5 3 5 3 0 2 0 2
using Value1=vector<aa>;
aa connecta(const aa& l,  const aa& r){
    if(r.len==0)return l;
    else if(l.len==0)return r;
    int nans=max(l.answer,r.answer);
    if(l.r_l==0){
        nans=max(nans,l.r_r+r.l_r+r.l_l);
    }
    if(r.l_r==0){
        nans=max(nans,l.r_r+l.r_l+r.l_l);
    }

    int n_l_r=l.l_r;
    if(l.l_r==l.len)n_l_r+=r.l_r;

    int n_l_l=l.l_l;
    if(l.l_l+l.l_r==l.len)n_l_l+=((l.l_l==0||r.l_r==0) ? r.l_l : 0);

    int n_r_r=r.r_r;
    if(r.r_r+r.r_l==r.len){
        n_r_r+=((l.r_l==0 ||r.r_r==0)? l.r_r:0);
    }

    int n_r_l=r.r_l;
    if(r.r_l==r.len)n_r_l+=l.r_l;

    int n_len=l.len+r.len;

    nans=max(nans,n_r_l+n_r_r);
    nans=max(nans,n_l_l+n_l_r);
    return aa{nans,n_len,n_l_r,n_l_l,n_r_r,n_r_l};
}



typedef bool Value2;
const Value1 Zero1(2,aa{0,0,0,0,0,0});
const Value2 Zero2(false);

// using Value1=int;
// using Value2=int;
// const Value1 Zero1= 0;
// const Value2 Zero2(0);
 
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
		return l^r;
	}
 
	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy)swap(dat[k].sum[0],dat[k].sum[1]);
		
	}
 
	inline Value1 connect(const Value1& l, const Value1& r) {
		auto a1=connecta(l[0],r[0]);
        auto a2=connecta(l[1],r[1]);
        return Value1{a1,a2};
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
// void say(aa x){
//     WHATS(x.answer)
//     WHATS(x.len)
//     WHATS(x.l_r)
//     WHATS(x.l_l)
//     WHATS(x.r_r)
//     WHATS(x.r_l)
// }
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie();
    //say(connecta(aa{8,8,5,3,5,3},aa{2,2,0,2,0,2}));
    auto al=aa{1,1,0,1,0,1};
    auto ar=aa{1,1,1,0,1,0};
    //say(connecta(ar,ar));
    //auto now=Zero1[0];
    //say(now);
    // string stst=">>>>><<<<<";
    // for(int i=0;i<10;++i){
    //     auto kk=stst[i]=='>'?ar:al;
    //     now=connecta(now,kk);
    //     //say(now);
    // }
    //say(connecta(connecta(connecta(connecta(ar,al),ar),al),ar));
    //say(connecta(aa{1,1,1,0,1,0},aa{1,1,0,1,0,1}));
    //><><
    int N,M;
    string st;
    char chs[510000];
    scanf("%d %d %s",&N,&M,chs);
    st=chs;

    vector<Value1>vals;
    
    
    for(int i=0;i<N;++i){
        if(st[i]=='<'){
            vals.push_back(Value1{al,ar});

        }else{
            vals.push_back(Value1{ar,al});
        }
    }
    lazy_segtree seg(N,vals);

    for(int i=0;i<M;++i){
        int l,r;scanf("%d %d",&l,&r);
        l--;
        seg.update(l,r,true);
        auto ans_aa=seg.get(l,r);
        //say(ans_aa[0]);
        //cout<<ans_aa[0].answer<<'\n';
        printf("%d\n",ans_aa[0].answer);
        
    }
	return 0;
}