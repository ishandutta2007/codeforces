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
#include<memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}

	
using ll = long long int;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int H,W;cin>>H>>W;
	int sy,sx;
	cin>>sy>>sx;
	int L,R;cin>>L>>R;
	vector<string>field(H+2,string(W+2,'*'));
	for(int y=1;y<=H;++y){
		string st;cin>>st;
		for(int x=1;x<=W;++x){
			field[y][x]=st[x-1];
		}
	}
	deque<pair<int,int>>que;
	vector<vector<int>>min_ls(H+2,vector<int>(W+2,int(1e7)));
	min_ls[sy][sx]=0;
	que.emplace_back(sx,sy);
	while(!que.empty()){
		auto p(que.front());
		que.pop_front();
		int dx[]={-1,0,1,0};
		int dy[]={0,1,0,-1};
		int nx=p.first;
		int ny=p.second;
		int nl=min_ls[ny][nx];
		for(int way=0;way<4;++way){
			int nextx=nx+dx[way];
			int nexty=ny+dy[way];
			int nextl=nl + (way==0? 1 :0);
			int nextr=(nx-sx)+nl + (way==2?1:0);

			if(nextr<=R&&nextl<=L){
				if(field[nexty][nextx]=='.'){
					if(min_ls[nexty][nextx]>nextl){
						min_ls[nexty][nextx]=min(min_ls[nexty][nextx],nextl);
						if(nextl!=nl)que.emplace_back(nextx,nexty);
						else que.emplace_front(nextx,nexty);
					}
				}
			}
		}
	}
	int answer=0;
	for(int y=1;y<=H;++y){
		for(int x=1;x<=W;++x){
			if(min_ls[y][x]!=1e7)answer++;
		}
		//cout<<endl;
	}
	cout<<answer<<endl;

	return 0;
}