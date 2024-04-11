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
map<pair<int,int>,int>mp;
int H,W;
int ask(const vector<set<int>>&lines,int x,int y){
	//WHATS(x)
	//WHATS(y)
	if(mp.find(make_pair(x,y))!=mp.end())return mp[make_pair(x,y)];
	else{
		auto it=lines[H+1+x-y].lower_bound(y);
		if(it==lines[H+1+x-y].end()){
			//cout<<x+(H+1-y)<<endl;
			return mp[make_pair(x,y)]=min(x+(H+1-y),W-1);
		}else{
			int ay=*it;
			int ax=x+ay-y-1;
			return mp[make_pair(x,y)]=ask(lines,ax,ay);
		}
	}
}
vector<int>solve(vector<int>ps){
	vector<set<int>>lines(H+W+1);
	vector<int>rs(W);
	for(int i=0;i<H;++i){
		lines[ps[i]+H-i].emplace(i);
	}
	mp.clear();
	for(int x=0;x<W;++x){
		int y=0;
		rs[x]=ask(lines,x,y);
	}
	return rs;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>W>>H;
	vector<int>ps(H);
	for(int  i=0;i<H;++i){
		int a;cin>>a;a--;
		ps[i]=a;
		
	}
	vector<int>rs=solve(ps);
	for(int i=0;i<H;++i){
		ps[i]=W-1-ps[i];
	}
	//WHATS(ps)
	vector<int>ls=solve(ps);
	ll ans=0;
	//WHATS(rs)
	//WHATS(ls)
	for(int i=0;i<W;++i){
		ans+=1+rs[i]-i;
		ans+=ls[i]-i;
	}
	if(W==1)ans=0;
	cout<<ans<<endl;
	return 0;
}