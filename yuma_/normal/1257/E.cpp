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
	vector<vector<int>>vs(3);
	int N=0;
	for(int i=0;i<3;++i){
		int a;cin>>a;
		vs[i].resize(a);
		N+=a;
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<vs[i].size();++j)cin>>vs[i][j];
		sort(vs[i].begin(),vs[i].end());
	}
	vector<vector<int>>nums(4,vector<int>(N+1));
	for(int i=0;i<vs[0].size();++i){
		nums[0][i+1]=i+1;
	}
	nums[1][vs[1][0]]=1+(lower_bound(vs[0].begin(),vs[0].end(),vs[1][0])-vs[0].begin());
	for(int i=0;i<vs[1].size();++i){
		int k=lower_bound(vs[0].begin(),vs[0].end(),vs[1][i])-vs[0].begin();
		nums[1][i+1]=max(nums[1][i]+1,nums[0][k]+1);
	}
	for(int i=0;i<vs[2].size();++i){
		int k=lower_bound(vs[1].begin(),vs[1].end(),vs[2][i])-vs[1].begin();
		nums[2][i+1]=max(nums[2][i]+1,nums[1][k]+1);

		k=lower_bound(vs[0].begin(),vs[0].end(),vs[2][i])-vs[0].begin();
		nums[2][i+1]=max(nums[2][i+1],nums[0][k]+1);
	}
	//WHATS(nums)
	int answer=N-nums[2][vs[2].size()];
	answer=min(answer,N-nums[0][vs[0].size()]);
	answer=min(answer,N-nums[1][vs[1].size()]);
	cout<<answer<<endl;
	return 0;
}