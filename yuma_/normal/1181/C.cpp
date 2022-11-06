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
struct flag{
	string colors;
	int x;
	int u;
	int d;
	int id;
};
int main() {
	
	int H,W;cin>>H>>W;
	vector<string>field(H);
	for(int i=0;i<H;++i)cin>>field[i];

	vector<vector<flag>>uds(W);
	int id=0;
	for(int x=0;x<W;++x){
		vector<pair<char,int>>v;
		char pre='@';
		int num=0;
		for(int y=0;y<H;++y){
			if(pre!=field[y][x]){
				if(num){
					v.emplace_back(pre,num);
				}
				num=1;
				pre=field[y][x];
			}else{
				num++;
				pre=field[y][x];
			}
		}
		v.emplace_back(pre,num);
		int u=0;
		for(int i=0;i<v.size();++i){
			if(i==0||i+1==v.size()){

			}
			else{
				if(v[i].second<=v[i-1].second&&v[i].second<=v[i+1].second){
					
					string colors=string(1,v[i-1].first)+string(1,v[i].first)+string(1,v[i+1].first);
					
					if(v[i-1].first!=v[i].first&&v[i].first!=v[i+1].first){
						uds[x].push_back(flag{colors,x,u,u+v[i].second,id++});
					}
				}
			}
			u+=v[i].second;
		}
		//WHATS(v)
	}
	UnionFind uf(id);
	for(int x=0;x<W-1;++x){
		auto ud1=uds[x];
		auto ud2=uds[x+1];

		auto it=ud1.begin();
		auto jt=ud2.begin();

		while(it!=ud1.end()){
			while(jt!=ud2.end()){
				if(it->u>jt->u)jt++;
				else{
					break;
				}
			}
			if(jt!=ud2.end()){
				if(it->u==jt->u&&it->d==jt->d&&it->colors==jt->colors){
					uf.unionSet(it->id,jt->id);
				}
			}
			it++;
		}
	}
	ll answer=0;
	for(int i=0;i<id;++i){
		if(uf.root(i)==i){
			answer+=ll(uf.size(i))*ll(uf.size(i)+1)/2;
		}
	}
	cout<<answer<<endl;

	return 0;
}