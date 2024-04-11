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


using Value1=int;
using Value2=int;
const Value1 Zero1= 0;
const Value2 Zero2(-1);
 
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
		for (int i = 0; i < N; ++i) {
			dat[i+N].sum = Zero1;
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		if(r!=-1)return r;
        else{
            return l;
        }
	}
 
	void lazy_func(const int k, const int a, const int b) {
		
        if(dat[k].lazy!=-1)dat[k].sum=dat[k].lazy*(b-a);
	}
 
	Value1 connect(const Value1 l, const Value1 r) {
		return l+r;

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


vector<pair<int,int>>solve(int N,vector<pair<int,int>>vs){
    vector<pair<int,int>>anss;
    lazy_segtree seg(N);
    seg.update(0,N,1);
    for(auto p:vs){
        int l=p.first;
        int r=p.second;
        if(l>r)swap(l,r);

        int al=seg.get(0,l);
        int ar=seg.get(0,r);
        seg.update(l,r,0);
        anss.emplace_back(al+1,ar);
    }
    if(seg.get(0,N)!=0)anss.emplace_back(1,seg.get(0,N));
    return anss;
}
int main() {
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    ios::sync_with_stdio(false);
    cin.tie();
    int T;cin>>T;
    
    while(T--){
        string st;cin>>st;
        vector<set<int>>cs(26);
        for(int i=0;i<st.size()-1;++i){
            
            if(st[i]==st[i+1]){
                cs[st[i]-'a'].emplace(i+1);
            }
        }
        //WHATS(cs)
        vector<pair<int,int>>answers;
        while(true){
            pair<int,int>p(-1,-1);
            int cnt=0;
            for(int i=0;i<26;++i){
                if(!cs[i].empty()){
                    p=max(p,make_pair(int(cs[i].size()),i));
                    cnt++;
                }
            }
            if(cnt==1 || cnt==0)break;
            else{
                int max_c=p.second;
                pair<int,int> max_l=make_pair(*cs[max_c].begin(),max_c);;
                pair<int,int> other_l=make_pair(int(1e7),-1);
                for(int i=0;i<26;++i){
                    if(i!=max_c&&!cs[i].empty()){
                        other_l=min(other_l,make_pair(*cs[i].begin(),i));
                    }
                }
                //WHATS(other_l)
                //WHATS(max_l)
                bool flag=false;
                {
                    
                    pair<int,int>other_m=make_pair(-1,-1);
                    for(int i=0;i<26;++i){
                        if(i!=max_c&&!cs[i].empty()){
                            auto it=cs[i].lower_bound(max_l.first);
                            if(it!=cs[i].begin()){
                                other_m=max(other_m,make_pair(*prev(it),i));
                            }
                        }
                    }
                    if(other_m.first!=-1){
                        flag=true;
                       // WHATS(max_c)
                        //WHATS(other_m)
                        answers.emplace_back(max_l.first,other_m.first);
                        cs[max_l.second].erase(max_l.first);
                        cs[other_m.second].erase(other_m.first);
                    }
                }
                if(!flag){
                    pair<int,int>max_m=make_pair(-1,-1);
                    {
                        auto it=cs[max_l.second].lower_bound(other_l.first);
                        {
                                max_m=make_pair(*prev(it),max_c);
                        }
                    }
                    {
                        answers.emplace_back(max_m.first,other_l.first);
                        cs[max_m.second].erase(max_m.first);
                        cs[other_l.second].erase(other_l.first);
                    }
                }
            }
        }
        //WHATS(answers)
        for(int i=0;i<26;++i){
            if(!cs[i].empty()){
                for(auto k:cs[i]){
                    answers.emplace_back(0,k);
                }
            }
        }
        //WHATS(answers)
        auto ans2=solve(st.size(),answers);
        //WHATS(ans2);
        cout<<ans2.size()<<endl;
        for(auto an:ans2){
            cout<<an.first<<' '<<an.second<<endl;
            //printf("%d %d\n",an.first,an.second);
        }
    }
    return 0;
}