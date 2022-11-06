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

using ll =long long ;
ll mod;
const int N=10;

int aget(int y,int x){
	if(y%2==0){
		return 99-10*y-x;
	}else{
		return 90-10*y+x;
	}
}
int main() {
	ios::sync_with_stdio(false);
	vector<int>tos(N*N);
	vector<vector<int>>field(N,vector<int>(N));
	for(int y=0;y<N;++y){
		for(int x=0;x<N;++x){
			cin>>field[y][x];
			tos[aget(y,x)]=aget(y-field[y][x],x);
		}
	}
	vector<ld>vals(N*N);
	vals[99]=0;
	for(int i=98;i>=0;--i){
		ld per=0;
		int num=0;
		for(int plus=1;plus<=6;++plus){
			if(i+plus<=99){
				per+=min(vals[i+plus],vals[tos[i+plus]]);
				num++;
			}else{
				
			}
		}
		vals[i]=6.0/num+per/num;
	}
	//WHATS(vals)
	cout<<setprecision(10)<<fixed<<vals[0]<<endl;
	
	return 0;	
}