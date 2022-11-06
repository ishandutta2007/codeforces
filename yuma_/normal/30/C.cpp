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
using ll =long long int;
struct target{
	int t;
	ld p;
	int x;
	int y;
};
bool check(target&l,target&r){
	ll dx=l.x-r.x;
	ll dy=l.y-r.y;
	ll dt=l.t-r.t;

	if(dx*dx+dy*dy<=dt*dt){
		return true;
	}else{
		return false;
	}
}
int main() {
	
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<target>ts;
	for(int i=0;i<N;++i){
		int x,y,t;
		ld p;cin>>x>>y>>t>>p;
		ts.push_back(target{t,p,x,y});
	}
	sort(ts.begin(),ts.end(),[](const target&l,const target&r){return l.t<r.t;});
	vector<ld>memo(N,0);
	for(int i=0;i<N;++i){
		memo[i]+=ts[i].p;
		for(int j=i+1;j<N;++j){
			if(check(ts[i],ts[j])){
				memo[j]=max(memo[j],memo[i]);
			}
		}
	}
	cout<<setprecision(10)<<fixed;
	cout<<*max_element(memo.begin(),memo.end())<<endl;

	// int N,K;cin>>N>>K;
	// K--;
	// vector<pair<int,int>>ids;
	// for(int i=0;i<N;++i){
	// 	int x;cin>>x;
	// 	ids.push_back(make_pair(x,i));
	// }
	// sort(ids.begin(),ids.end());
	// int place=-1;
	// for(int i=0;i<N;++i){
	// 	if(ids[i].second==K){
	// 		place=i;
	// 		break;
	// 	}
	// }
	// pair<int,int>start;
	// vector<pair<int,int>>coors;
	// start=make_pair(ids[place].first,0);
	// if(place){
	// 	coors.push_back(make_pair(ids[0].first,0));
	// 	coors.push_back(make_pair(ids[place-1].first,0);
	// }
	// if(place+1!=N){
	// 	coors.push_back(make_pair(ids[place+1].first,0));
	// 	coors.push_back(make_pair(ids.back().first,0));

	// }
	return 0;
}