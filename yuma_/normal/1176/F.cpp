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

using ll = long long int;

vector<pair<ll,ll>>solve(){
	int K;cin>>K;
	vector<pair<ll,ll>>anss(4);
	vector<vector<ll>>costs(3,vector<ll>(3,-1e17));
	for(int i=0;i<K;++i){
		int c,d;cin>>c>>d;
		costs[c-1].push_back(d);

	}
	for(int i=0;i<3;++i){
		sort(costs[i].begin(),costs[i].end(),greater<ll>());
		costs[i].resize(3);
	}
	vector<ll>ones{costs[0][0],costs[1][0],costs[2][0]};
	vector<ll>twos{costs[0][0],costs[0][1],costs[1][0]};
	sort(ones.begin(),ones.end(),greater<ll>());
	sort(twos.begin(),twos.end(),greater<ll>());
	vector<ll>threes{costs[0][0],costs[0][1],costs[0][2]};
	sort(threes.begin(),threes.end(),greater<ll>());
	anss[0]=make_pair(0,0);
	anss[1]=make_pair(ones[0],ones[0]);
	anss[2]=make_pair(twos[0]+twos[1],twos[0]);
	anss[3]=make_pair(threes[0]+threes[1]+threes[2],threes[0]);

	return anss;
}
int main() {
	ios::sync_with_stdio(false);
	int T;cin>>T;
	vector<vector<pair<ll,ll>>>costs(T);
	for(int turn=0;turn<T;++turn){
		costs[turn]=solve();
	}
	vector<vector<ll>>memo(T+1,vector<ll>(10,-1e18));
	memo[0][0]=0;
	for(int i=0;i<T;++i){
		int cur=i&1;
		int tar=cur^1;
		for(int x=0;x<10;++x){
			if(memo[i][x]<0)continue;

			for(int use=0;use<=3;++use){
				int y=x+use;
				ll plus=costs[i][use].first;
				if(y>=10){
					plus+=costs[i][use].second;
				}
				memo[i+1][y%10]=max(memo[i+1][y%10],memo[i][x]+plus);
			}
		}
	}
	ll answer=-1;
	for(int x=0;x<10;++x)answer=max(answer,memo[T][x]);
	//WHATS(memo)
	cout<<answer<<endl;
	return 0;
}