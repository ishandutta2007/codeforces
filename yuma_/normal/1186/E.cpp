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


using ll=long long ;

#define WHAT(var) cout<<__LINE__<<' '<<#var<<" : "<<var<<endl;
const int MAX_N=1e5;

vector<vector<int>>field;

int H,W,Q;

vector<vector<int>>sums;
ll solve(ll h,ll w){
	int ah=(h/(2*H)*(2*H));
	int aw=(w/(2*W)*(2*W));

	ll sum=h*w-(h-ah)*(w-aw);

	sum/=2;
//	WHATS(sum)
	int place_y=ah/(2*H);
	int place_x=aw/(2*W);
	int cnt=(__builtin_popcount(place_y)^__builtin_popcount(place_x));
	// WHATS(cnt)
	// WHATS(h)
	// WHATS(w)
	//WHATS(ah)
//	WHATS(aw)
	//WHATS(field)

	ll plus=sums[h-ah][w-aw];
	// for(int y=ah;y<h;++y){
	// 	for(int x=aw;x<w;++x){
	// 		sum+=(cnt&1)^(field[y-ah][x-aw]);
	// 	}
	// }
	if(cnt&1)plus=(h-ah)*(w-aw)-plus;
	sum+=plus;
	//WHATS(sum)
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>H>>W>>Q;
	field=vector<vector<int>>(2*H,vector<int>(2*W));
	sums=vector<vector<int>>(2*H+1,vector<int>(2*W+1));
	for(int y=0;y<H;++y){
		string st;cin>>st;
		for(int x=0;x<W;++x){
			for(int w=0;w<4;++w){
				int ny=y,nx=x;
				if(w&1)ny+=H;
				if(w&2)nx+=W;
				field[ny][nx]=(w==1||w==2)^(st[x]=='1');
			}
		}
	}
	for(int y=0;y<2*H;++y){
		for(int x=0;x<2*W;++x){
			sums[y+1][x+1]=sums[y][x+1]+sums[y+1][x]-sums[y][x]+field[y][x];
		}
	}
	while(Q--){
		int u,l,d,r;cin>>u>>l>>d>>r;
		u--;l--;
		ll answer=solve(d,r)-solve(d,l)-solve(u,r)+solve(u,l);
		cout<<answer<<endl;
	}
}