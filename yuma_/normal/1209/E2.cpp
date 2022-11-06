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
	
	
using ll = long long int;

void solve(ll N ,ll K){
	ll sz=K*K+1;
	
	ll type=(N-1)/sz;
	ll id=(N-1)%sz;

	vector<ll>v;
	{
		ll now=type;
		while(now){
			v.push_back(now%K);
			now/=K;
		}
		reverse(v.begin(),v.end());
	}
	WHATS(v)

	ll now_selected=K*(K+1)/2-1;
	for(int i=0;i<v.size();++i){
		WHATS(now_selected)
		ll l=v[i]*K;
		ll r=(v[i]+1)*K;
		if(r<=now_selected){
			now_selected=K*(K+1)/2-(v[i]+1);
		}else if(now_selected<=l){
			now_selected=K*(K+1)/2-(v[i]+1)+K;
		}else{
			now_selected=K*(K+1)/2-(v[i]+1)+(r-now_selected);
		}
	}
	if(id==now_selected){

	}
	cout<<now_selected+1+type*sz<<endl;
}
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}



int main() 
{
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		int N,M;cin>>N>>M;
		vector<vector<int>>cols(M,vector<int>(N));
		for(int y=0;y<N;++y){
			for(int x=0;x<M;++x){
				cin>>cols[x][y];
			}
		}
		sort(cols.begin(),cols.end(),[](const vector<int>&l,const vector<int>&r){
			return *max_element(l.begin(),l.end())>*max_element(r.begin(),r.end());
		});
		if(cols.size()>=N){
			cols.resize(N);
			M=N;
		}
		
		vector<vector<int>>memo(M+1,vector<int>(1<<N));
		for(int x=0;x<M;++x){
			vector<int>pluss(1<<N);
			for(int i=0;i<N;++i){
				pluss[(1<<i)]=cols[x][i];
			}
			for(int k=0;k<N;++k){
				for(int i=0;i<(1<<N);++i){
					if(i&(1<<k))pluss[i]+=pluss[i^(1<<k)];
				}
			}
			for(int use=0;use<(1<<N);++use){
				for(int u=0;u<N;++u){
					int ause=(use>>u)+((use&((1<<u)-1))<<(N-u));
					pluss[use]=max(pluss[use],pluss[ause]);

				}
			}
			
			for(int bs=0;bs<(1<<N);++bs){
				int mask=((1<<N)-1)^bs;
				for(int use=mask; use>=0; use=(use-1)&mask) {
					//WHATS(bs)
					//WHATS(use)
					
					int plus=pluss[use];
					memo[x+1][bs|use]=max(memo[x+1][bs|use],memo[x][bs]+plus);
				
					if(!use)break;
				}
			}
		}
		cout<<memo[M][(1<<N)-1]<<endl;
	}
	return 0;
}