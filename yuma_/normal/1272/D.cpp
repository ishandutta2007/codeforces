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
	int N;cin>>N;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		v.push_back(a);
	}
	vector<int>ls(N+1),rs(N+1);
	ls[0]=0;
	ls[1]=1;
	for(int i=2;i<=N;++i){
		if(v[i-2]<v[i-1])ls[i]=ls[i-1]+1;
		else ls[i]=1;
	}
	rs[N]=0;
	rs[N-1]=1;
	for(int i=N-2;i>=0;--i){
		if(v[i+1]>v[i])rs[i]=rs[i+1]+1;
		else rs[i]=1;
	}
	//WHATS(ls);
//	WHATS(rs);
	int answer=0;
	for(int k=0;k<N;++k){
		int nanswer=0;

		int al=k==0?-1:v[k-1];
		int ar=k==N-1?int(2e9):v[k+1];
		if(al<ar){
			answer=max(answer,ls[k]+rs[k+1]);
		}else{
			answer=max(answer,max(ls[k],rs[k+1]));
		}
		
	}
	answer=max(answer,ls[N]);
	cout<<answer<<endl;
	
	return 0;
}