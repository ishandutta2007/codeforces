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


const int MAX_N=40;

int solve1(vector<int>cnts,vector<int>trashes,bool mkbig=false){
	int answer=0;
	for(int i=MAX_N;i>=0;--i){
		
		if(cnts[i]<trashes[i]){
			//WHATS(cnts)
			//WHATS(trashes)
			return -1;
		}else{
			while(cnts[i]){
				for(int j=0;j<=i;++j){
					cnts[j]--;
				}
				bool flag=false;
				
				for(int j=i;j>=0;--j){
					if(trashes[j]){
						trashes[j]--;
						flag=true;
						break;
					}
				}
				if(mkbig){
					if(!flag){
						for(int j=0;j<=i;++j){
							if(j==MAX_N||cnts[j]>cnts[j+1]){
								cnts[j]--;
								flag=true;
								break;
							}
						}
					}
					
				}
				
				answer++;
			}
			
		}
	}
	
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;cin>>N;
	vector<vector<ll>>costs(N,vector<ll>(N));
	ll min_cost=1e18;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			cin>>costs[i][j];
			costs[j][i]=costs[i][j];
			min_cost=min(min_cost,costs[i][j]);
		}
		costs[i][i]=ll(1e18);
	}
	
	//WHATS(costs)
	vector<ll>anss(N,ll(1e18));
	vector<pair<ll,int>>ps(N);
	for(int i=0;i<N;++i){
		ps[i]=make_pair(*min_element(costs[i].begin(),costs[i].end()),i);
	}
	sort(ps.begin(),ps.end());
	//WHATS(ps)
	for(auto p:ps){
		ll acost=p.first;
		int now=p.second;
		if(acost==min_cost){
			anss[now]=0;
		}else{
			anss[now]=min(anss[now],2*(acost-min_cost));
			for(int i=0;i<N;++i){
				if(i==now)continue;
				if(costs[now][i]!=acost)continue;
				anss[now]=min(anss[now],acost-min_cost+anss[i]);
			}
		}
		for(int i=0;i<N;++i){
			if(i==now)continue;
			anss[i]=min(anss[i],anss[now]+costs[now][i]-min_cost);
		}
		//WHATS(anss)
	}
	for(int i=0;i<N;++i){
		cout<<min_cost*(N-1)+anss[i]<<'\n';
	}
	return 0;
}