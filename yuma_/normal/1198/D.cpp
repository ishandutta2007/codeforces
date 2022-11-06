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
vector<string>field;
vector<vector<int>>sums;
int memo[51][51][51][51];
int getsum(int l,int r,int u,int d){
	int asum=sums[r][d]-sums[r][u]-sums[l][d]+sums[l][u];
	return asum;
}
int solve(int l,int r,int u,int v){
	if(getsum(l,r,u,v)==0){
		return memo[l][r][u][v]=0;
	}else{
		if(memo[l][r][u][v]==-1){
			int ans=max(r-l,v-u);
			for(int y=u+1;y<v;++y){
				int asum=solve(l,r,u,y)+solve(l,r,y,v);
				ans=min(ans,asum);
			}
			for(int x=l+1;x<r;++x){
				int asum=solve(l,x,u,v)+solve(x,r,u,v);
				ans=min(ans,asum);
			}
			memo[l][r][u][v]=ans;
		}
		//cout<<l<<r<<u<<v<<' '<<memo[l][r][u][v]<<endl;
		return memo[l][r][u][v];
	}
}
int main() {
	
	ios::sync_with_stdio(false);
	int N;cin>>N;
	field.resize(N);
	sums=vector<vector<int>>(N+1,vector<int>(N+1));
	for(int i=0;i<N;++i)cin>>field[i];
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			sums[i+1][j+1]=sums[i+1][j]+sums[i][j+1]-sums[i][j]+(field[i][j]=='#');
		}
	}
	for(int i=0;i<51;++i){
		for(int j=0;j<51;++j){
			for(int k=0;k<51;++k){
				for(int l=0;l<51;++l){
					memo[i][j][k][l]=-1;
				}
			}
		}
	}
	int ans=solve(0,N,0,N);
	cout<<ans<<endl;
	
	return 0;
}