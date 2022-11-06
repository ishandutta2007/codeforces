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


using Value1=ll;
using Value2=pair<int,ll>;
const Value1 Zero1= (1ll<<60);
const Value2 Zero2(0,0);
 
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
		for (int i = 0; i < n; ++i) {
			dat[i+N].sum = Zero1;
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
        if(r.first){
            return r;
        }else{
            return make_pair(l.first,l.second+r.second);
        }
	}
 
	void lazy_func(const int k, const int a, const int b) {
        if(dat[k].lazy.first){
            dat[k].sum=dat[k].lazy.second;
        }else{
            dat[k].sum+=dat[k].lazy.second;
        }
	}
 
	Value1 connect(const Value1 l, const Value1 r) {
        return min(l,r);
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
using Graph=vector<vector<int>>;

int one_check(const Graph&g,int now,int from=-1){
    //WHATS(now)
    vector<int>nums;
    for(auto e:g[now]){
        if(e==from)continue;
        else{
            nums.push_back(1-one_check(g,e,now));
        }
    }
    if(!nums.empty()&&count(nums.begin(),nums.end(),nums[0])!=nums.size()){
        throw(false);
    }else{
        return nums.empty()?0:nums[0];
    }
}

pair<int,int> dfs(const Graph&g,int now,int from=-1){
    bool have_leaf=false;
    int sum=0;
    for(auto e:g[now]){
        if(e==from)continue;
        else{
            auto p=dfs(g,e,now);
            if(p.second)have_leaf=true;
            else{
                sum+=p.first+1;
            }
        }
    }
    if(g[now].size()==1){
        return make_pair(0,true);
    }else{
        if(have_leaf)sum++;
        return make_pair(sum,0);
    }
}

vector<int> solve(vector<int>&used){
    for(int i=1;i<used.size();++i){
        if(used[i])continue;
        for(int j=i+1;j<used.size();++j){
            if(used[j])continue;
            for(int k=j+1;k<used.size();++k){
                if(used[i]||used[j]||used[k])continue;
                else if((i^j)==k){
                    return vector<int>{i,j,k};
                }
            }
        }
    }
    return vector<int>();
}

ll solve2(ll a,ll b,ll c){
    vector<int>v;
    ll rest=b;
    while(rest){
        v.push_back(rest%4);
        rest/=4;
    }
    ll answer=a;
    ll tt=1;

    vector<vector<int>>field{
        {0,1,2,3},
        {0,2,3,1},
        {0,3,1,2}
    };
    for(int i=0;i<v.size();++i){
        answer+=field[c][v[i]]*tt;
        tt*=4;
    }

    answer+=a*c;
    return answer;
}
ll solve(ll N){
    
    ll kk=4;
    while(N>=kk){
        kk=kk*4;
    }
    ll id=N-(kk/4);

    ll place=id/3;
    ll amod=id%3;
    return solve2(kk/4,place,amod);
}
int main() {
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
 
    ios::sync_with_stdio(false);
    cin.tie();
    // vector<int>S;
    // vector<int>used(1000);
    // while(true){
    //     auto v=solve(used);
    //     if(v.empty())break;
    //     else{
    //         for(int i=0;i<3;++i){
    //             S.push_back(v[i]);
    //             used[v[i]]=true;
    //         }
            
    //     }
    // }
    // WHATS(S)

    // vector<int>S2;
    // for(int i=1;i<100;++i){
    //     S2.push_back(solve(i));
    // }
    // WHATS(S2)
    // S.resize(S2.size());
    // assert(S==S2);
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll ans=solve(N);
        cout<<ans<<endl;
    }
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14