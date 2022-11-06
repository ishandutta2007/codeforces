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

using ll =long long ;
ll mod;
int MAX_N=251;
vector<vector<vector<int>>>memo(MAX_N,vector<vector<int>>(MAX_N,vector<int>(MAX_N)));
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	string st;cin>>st;
	vector<vector<int>>rs(26,vector<int>(N+2));
	for(int i=N+1;i>=0;--i){
		for(int j=0;j<26;++j){
			if(st[i]=='a'+j){
				rs[j][i]=i+1;
			}else{
				if(i!=N+1)rs[j][i]=rs[j][i+1];
				else rs[j][i]=N+1;
			}
		}
	}
	vector<string>sts(3);
	for(int i=0;i<M;++i){
		char ch;cin>>ch;
		//WHATS(sts)
		//WHATS(memo)
		if(ch=='+'){
			int x;
			char c;cin>>x>>c;x--;
			int num=c-'a';
			sts[x].push_back(c);
			{
				vector<int>ls(3,0);
				ls[x]=sts[x].size();
				for(int i=ls[0];i<=sts[0].size();++i){
					for(int j=ls[1];j<=sts[1].size();++j){
						for(int k=ls[2];k<=sts[2].size();++k){
							
							memo[i][j][k]=N+1;
							if(i)memo[i][j][k]=min(memo[i][j][k],rs[sts[0][i-1]-'a'][memo[i-1][j][k]]);
							if(j)memo[i][j][k]=min(memo[i][j][k],rs[sts[1][j-1]-'a'][memo[i][j-1][k]]);
							if(k)memo[i][j][k]=min(memo[i][j][k],rs[sts[2][k-1]-'a'][memo[i][j][k-1]]);
						}
					}
				}	
			}
		}else{
			int x;cin>>x;x--;
			sts[x].pop_back();
		}
		
		if(memo[sts[0].size()][sts[1].size()][sts[2].size()]!=N+1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;	
}