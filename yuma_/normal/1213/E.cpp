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
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

#define WHATS(var) cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

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
struct query{
	int id;
	int a;
	int b;
};
bool operator <(const query&l,const query&r){
	return l.a<r.a;
}
string A,B;
bool ok(string st){
	if(st==A || st==B)return false;
	return true;
}
int main() {

	ios::sync_with_stdio(false);
	int N;cin>>N;
	cin>>A>>B;
	string answer;
	if(ok("ab")&&ok("bc")&&ok("ca")){
		for(int i=0;i<N;++i){
			answer+="abc";
		}
	}else if(ok("ac")&&ok("cb")&&ok("ba")){
		for(int i=0;i<N;++i){
			answer+="acb";
		}
	}else{
		vector<string>sts{
			"abc",
			"acb",
			"bac",
			"bca",
			"cab",
			"cba"
		};
		for(int i=0;i<6;++i){
			if(ok(sts[i].substr(0,2))&&ok(sts[i].substr(1,2))){
				for(int j=0;j<3;++j){
					for(int k=0;k<N;++k){
						answer+=sts[i][j];
					}
				}
				break;
			}
		}
	}
	if(answer.empty())cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl<<answer<<endl;
	}
	return 0;
}