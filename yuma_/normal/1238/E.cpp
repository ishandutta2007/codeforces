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

using ll = long long int;

int memo[1<<20];
int N,M;
int field[20][20];
int solve(bitset<20>bs,int sum){
	//WHATS(sum)
	//WHATS(bs.to_ulong());
	if(memo[bs.to_ulong()]==-1){
		if(bs.count()==M){
			return memo[bs.to_ulong()]=0;
		}
		memo[bs.to_ulong()]=1e9;
		for(int use=0;use<M;++use){
			if(bs[use])continue;
			else{
				int asum=sum;
				for(int i=0;i<M;++i){
					if(i==use)continue;
					if(bs[i]){
						asum-=field[i][use];
					}else{
						asum+=field[i][use];
					}
				}
				//WHATS(use)
				//WHATS(asum)
				bs[use]=true;
				int nans=solve(bs,asum)+asum;
				bs[use]=false;
				memo[bs.to_ulong()]=min(memo[bs.to_ulong()],nans);
			}
		}
		//WHATS(bs.to_ulong());
		//WHATS(memo[bs.to_ulong()]);
		return memo[bs.to_ulong()];
	}else{
		return memo[bs.to_ulong()];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin>>N>>M;
	string st;cin>>st;
	for(int i=0;i<20;++i){
		for(int j=0;j<20;++j){
			field[i][j]=0;
		}
	}
	for(int i=0;i<N-1;++i){
		int a=st[i]-'a';
		int b=st[i+1]-'a';
		field[a][b]++;
		field[b][a]++;
	}
	
	for(int i=0;i<(1<<20);++i)memo[i]=-1;
	bitset<20>bs(0);
	int answer=solve(bs,0);
	cout<<answer<<endl;
	return 0;
}