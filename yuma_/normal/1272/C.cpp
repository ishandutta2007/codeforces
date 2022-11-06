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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;
const ll mod=1e9+7;

ll powll(ll a,ll b){
	if(b==0)return 1;
	else{
		ll x=powll(a,b/2);
		x*=x;
		x%=mod;
		if(b%2)x*=a;
		x%=mod;
		return x;
	}
}
#include<random>
int gcd(int a,int b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
bool check(vector<int>ls,vector<int>rs){
	set<pair<int,int>>aset;
	for(int i=0;i<ls.size();++i){
		for(int j=i+1;j<ls.size();++j){
			int dl=ls[i]-ls[j];
			int dr=rs[j]-rs[i];
			pair<int,int>ap=make_pair(dl/gcd(dl,dr),dr/gcd(dl,dr));
			if(aset.find(ap)!=aset.end())return false;
			else aset.emplace(ap);
			//cout<<ap.first<<' '<<ap.second<<endl;
		}
	}
	return true;
}

vector<int>bfs(int from,const vector<vector<int>>&edges){
	queue<int>que;
	que.emplace(from);
	vector<int>memo(edges.size(),100000000);
	memo[from]=-1;
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto e:edges[now]){
			if(memo[e]>memo[now]+1){
				memo[e]=memo[now]+1;
				que.emplace(e);
			}
		}
	}
	return memo;
}
struct aa{
	int a;
	int b;
	int c;
	int cost;
};
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie();
	vector<int>v;
	int N,M;cin>>N>>M;
	string st;cin>>st;
	vector<int>oks(26);
	for(int i=0;i<M;++i){
		char ch;cin>>ch;
		oks[ch-'a']=true;
	}
	vector<vector<int>>rs(N+1,vector<int>(26));
	for(int i=0;i<26;++i){
		rs[N][i]=N;
		for(int x=N-1;x>=0;--x){
			if(st[x]=='a'+i){
				rs[x][i]=x;
			}else{
				rs[x][i]=rs[x+1][i];
			}
		}
	}
	ll answer=0;
	ll num=0;
	for(int l=0;l<N;++l){
		int ar=N;
		for(int i=0;i<26;++i){
			if(!oks[i]){
				ar=min(ar,rs[l][i]);
			}
		}
		answer+=ar-l;
	}
	cout<<answer<<endl;
	return 0;
}