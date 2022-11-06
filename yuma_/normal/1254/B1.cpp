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

#define WHAT(var) cout<<__LINE__<<' '<<#var<<" : "<<var<<endl;

const ll amod=1e9+7;
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<ll>nums(N);
	for(int i=0;i<N;++i)cin>>nums[i];
	ll sum=accumulate(nums.begin(),nums.end(),0ll);
	auto mp=soinnsuu(sum);

	ll answer=1e18;
	for(auto m:mp){
		auto div=m.first;
		ll nanswer=0;
		ll cnt=0;
		for(int i=0;i<N;++i){
			nanswer+=abs(cnt);
			cnt+=nums[i];
			cnt%=div;
			if(cnt>div/2)cnt=cnt-div;
		}
		answer=min(answer,nanswer);
	}
	if(sum==1)answer=-1;
	cout<<answer<<endl;
	return 0;
}