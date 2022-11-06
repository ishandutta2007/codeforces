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
ll solve(vector<ll>v){
	ll answer=0;
	sort(v.begin(),v.end());
	for(int i=0;i<3;++i)answer+=v[i]*v[i];
	answer+=v[0]*7;
	return answer;
}




int main() {
	ios::sync_with_stdio(false);
	string A,B;cin>>A>>B;
	vector<int>ls(A.size()+1),rs(A.size()+1,int (B.size()));
	for(int i=0;i<A.size();++i){
		if(ls[i]!=B.size()&&B[ls[i]]==A[i]){
			ls[i+1]=ls[i]+1;
		}else{
			ls[i+1]=ls[i];
		}
	}
	//WHATS(ls)
	for(int i=A.size()-1;i>=0;--i){
		if(rs[i+1]!=0&&B[rs[i+1]-1]==A[i]){
			rs[i]=rs[i+1]-1;
		}else{
			rs[i]=rs[i+1];
		}
	}
	vector<vector<int>>sums(26,vector<int>(B.size()+1));
	for(int i=0;i<B.size();++i){
		for(int j=0;j<26;++j){
			if('a'+j==B[i]){
				sums[j][i+1]=sums[j][i]+1;
			}else{
				sums[j][i+1]=sums[j][i];
			}
		}
	}
	//WHATS(sums)
	//WHATS(rs)
	bool ok=true;
	if(ls[A.size()]!=B.size()){
		ok=false;
	}else{
		
		for(int i=0;i<A.size();++i){
			int lp=rs[i];
			int rp=ls[i+1];
			int xx=A[i]-'a';

			if(sums[xx][rp]-sums[xx][lp]==0)ok=false;

		}
	}
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}