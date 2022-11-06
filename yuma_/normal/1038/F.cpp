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
const int MAX_N=41;
int N;
string st;
long long dp[MAX_N+1][2][MAX_N][MAX_N*MAX_N];

map<string,int>idx;
vector<string>v;
set<string>pref;
long long answer=0;
void add(int len,int have,int pre,int suf,char ch){
	string cur=st.substr(0,pre);
	cur+=ch;
	while(pref.find(cur)==pref.end()){
		cur.erase(cur.begin());
	}

	int n_have=have;
	if(cur.size()==st.size()){
		n_have=true;
	}
	int n_pre=cur.size();
	cur=v[suf];
	cur+=ch;
	int n_suf=suf;
	if(cur.size()==len+1&&idx.count(cur)){
		n_suf=idx[cur];
	}
	dp[len+1][n_have][n_pre][n_suf]+=dp[len][have][pre][suf];
}
void work(int len,int have,int pre,int suf){
	if(!dp[len][have][pre][suf]){
		return ;
	}else{
		if(len==N){
			if(have){
				answer+=dp[len][have][pre][suf];
			}else{
				string cur=v[pre]+v[suf];
				if(cur.find(st)!=string::npos){
					answer+=dp[len][have][pre][suf];
				}
			}
			return ;

		}else{
			add(len,have,pre,suf,'0');
			add(len,have,pre,suf,'1');
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N>>st;
	idx[""]=0;
	v.push_back("");
	pref.insert("");
	int sz=st.size();
	for(int i=0;i<sz;++i){
		string cur="";
		for(int j=i;j<sz;++j){
			cur+=st[j];
			if(idx.count(cur)==0){
				int asz=idx.size();
				idx[cur]=asz;
				v.push_back(cur);
			}
			if(i==0){
				pref.insert(cur);
			}
		}
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=N;++i){
		for(int j=0;j<=1;++j){
			for(int k=0;k<=N;++k){
				for(int l=0;l<v.size();++l){
					work(i,j,k,l);
				}
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}