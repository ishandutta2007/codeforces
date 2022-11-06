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
int xx;

using ll =long long ;

ll mod=1e9+7;
int main() {
	ios::sync_with_stdio(false);

  vector<int>v(1e6);
  v[0]=v[1]=1;
  for(int i=2;i<2e5;++i){
	  v[i]=v[i-1]+v[i-2];
	  v[i]%=mod;
  }
  string st;cin>>st;
  ll answer=1;
  char pre='a';
  int cnt=0;
  for(auto c:st){
	  if(pre==c){
	  	cnt++;
		  
	  }else{
		  if(pre=='u'||pre=='n'){
			  answer*=v[cnt];
			  answer%=mod;
		  }
		  cnt=1;
	  }
	  pre=c;
	  if(c=='m'||c=='w')answer=0;
  }
  if(pre=='u'||pre=='n'){
	  answer*=v[cnt];
	  answer%=mod;
  }
  cout<<answer<<endl;
	return 0;	
}