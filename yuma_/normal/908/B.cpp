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
	vector<string>field(H+2,string(W+2,'#'));
	int sx,sy,gx,gy;
	for(int y=1;y<=H;++y){
		string st;cin>>st;
		for(int x=1;x<=W;++x){
			field[y][x]=st[x-1];
			if(field[y][x]=='S'){
				sx=x;
				sy=y;
			}else if(field[y][x]=='E'){
				gx=x;
				gy=y;
			}
		}
	}
	vector<pair<int,int>>ways{
		make_pair(-1,0),
		make_pair(0,1),
		make_pair(1,0),
		make_pair(0,-1)
	};
	sort(ways.begin(),ways.end());
	string inst;
	cin>>inst;
	int answer=0;
	do{
		int nx=sx;
		int ny=sy;
		bool ok=false;
		for(auto x:inst){
			int num=x-'0';
			int nextx=nx+ways[num].first;
			int nexty=ny+ways[num].second;

			if(field[nexty][nextx]!='#'){
				nx=nextx;
				ny=nexty;
			}else{
				break;
			}
			if(nx==gx&&ny==gy)ok=true;
		}
		answer+=ok;
	}while(next_permutation(ways.begin(),ways.end()));
	cout<<answer<<endl;
	return 0;
}