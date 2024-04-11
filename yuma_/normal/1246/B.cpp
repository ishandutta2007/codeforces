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
using ll =long long ;	
vector<vector<int>>chs;
vector<int>ds;
vector<int>answers;
vector<int>ops;
void dfs(int now){
	ds[now]=0;
	for(auto e:chs[now]){
		dfs(e);
		ds[now]=max(ds[now],1+ds[e]);
	}

}
void solve(int now,int next){
	answers.push_back(now);
	vector<pair<int,int>>ps;
	for(auto e:chs[now]){
		ps.push_back(make_pair(ds[e],e));
	}
	sort(ps.begin(),ps.end());
	for(int i=0;i<ps.size();++i){	
		int an=-1;
		if(i!=ps.size()-1)an=ps[i+1].second;
		else{
			an=next;
		}
		solve(ps[i].second,an);
	}
	if(next!=-1)ops.push_back(next);

}
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
#include<unordered_map>
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
	size_t operator()(const map<ll,int>&mp) const {
		const int C = 997;      // f
		size_t t = 0;
		for(auto m:mp){
			
			t=t*C+m.first;
			t=t*(C+100)+m.second;
		}
		return t;
	}
};
int main() {
	ios::sync_with_stdio(false);
	int N;ll K;cin>>N>>K;
	unordered_map<map<ll,int>,int,HashVI>ump;
	ll answer=0;
	for(int i=0;i<N;++i){
		ll x;cin>>x;
		auto k=soinnsuu(x);
		map<ll,int>need;
		for(auto m :k){
			int xx=m.second%K;
			xx=K-xx;
			if(xx==K){

			}else{
				need[m.first]=xx;
			}
		}
		auto it=ump.find(need);

		if(it!=ump.end()){
			answer+=it->second;
		}
		for(auto&m :need){
			int xx=m.second%K;
			xx=K-xx;
			if(xx==K){

			}else{
				need[m.first]=xx;
			}
		}
		
		ump[need]++;
	}
	cout<<answer<<endl;
	return 0;	
}