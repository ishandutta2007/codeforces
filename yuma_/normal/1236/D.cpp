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


int main() {
	ios::sync_with_stdio(false);
	int H,W;cin>>H>>W;
	int Q;cin>>Q;
	vector<set<int>>xs(H);
	vector<set<int>>ys(W);
	for(int i=0;i<Q;++i){
		int x,y;cin>>y>>x;
		x--;y--;
		xs[y].emplace(x);
		ys[x].emplace(y);
	}
	int nx=0;
	int ny=0;
	ll sum=1;
	int way=2;

	int l=0,r=W-1,u=1,d=H-1;
	int kk=0;
	while(true){
		kk++;
		//WHATS(nx)
		//WHATS(ny)
		//WHATS(way)
		if(way==2){
			auto it=xs[ny].lower_bound(nx);
			int nextx=r;
			if(it==xs[ny].end()){
			}else{
				nextx=(*it)-1;
			}
			nextx=min(nextx,r);
			//WHATS(nextx)
			if(nx==nextx&&kk!=1){
				break;
			}else{
				sum+=nextx-nx;
				r=nextx-1;
				nx=nextx;
			}
		}else if(way==3){
			auto it=ys[nx].lower_bound(ny);
			int nexty=d;
			if(it==ys[nx].end()){
			}else{
				nexty=(*it)-1;
			}
			nexty=min(nexty,d);
			if(ny==nexty){
				break;
			}else{
				sum+=nexty-ny;
				d=nexty-1;
				ny=nexty;
			}
		}else if(way==0){
			auto it=xs[ny].lower_bound(nx);
			int nextx=l;
			if(it==xs[ny].begin()){
			}else{
				nextx=(*prev(it))+1;
			}
			nextx=max(nextx,l);
			if(nx==nextx){
				break;
			}else{
				sum+=-nextx+nx;
				l=nextx+1;
				nx=nextx;
			}
		}else if(way==1){
			auto it=ys[nx].lower_bound(ny);
			int nexty=u;
			if(it==ys[nx].begin()){
			}else{
				nexty=(*prev(it))+1;
			}
			nexty=max(nexty,u);
			if(ny==nexty){
				break;
			}else{

				sum+=-nexty+ny;
				u=nexty+1;
				ny=nexty;
			}
		}

		way++;
		way%=4;
	}
	
	if(sum+Q==ll(H)*W){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}