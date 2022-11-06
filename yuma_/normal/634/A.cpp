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
ld dis(pair<int,int>a,pair<int,int>b){
	ld dx=a.first-b.first;
	ld dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}

using ll = long long int;

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
int main() {
	
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>perms;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		if(a)perms.push_back(a);
	}
	vector<int>perms2;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		if(a)perms2.push_back(a);
	}
	int x=-1;
	//WHATS(perms2)
	for(int i=0;i<N-1;++i){
		if(perms2[i]==perms[0]){
			x=i;
		}
	}
	bool ok=true;
	for(int i=0;i<N-1;++i){
		if(perms[i]==perms2[(i+x)%(N-1)]){

		}else{
			ok=false;
		}
	}
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}