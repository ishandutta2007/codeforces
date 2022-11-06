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
using Graph=vector<vector<pair<int,int>>>;
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
void add_edge(Graph&g,int u,int v,int cost){
	g[u].push_back(make_pair(v,cost));
}

int solve(const Graph&g,int s,int t){
	vector<int>memo(g.size(),int(2e9));
	memo[s]=0;
	deque<int>que;
	que.emplace_back(s);
	while(!que.empty()){
		int now=que.front();
		que.pop_front();
		for(auto e:g[now]){
			int nextcost=memo[now]+e.second;
			if(nextcost<memo[e.first]){
				memo[e.first]=nextcost;
				if(e.second==1){
					que.emplace_back(e.first);
				}else{
					que.emplace_front(e.first);
				}
			}
		}
	}
	

	return memo[t];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	// ll M,B;cin>>M>>B;
	// ll answer=0;
	// for(int h=0;h<=B;++h){
	// 	int w=(B-h)*M;

	// 	ll nans=ll(h+w)*(h+1)*(w+1)/2;
	// 	answer=max(answer,nans);
	// 	//WHATS(nans);
	// }
	// cout<<answer<<endl;

	int H,W,K;cin>>H>>W>>K;
	vector<pair<int,int>>light_coors(K);

	const int light_id=0;
	int start;
	const int row_id=light_id+K;
	const int col_id=row_id+H;
	const int goal=col_id+W;
	Graph g(goal+1);

	for(int i=0;i<K;++i){
		int y,x;cin>>y>>x;x--;y--;
		light_coors[i]=make_pair(x,y);
		if(x==0&&y==0)start=i;

		for(int dx=-1;dx<=1;++dx){
			int nx=x+dx;
			if(nx>=0&&nx<W){
				g[light_id+i].push_back(make_pair(col_id+nx,1));
				g[col_id+nx].push_back(make_pair(light_id+i,0));

			}
		}
		for(int dy=-1;dy<=1;++dy){
			int ny=y+dy;
			if(ny>=0&&ny<H){
				g[light_id+i].push_back(make_pair(row_id+ny,1));
				g[row_id+ny].push_back(make_pair(light_id+i,0));
			}
		}
		if(y==H-1&&x==W-1){
			g[light_id+i].push_back(make_pair(goal,0));
		}
	}
	g[row_id+H-1].push_back(make_pair(goal,0));
	g[col_id+W-1].push_back(make_pair(goal,0));

	for(int i=0;i<K;++i){
		int ix=light_coors[i].first;
		int iy=light_coors[i].second;
		for(int j=0;j<K;++j){
			int jx=light_coors[j].first;
			int jy=light_coors[j].second;

			if(abs(ix-jx)+abs(iy-jy)==1){
				g[light_id+i].push_back(make_pair(light_id+j,0));
			}
		}
	}
	int answer=solve(g,start,goal);
	if(answer>1e9)answer=-1;
	cout<<answer<<endl;
	return 0;
}