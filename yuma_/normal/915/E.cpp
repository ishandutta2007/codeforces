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
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

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


#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
template<typename T> struct Compress {
	map<T, int>mp;
	map<int, T>revmp;
	
	Compress(vector<T>vs) {
		setmp(vs);
	}
	
	Compress() :mp(), revmp() {
	
	}
	void setmp(vector<T>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
};
	
typedef int Value1;
typedef int Value2;
const Value1 Zero1 = 0;
const Value2 Zero2(0);
	
struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
vector<int>sums;
struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		if (sums.size() < N + 1) {
			int aa = sums.size();
			int bb = sums.back();
			sums.resize(N + 1);
			fill(sums.begin() + aa, sums.end(), bb);
		}
		for (int i = 2 * N - 1; i >= 1; --i) {
			if (i >= N) {
				dat[i].sum = sums[i - N + 1] - sums[i - N];
			}
			else {
				update_node(i);
			}
		}
	}
	
	inline Value2 lazy_connect(const Value2 l, const Value2 r) {
		if (r == 0)return l;
		else return r;
	}
	
	inline Value1 eval(const int a,const int b ,const Value1&x, const Value2&y) {
		if (y == 1) {
			return sums[b]-sums[a];
		}
		else {
			return Zero1;
		}
	}
	
	inline void lazy_func(const int k, const int a, const int b) {
		dat[k].sum=eval(a,b,dat[k].sum,dat[k].lazy);
	}
	
	inline Value1 connect(const Value1 l, const Value1 r) {
		return l + r;
	}
	
	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		if (!dat[k].lazy)return;
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
	
	void update(int l, int r, Value2 v) {
		update(l, r, v, 1, 0, N);
	}
	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k, int a, int b) {
		lazy_evaluate_node(k, a, b); 	// .
	
		if (b <= l || r <= a) //[a,b)[l,r)
			return;
		if (l <= a && b <= r) { // [l,r)[a,b)
			dat[k].lazy = v;
			lazy_func(k,a,b);
			return;
		}
	
		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	Value1 get(int l, int r) {
		return get(l, r, 1, 0, N);
	}
	//get(l,r) := [l,r). 0-indexed.
	Value1 get(int l, int r, int k, int a, int b) {
	
		lazy_evaluate_node(k, a, b); // .
	
		if (l <= a && b <= r) { // [l,r)[a,b)
			return dat[k].sum;
		}
	
		int m = (a + b) / 2;
		if (r <= m) {
			return get(l, r, k * 2, a, m);
		}
		else if (m <= l) {
			return get(l, r, k * 2 + 1, m, b);
		}
		return connect(get(l, r, 2 * k, a, m), get(l, r, 2 * k + 1, m, b));
	}
};
	
	
	
struct query {
	int type;
	int l;
	int r;
};
// void solve(){
// 	vector<vector<int>>vs(3);
// 	for(int i=0;i<3;++i){
// 		int x;cin>>x;
// 		for(int j=0;j<x;++j){
// 			int k;cin>>k;
// 			vs[x].push_back(k);
// 		}
// 	}
// 	for(int i=0;i<2;++i){
// 		if(vs[i]%2==0){
// 			int k=vs[i]/2;
// 		}
// 	}
// }
int main() {
	//ios::sync_with_stdio(false);
	int N, Q; cin >> N >> Q;
	
	map<int,int>ls;
	ls[N]=0;
	int answer=N;
	while(Q--){
		int l,r;
		int type;
		scanf("%d%d%d",&l,&r,&type);
		l--;
		{
			auto it=ls.lower_bound(l);
			while(it!=ls.end()){
				int al=it->second,ar=it->first;
				if(r<al)break;
				answer-=ar-al;
				it=ls.erase(it);
				if(ar>r){
					answer+=ar-r;
					ls[ar]=r;
				}
				if(l>al){
					answer+=l-al;
					ls[l]=al;
				}
			}
		}
		//WHATS(answer)
		if(type==2){
			answer+=r-l;
			ls[r]=l;
		}
		//cout<<answer<<endl;
		printf("%d\n",answer);
	}
	
	return 0;
}