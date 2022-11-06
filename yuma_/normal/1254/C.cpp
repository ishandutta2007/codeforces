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
ll say(vector<int>v){
	for(int i=0;i<v.size();++i){
		cout<<v[i];
		if(i==v.size()-1)cout<<endl;
		else cout<<' ';
	}
	ll ans;cin>>ans;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<pair<ll,int>>ps;
	for(int i=2;i<N;++i){
		auto ans=say(vector<int>{1,1,2,i+1});
		ps.emplace_back(ans,i);
	}
	sort(ps.begin(),ps.end(),greater<pair<ll,int>>());

	deque<int>lows,highs;
	int low_id=-1,high_id=-1;
	for(auto p:ps){
		int id=p.second;
		auto ans=say(vector<int>{2,1,2,id+1});
		if(ans<0){
			if(lows.empty()){
				lows.push_back(id);
				low_id=id;
			}else{
				auto nans=say(vector<int>{2,1,low_id+1,id+1});
				if(nans<0){
					lows.push_front(id);
				}else{
					lows.push_back(id);
				}
			}
		}else{
			if(highs.empty()){
				highs.push_back(id);
				high_id=id;
			}else{
				auto nans=say(vector<int>{2,1,high_id+1,id+1});
				if(nans<0){
					highs.push_front(id);
				}else{
					highs.push_back(id);
				}
			}
		}
	}
	vector<int>answer;
	answer.push_back(0);
	for(auto xx:lows)answer.push_back(xx);
	answer.push_back(1);
	for(auto xx:highs)answer.push_back(xx);

	cout<<0;
	for(auto ans:answer)cout<<' '<<ans+1;
	cout<<endl;
	return 0;
}