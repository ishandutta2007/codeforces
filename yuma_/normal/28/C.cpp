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
vector<ld>facts(51);
ld comb(int a,int b){
		return facts[a]/facts[b]/facts[a-b];
}
int main() {
	facts[0]=1;
	facts[1]=1;
	for(int i=2;i<=50;++i){
		facts[i]=facts[i-1]*i;
	}
	//WHATS(facts)
	ios::sync_with_stdio(false);
	int N;cin>>N;
	int M;cin>>M;
	vector<int>caps(M);
	for(int i=0;i<M;++i){
		cin>>caps[i];
	}
	vector<vector<vector<ld>>>dp(M+1,vector<vector<ld>>(N+1,vector<ld>(N+1)));
	dp[0][N][0]=1;
	for(int room=0;room<M;++room){
		for(int rest=0;rest<=N;++rest){
			for(int amax=0;amax<=N;++amax){
				ld per=dp[room][rest][amax];
				for(int use=0;use<=rest;++use){
					ld aper=1;
					aper=comb(rest,use)*powl(M-room-1,rest-use)/powl(M-room,rest);
					dp[room+1][rest-use][max(amax,(use-1)/caps[room]+1)]+=aper*per;
				}
			}
		}
	}
	ld answer=0;
	for(int amax=0;amax<=N;++amax){

		answer+=amax*dp[M][0][amax];
	}
	cout<<setprecision(15)<<fixed<<answer<<endl;
	return 0;
}