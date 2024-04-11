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
using ld = __float128;
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
struct Compress {
	map<long long int, int>mp;
	map<int, long long int>revmp;

	Compress(vector<long long int>vs) {
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
};


int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<string>sts(N);
	for(int i=0;i<N;++i)cin>>sts[i];

	map<int,int>ls,rs;
	for(int i=0;i<N;++i){
		int cnt=0;
		bool ok=true;
		for(auto c:sts[i]){
			if(c=='('){
				cnt++;
			}else{
				cnt--;
			}
			if(cnt<0)ok=false;
			
		}
		if(ok)ls[cnt]++;
		reverse(sts[i].begin(),sts[i].end());
		cnt=0;
		ok=true;
		for(auto c:sts[i]){
			if(c==')'){
				cnt++;
			}else{
				cnt--;
			}
			if(cnt<0)ok=false;
			
		}
		if(ok)rs[cnt]++;
	}
	ll answer=0;
	for(auto m:ls){
		answer+=ll(m.second)*rs[m.first];
	}
	cout<<answer<<endl;
	return 0;
}