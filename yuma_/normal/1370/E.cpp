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

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
	
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

int say(vector<int>v){
    cout<<v.size();
    for(auto x:v)cout<<' '<<x+1;
    cout<<endl;

    int a;cin>>a;
    a--;
    return a;
}
///02020
//02110
//02200
//03010
//03100
//04000
//20020
//11020
//11110
//11200
//12010
//12100
//13000
//22020
const ll mod=998244353;
vector<vector<ll>>calc(vector<vector<ll>>v,bool flag=false){
    if(!flag){
        vector<vector<ll>>sums(v.size(),vector<ll>(v[0].size()+1));
        for(int y=0;y<v.size();++y){
            for(int x=0;x<v[0].size();++x){
                sums[y][x+1]+=v[y][x];
                sums[y][x+1]+=sums[y][x];

                sums[y][x+1]%=mod;
            }
        }
        return sums;
    }else{
        vector<vector<ll>>sums(v.size()+1,vector<ll>(v[0].size()+1));
        for(int y=0;y<v.size();++y){
            for(int x=v[0].size()-1;x>=0;--x){
                sums[y+1][x]+=v[y][x];
                sums[y+1][x]+=sums[y][x+1];

                sums[y+1][x]%=mod;
            }
        }
        return sums;
    }
}

void dfsb(int now ,const Graph&g,int &num,vector<int>&ls,vector<int>&rs){
    ls[now]=num;
    for(auto e:g[now]){ 
        dfsb(e,g,num,ls,rs);
    }
    num++;
    rs[now]=num;
}

using Value1=pair<int,int>;
using Value2=int;
const Value1 Zero1= make_pair(10000000,1);
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
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}
 
	void lazy_func(const int k, const int a, const int b) {
		if (dat[k].lazy)dat[k].sum.first+=dat[k].lazy;
		else {
		}
	}
 
	Value1 connect(const Value1 l, const Value1 r) {
		if(l.first==r.first)return make_pair(l.first,l.second+r.second);
        else{
            return min(l,r);
        }
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

lazy_segtree seg(0);
ll answer=0;
void dfsa(int now,const Graph&g,const vector<int>&ls,const vector<int>&rs){
    seg.update(ls[now],rs[now],1);
    auto p=seg.get(0,g.size());
    //WHATS(now)
    //WHATS(p)
    if(p.first==0){
        answer+=p.second;
    }
    for(auto e:g[now]){
        dfsa(e,g,ls,rs);
    }
    seg.update(ls[now],rs[now],-1);

}
void solve(Graph g_a,Graph g_b){
    const int N=g_a.size();
    vector<int>b_ls(N,-1),b_rs(N,-1);

    

    vector<int>comes_a(N),comes_b(N);
    for(int i=0;i<N;++i){
        for(auto e:g_a[i]){
            comes_a[e]++;
        }
        for(auto e:g_b[i]){
            comes_b[e]++;
        }
    }
    {
        int num=0;
        for(int start=0;start<N;++start){
            if(comes_b[start]==0)dfsb(start,g_b,num,b_ls,b_rs);

        }
    }
    //WHATS(b_ls)
    ////WHATS(b_rs)
    //WHATS(comes_a)
    //WHATS(g_a)
    {
        seg=lazy_segtree(N);
        seg.update(0,N,-10000000);
        for(int start=0;start<N;++start){
            if(comes_a[start]==0){
                dfsa(start,g_a,b_ls,b_rs);
            }
        }
    }
    answer=ll(N)*N-answer;
    
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    string A,B;cin>>A>>B;
    if(count(A.begin(),A.end(),'0')!=count(B.begin(),B.end(),'0')){
        cout<<-1<<endl;
    }else{
        int answer=0;
        
        vector<int>nums(N);
        for(int i=0;i<N;++i){
            nums[i]+=(A[i]-'0')*2+(B[i]-'0');
        }
        int amin=0;
        int amax=0;
        int now=0;
        vector<int>v{0,1,-1,0};
        for(int i=0;i<N;++i){
            now+=v[nums[i]];
            amax=max(amax,now);
            amin=min(amin,now);
            answer=max(answer,amax-now);
            answer=max(answer,now-amin);
        }
        cout<<answer<<endl;
    }
    return 0;
}