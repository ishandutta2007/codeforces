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
	int N,M;cin>>N>>M;
	ll bou,inc,dam;cin>>bou>>inc>>dam;
	vector<ll>mhs,shs,res;

	vector<vector<pair<ll,ll>>>qs(N);
	for(int i=0;i<N;++i){
		int a,b,c;cin>>a>>b>>c;
		mhs.push_back(a);
		shs.push_back(b);
		res.push_back(c);
		qs[i].push_back(make_pair(0,b));
	}
	for(int i=0;i<M;++i){
		int t,e,h;cin>>t>>e>>h;
		e--;
		qs[e].push_back(make_pair(t,h));
	}
	bool flag=false;
	map<ll,ll>nums;
	for(int i=0;i<N;++i){

		sort(qs[i].begin(),qs[i].end());
		if(inc){
			
			if(mhs[i]<=dam)flag=true;
			if(qs[i].back().second<=dam&&res[i]==0)flag=true;
		}
		//WHATS(flag)
		if(flag)break;
		qs[i].push_back(make_pair(ll(3e9),mhs[i]));

		for(int j=0;j<qs[i].size()-1;++j){
			ll t=qs[i][j].first;
			ll h=qs[i][j].second;

			if(h>dam){

			}else{
				nums[t]++;
				ll need_time=1e18;
				if(res[i]){
					need_time=max(1ll,1ll+(dam-h)/res[i]);
				}else{
					
				}	
				need_time=min(need_time,qs[i][j+1].first-t);
				nums[t+need_time]--;
			
			}
			
		}
	}
	//WHATS(nums)
	//for(auto m:nums)WHATS(m)
	int sum=0;
	ll answer=0;
	if(flag){
		answer=-1;
	}else{
		for(auto m:nums){
			if(m.first){
				if(sum){
					ll nanswer=sum*((m.first-1)*inc+bou);
					answer=max(answer,nanswer);
				}
			}
			sum+=m.second;
		}
	}
	cout<<answer<<endl;
	
	return 0;
}