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


vector<ll>as,wes;
using Value=pair<ll,ll>;
const Value ini =make_pair(0,0ll);
const ll mod=1e9+7;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	Value v=make_pair(al.first+ar.first,al.second+ar.second);
    if(v.second>=mod)v.second-=mod;

    return v;
}
//    Value dat[800001];

struct segtree {
	int N;
    vector<Value>dat;
	segtree() {}
	
	segtree(int n,vector<Value>v)  {
		N = 1;
        dat.resize(800001);
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			if(x<v.size()){
				dat[x+N-1]=v[x];
			}else{
				dat[x+N-1] = ini;
			}
		}
		for(int x=N-2;x>=0;--x){
			dat[x]=connect(dat[x*2+1],dat[x*2+2]);
		}
	}
	// update k th element
	void update(int k,const Value& a) {
		 k += N - 1;
		dat[k] = a;
		
		while (k > 0) {
			k = (k - 1) >>1;
			dat[k]=connect(dat[k * 2 + 1],dat[k * 2 + 2]);
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}

    int dfs(int k,int l,int r,ll need){
        {
            if(l+1==r){
                if(dat[k].first>=need)return r;
                else return l;
            }else{
                int m((l+r)/2);
                if(dat[2*k+1].first>=need){
                    return dfs(2*k+1,l,m,need);
                }else{
                    return dfs(2*k+2,m,r,need-dat[2*k+1].first);
                }
            }
        }
    }
};

int main() {
    //cout<<3<<endl;
	ios::sync_with_stdio(false);
	cin.tie();
    int N,Q;cin>>N>>Q;
    as=vector<ll>(N);
    wes=vector<ll>(N);
    for(int i=0;i<N;++i)cin>>as[i];
    for(int i=0;i<N;++i)cin>>wes[i];

    vector<Value>v1(N),v2(N);
    for(int i=0;i<N;++i){

        as[i]-=i;
        v1[i]=make_pair(wes[i],as[i]*wes[i]%mod);
        v2[i]=make_pair(wes[i],(mod*mod-as[i]*wes[i])%mod);

    }
    segtree seg1(N,v1),seg2(N,v2);
    for(int i=0;i<Q;++i){
        int id;cin>>id;
        if(id<0){
            id=-(id+1);
            ll nw;
            cin>>nw;
            seg1.update(id,make_pair(nw,as[id]*nw%mod));
            seg2.update(id,make_pair(nw,(mod*mod-as[id]*nw)%mod));

        }else{
            int l=id-1;
            int r;cin>>r;

            ll total_weight=seg1.query(l,r).first;
            ll l_weight=seg1.query(0,l).first;
            int m=seg1.dfs(0,0,seg1.N,l_weight+(total_weight+1)/2);
            m--;
            auto r_p=seg1.query(m+1,r);
            auto l_p=seg1.query(l,m);

            //WHATS(m)
            //WHATS(l_p)
            //WHATS(r_p)

            ll r_answer=r_p.second-r_p.first*as[m];
            ll l_answer=l_p.second-l_p.first*as[m];
            l_answer=-l_answer;

            ll answer=(l_answer+r_answer)%mod;
            if(answer<0)answer+=mod;
            cout<<answer<<endl;
        }
    }
	return 0;
}