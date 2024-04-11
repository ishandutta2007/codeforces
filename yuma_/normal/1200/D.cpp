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

int main() {

	ios::sync_with_stdio(false);
	int N,K;cin>>N>>K;
	vector<string>field(N);
	for(int i=0;i<N;++i)cin>>field[i];

	vector<pair<int,int>>row_bs(N,make_pair(N,-1));
	vector<pair<int,int>>col_bs(N,make_pair(N,-1));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(field[i][j]=='B'){
				row_bs[i].first=min(row_bs[i].first,j);
				row_bs[i].second=max(row_bs[i].second,j);

				col_bs[j].first=min(col_bs[j].first,i);
				col_bs[j].second=max(col_bs[j].second,i);
			}
		}
	}
	int answer=0;
	vector<vector<int>>pluss(N-K+3,vector<int>(N-K+3));
	vector<vector<int>>sums(N-K+2,vector<int>(N-K+2));

	for(int i=0;i<N;++i){
		if(row_bs[i]==make_pair(N,-1)){
			answer++;
		}else{
			int min_x=max(0,row_bs[i].second-K+1);
			int max_x=min(N-K,row_bs[i].first);
			//WHATS(row_bs[4])
			//WHATS(col_bs[0])
			int min_y=max(0,i-K+1);
			int max_y=min(N-K,i);
			if(min_x>max_x || min_y>max_y)continue;

			pluss[min_y][min_x]++;
			pluss[min_y][max_x+1]--;
			pluss[max_y+1][min_x]--;
			pluss[max_y+1][max_x+1]++;
		}
	}

	for(int i=0;i<N;++i){
		if(col_bs[i]==make_pair(N,-1)){
			answer++;
		}else{
			int min_y=max(0,col_bs[i].second-K+1);
			int max_y=min(N-K,col_bs[i].first);

			int min_x=max(0,i-K+1);
			int max_x=min(N-K,i);
			
			if(min_x>max_x || min_y>max_y)continue;

			pluss[min_y][min_x]++;
			pluss[min_y][max_x+1]--;
			pluss[max_y+1][min_x]--;
			pluss[max_y+1][max_x+1]++;
		}
	}
	for(int y=1;y<=N-K+1;++y){
		for(int x=1;x<=N-K+1;++x){
			sums[y][x]=sums[y-1][x]+sums[y][x-1]-sums[y-1][x-1]+pluss[y-1][x-1];
		}
	}
	// WHATS(pluss)
	// WHATS(sums)
	int xx=0;
	for(int y=0;y<=N-K;++y){
		for(int x=0;x<=N-K;++x){
			int nans=sums[y+1][x+1];
			xx=max(xx,nans);
		}
	}
	cout<<answer+xx<<endl;
	return 0;
}