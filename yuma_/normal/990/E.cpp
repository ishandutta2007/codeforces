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
using ld = __float128;
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
struct Compress {
	map<long long int, int>mp;
	map<int, long long int>revmp;
	
	Compress(vector<long long int>vs) {
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
};
void out(vector<vector<int>>field,bool flag=false){
	cout<<"YES"<<endl;
	for(int i=0;i<field.size();++i){
		for(int j=0;j<field[i].size();++j){
			if(flag&&i!=j)field[i][j]=!field[i][j];
			cout<<field[i][j];
		}
		cout<<endl;

	}
	return ;
}
int get_time(int N,const vector<int>&ls,int d){
	int now=0;
	int sum=0;
	while(now!=N){
		int next=ls[min(now+d,N)];
		if(now==next)return -1;
		else{
			now=next;
			sum++;
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	int N,M,K;cin>>N>>M>>K;
	vector<int>oks(N+1,true);
	for(int i=0;i<M;++i){
		int a;cin>>a;
		oks[a]=false;
	}
	ll answer=1e18;
	if(!oks[0]){
		
		
	}else{
		vector<int>ls(N+1);
		ls[0]=0;
		int pre=0;
		for(int i=1;i<=N;++i){
			if(oks[i]){
				pre=i;
			}
			ls[i]=pre;
		}
		for(int d=1;d<=K;++d){
			ll cost;cin>>cost;
			int atime=get_time(N,ls,d);
			//cout<<atime<<endl;
			if(atime==-1){

			}else{
				answer=min(answer,atime*cost);
			}
		}
	}
	if(answer>=1e17){
		cout<<-1<<endl;
	}else{
		cout<<answer<<endl;
	}
	return 0;
}