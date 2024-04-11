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
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14

12 1 11
13 3 10
14 5 9
15 7 8
16 2 14
17 4 13
18 6 12

1-12

11 1 10
12 3 9
13 5 8
13 6 7
14 2 12
15 4 11
*/

const int MAX_X=2220;

using ll=long long ;


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
	ll A,B;cin>>A>>B;
	if(A==B){
		cout<<0<<endl;
	}else{
		if(A<B)swap(A,B);
		auto divs=divisor(A-B);
		pair<ll,ll>answers(ll(6e18),-1);
		for(auto div:divs){
			ll need_plus=div-(A%div);
			if(need_plus==div)need_plus=0;
			ll answer=(A+need_plus)*(B+need_plus)/div;
			answers=min(answers,make_pair(answer,need_plus));
		}
		cout<<answers.second<<endl;

	}
	return 0;
}