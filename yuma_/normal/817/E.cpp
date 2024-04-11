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
struct Node{
	int l;
	int r;
	int cnt;
	vector<shared_ptr<Node>>chs;
	Node(int l_,int r_,int cnt_):l(l_),r(r_),cnt(cnt_){
		chs=vector<shared_ptr<Node>>(2,nullptr);
	}
	bool is_leaf(){return l+1==r;}
	shared_ptr<Node>get_ch(int x){
		if(chs[x]==nullptr){
			assert(l+1<r);
			if(x==0)chs[x]=make_shared<Node>(l,(l+r)>>1,0);
			else chs[x]=make_shared<Node>((l+r)>>1,r,0);
		}
		return chs[x];
	}
};
shared_ptr<Node>mk_node(int l,int r){
	return make_shared<Node>(l,r,0);
}

void aplus(shared_ptr<Node>now,int x,int val){
	if(now->is_leaf()){
		now->cnt+=val;
		return;
	}
	int m((now->l+now->r)>>1);

	if(x<m){
		aplus(now->get_ch(0),x,val);
		
	}else{
		aplus(now->get_ch(1),x,val);
	}
	now->cnt+=val;
	// WHATS(m)
	// WHATS(now->l)
	// WHATS(now->r)
	// WHATS(now->cnt)
}
int solve(shared_ptr<Node>now,int id,int p,int l){
	int answer=0;
	if(id==-1){
		assert(now->l+1==now->r);
		return now->cnt;
	}
	if(l&(1<<id)){
		if(p&(1<<id)){
			answer+=now->get_ch(1)->cnt;
			answer+=solve(now->get_ch(0),id-1,p,l);
		}else{
			answer+=now->get_ch(0)->cnt;
			answer+=solve(now->get_ch(1),id-1,p,l);
		}
	}else{
		if(p&(1<<id)){
			answer+=solve(now->get_ch(1),id-1,p,l);

		}else{
			answer+=solve(now->get_ch(0),id-1,p,l);
		}
	}
	
	// WHATS(now->l)
	// WHATS(now->r)
	// WHATS(id)
	// WHATS(now->cnt)
	// WHATS(answer)
	return answer;
}
const int MAX_N=30;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int Q;cin>>Q;
	auto root=mk_node(0,1<<MAX_N);

	while(Q--){
		int type;cin>>type;
		if(type==1){
			int x;cin>>x;
			aplus(root,x,1);
		}else if(type==2){
			int x;cin>>x;
			aplus(root,x,-1);
		}else{
			int p,l;cin>>p>>l;
			l--;
			int answer=solve(root,MAX_N-1,p,l);
			cout<<answer<<endl;
		}
	}
	return 0;
}