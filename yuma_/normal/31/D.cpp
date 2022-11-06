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
	int W,H;cin>>W>>H;
	int N;cin>>N;
	vector<vector<int>>ws(H,vector<int>(W-1,true));
	vector<vector<int>>hs(H-1,vector<int>(W,true));
	for(int i=0;i<N;++i){
		int l,u,r,d;cin>>l>>u>>r>>d;
		if(l==r){
			for(int y=u;y<d;++y){
				ws[y][l-1]=false;
			}
		}else{
			for(int x=l;x<r;++x){
				hs[u-1][x]=false;
			}
		}
	}
	UnionFind uf(H*W);
	for(int y=0;y<H;++y){
		for(int x=0;x<W-1;++x){
			if(ws[y][x]){
				uf.unionSet(y*W+x,y*W+x+1);
			}
		}
	}
	for(int x=0;x<W;++x){
		for(int y=0;y<H-1;++y){
			if(hs[y][x]){
				uf.unionSet(y*W+x,(y+1)*W+x);
			}
		}
	}
	set<int>aset;
	vector<int>answer;
	for(int i=0;i<H*W;++i){
		int ar=uf.root(i);
		if(aset.find(ar)==aset.end()){
			aset.insert(ar);
			answer.push_back(uf.size(ar));
		}
	}
	sort(answer.begin(),answer.end());
	for(auto a:answer)cout<<a<<' ';
	
	return 0;
}