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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	 int T;cin>>T;
	 while(T--){
		 int N;cin>>N;
		 vector<int>v;
		 int pre=-1;
		 int cnt=0;
		 for(int i=0;i<N;++i){
			 int x;cin>>x;
			 {
				 if(x!=pre){
					if(cnt)v.push_back(cnt);
					cnt=1;

				 }else{
					 cnt++;
				 }
			 }
			 pre=x;
		 }
		 v.push_back(cnt);
		 int gold=v[0];
		 int silver=0;
		 int bronze=0;
		 for(int i=1;i<v.size();++i){
			 if(silver<=gold){
				 silver+=v[i];
			 }else if((gold+silver+bronze+v[i])*2<=N){
				 bronze+=v[i];
			 }else{
				 break;
			 }
		 }
		if((gold+silver+bronze)*2>N || gold>=silver || gold>=bronze){
			gold=0;
			silver=0;
			bronze=0;
		}
		cout<<gold<< ' '<<silver<<' '<<bronze<<endl;
	 }
	return 0;
}