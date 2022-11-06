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
	
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
	
using ll = long long int;

struct truck{
	int id;
	ll val;
	ll pop;
	ll al;
	ll ar;
};
int main() {
	
	ios::sync_with_stdio(false);
	int N;cin>>N;
	map<int,vector<truck>>mp;
	vector<truck>trucks;
	for(int i=0;i<N;++i){
		int v,c,l,r;cin>>v>>c>>l>>r;
		mp[c+l+r].push_back(truck{i,v,c,l,r});
		trucks.push_back(truck{i,v,c,l,r});
	}
	pair<ll,vector<int>>oks(-1,vector<int>());
	for(auto m:mp){
		vector<truck>trs(m.second);
		map<int,pair<ll,int>>answer;
		answer[0]=make_pair(0,-1);
		map<int,int>pas;
		for(auto t:trs){
			if(answer.find(t.al)!=answer.end()){
				if(answer.find(t.al+t.pop)==answer.end()){
					answer[t.al+t.pop]=make_pair(answer[t.al].first+t.val,t.id);
					
				}else{
					answer[t.al+t.pop]=max(answer[t.al+t.pop],make_pair(answer[t.al].first+t.val,t.id));
				}
				pas[t.id]=answer[t.al].second;
			}
		}
		if(answer.find(m.first)!=answer.end()){
			vector<int>v;
			int now=m.first;
			int id=answer[now].second;
			while(id!=-1){
				v.push_back(id);
				id=pas[id];
			}
			oks=max(oks,make_pair(answer[m.first].first,v));
		}
	}
	//cout<<oks.first<<endl;
	cout<<oks.second.size()<<endl;
	reverse(oks.second.begin(),oks.second.end());
	for(int i=0;i<oks.second.size();++i){
		cout<<oks.second[i]+1;
		if(i==oks.second.size()-1)cout<<endl;
		else cout<<' ';
	}
	return 0;
}