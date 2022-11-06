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

int mex(vector<int>&v){
	vector<int>cnts(v.size()+1);
	for(auto x:v)cnts[x]++;
	for(int i=0;i<cnts.size();++i){
		if(!cnts[i])return i;
	}
	return -1;
}
void pl(){
	vector<int>v{3,5,2,1,3,5,6,3,2};
	while(true){
		int x;cin>>x;
		for(int i=0;i<100;++i){
			if(find(v.begin(),v.end(),i)==v.end()){
				v[x]=i;
				break;
			}
		}
		WHATS(v)
	}
}
using ll = long long int;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int T;T=1;
	while(T--){
		int N;cin>>N;
		vector<int>v(N);
		for(int i=0;i<N;++i)cin>>v[i];
		// vector<int>nums(v);
		// sort(nums.begin(),nums.end());
		// nums.erase(unique(nums.begin(),nums.end()),nums.end());
		// map<int,int>mp;
		// for(int i=0;i<nums.size();++i)mp[nums[i]]=i;
		// for(int i=0;i<N;++i){
		// 	v[i]=mp[v[i]];
		// }
		// vector<vector<int>>places(mp.size());
		// for(int i=0;i<N;++i){
		// 	places[v[i]].push_back(i);
		// }

		// vector<vector<int>>ps(N);
		// for(int i=0;i<N;++i){
		// 	for(int j=i+1;j<N;++j){
		// 		if(v[i]>v[j]){
		// 			ps[j].push_back(i);
		// 		}
		// 	}
		// }
		vector<pair<int,int>>anss;

		// int num=mp.size()-1;
		// int id=0;
		vector<vector<int>>needs(N);
		vector<int>v2(v);
		for(int i=N-1;i>=0;--i){
			for(int j=0;j<=i;++j){
				if(v[j]>v[i])needs[i].push_back(j);
			}
		}
		for(int i=N-1;i>=0;--i){
			vector<pair<int,int>>bigs;
			for(auto j:needs[i]){
				bigs.push_back(make_pair(v2[j],j));
				
			}
			sort(bigs.begin(),bigs.end());
			for(auto big:bigs){
				anss.emplace_back(big.second,i);
				swap(v[big.second],v[i]);
			}
			//WHATS(v)
		}
		//WHATS(anss)
		cout<<anss.size()<<endl;
		for(int i=0;i<anss.size();++i){
			cout<<anss[i].first+1<<' '<<anss[i].second+1<<'\n';
		}
		assert(is_sorted(v.begin(),v.end()));
	}
	return 0;
}