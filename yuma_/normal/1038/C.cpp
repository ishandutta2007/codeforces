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
vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	ll answer=0;
	vector<ll>as,bs;
	for(int i=0;i<N;++i){
		int a;cin>>a;as.push_back(a);
	}
	sort(as.begin(),as.end());
	for(int i=0;i<N;++i){
		int a;cin>>a;bs.push_back(a);
	}
	sort(bs.begin(),bs.end());
	for(int i=0;i<2*N;++i){
		int aa=as.empty()?0:as.back();
		int bb=bs.empty()?0:bs.back();

		if((i&1)==0){
			if(aa<bb){
				bs.pop_back();
			}else{
				answer+=as.back();

				as.pop_back();
			}
		}else{
			if(aa<bb){
				answer-=bs.back();
				bs.pop_back();
			}else{
				as.pop_back();
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}