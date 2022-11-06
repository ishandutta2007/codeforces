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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;
const ll mod=1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int H,W;cin>>H>>W;
	int R;cin>>R;
	int K;cin>>K;
	int my=min(R,H-R+1);
	int mx=min(R,W-R+1);
	vector<int>ys,xs;
	for(int y=0;y<H;++y){
		int k=1+min(y,H-y-1);
		k=min(k,my);
		ys.push_back(k);
	}
	for(int x=0;x<W;++x){
		int k=1+min(x,W-x-1);
		k=min(k,mx);
		xs.push_back(k);
	}
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	priority_queue<pair<ll,pair<ll,ll>>>que;
	for(int y=0;y<ys.size();++y){
		que.emplace(ys[y]*xs.back(),make_pair(y,xs.size()-1));
	}
	//WHATS(ys)
	//WHATS(xs)
	int rest=K;
	ld answer=0;
	while(rest){
		auto p(que.top());
		que.pop();
		answer+=p.first;
		if(p.second.second){
			que.emplace(ys[p.second.first]*xs[p.second.second-1],make_pair(p.second.first,p.second.second-1));

		}
		rest--;
	}
	cout<<setprecision(10)<<fixed;
	cout<<answer/ld(W-R+1)/ld(H-R+1)<<endl;
	return 0;
}