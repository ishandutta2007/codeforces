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


using ll=long long ;

class HashVI {  // nbVIuWFNg
public:
	size_t operator()(const vector<int> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			t = t * C + x[i];
		}
		return t;
	}
	size_t operator()(const vector<vector<int>> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			for (int j = 0; j < x[i].size(); ++j) {
				t = t * C + x[i][j];
			}
		}
		return t;
	}
};
#include<unordered_map>
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>x(N);
	for(int i=0;i<N;++i){
		cin>>x[i];
	}
	unordered_map<vector<int>,int,HashVI>mp;
	for(int up=0;up<(1<<15);++up){
		vector<int>nums(N);
		int mask=up<<15;
		for(int k=0;k<N;++k){
			int from=x[k]&(((1<<15)-1)<<15);
			nums[k]=__builtin_popcount(from^mask);
		}
		int me=*min_element(nums.begin(),nums.end());
		for(auto&nu:nums)nu-=me;
		if(mp.find(nums)==mp.end())mp[nums]=up;
	}

	int answer=-1;
	for(int down=0;down<(1<<15);++down){
		vector<int>nums(N);
		int mask=down;
		for(int k=0;k<N;++k){
			int from=x[k]&((1<<15)-1);
			nums[k]=__builtin_popcount(from^mask);
		}
		int ma=*max_element(nums.begin(),nums.end());
		for(auto&nu:nums)nu=ma-nu;
		auto it=mp.find(nums);
		//WHATS(down)
		//WHATS(nums)
		if(it!=mp.end()){
			answer=(it->second<<15)+down;
			break;
		}
	}
	cout<<answer<<endl;
	return 0;
}