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
using Hash=pair<ll,ll>;
static const ll mul0 = 10009, mul1 = 10007;
static const ll add0 = 1000010007, add1 = 1003333331;
static const ll mod0 = 1000000007, mod1 = 1000000009;

void add(vector<Hash>& hs,int x){
	Hash ah=hs.back();
	ah.first=(ah.first*mul0+add0+x)%mod0;
	ah.second=(ah.second*mul1+add1+x)%mod1;
	hs.push_back(ah);
}	

int main() {
	ios::sync_with_stdio(false);
	int H,W,K;cin>>H>>W>>K;
	vector<string>field(H);
	for(int i=0;i<H;++i)cin>>field[i];
	int dy[]={0,-1,1,0,0};
	int dx[]={0,0,0,-1,1};
	int id=0;
	vector<vector<pair<int,int>>>answers;
	for(int sz=1;sz<300;++sz){
		for(int y=0;y<H;++y){
			for(int x=0;x<W;++x){
				bool ok=true;
				for(int way=0;way<5;++way){
					int nx=x+dx[way]*sz;
					int ny=y+dy[way]*sz;
					if(nx<0|| nx>=W)ok=false;
					if(ny<0||ny>=H)ok=false;

					if(ok&&field[ny][nx]=='.')ok=false;
				}
				if(ok){
					id++;
					if(id==K){
						
						answers.push_back(vector<pair<int,int>>(5));
						for(int way=0;way<5;++way){
							int nx=x+dx[way]*sz;
							int ny=y+dy[way]*sz;
							answers.back()[way]=make_pair(nx,ny);
						}
					}
				}
			}
		}
	}
	if(answers.size()==0)cout<<-1<<endl;
	else{
		for(int i=0;i<5;++i){
			cout<<1+answers[0][i].second<<' '<<1+answers[0][i].first<<endl;
		}
	}
	return 0;
}