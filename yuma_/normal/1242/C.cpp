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

#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

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


struct node{
	int l;
	int r;
	shared_ptr<node>chl,chr;
	node(int l,int r):l(l),r(r){
		chl=nullptr;
		chr=nullptr;
	}
};
void add(shared_ptr<node>no,int x){
	int l=no->l;
	int r=no->r;
	if(l+1==r){

	}else{
		int m((l+r)/2);
		if(x<m){
			if(no->chl==nullptr){
				no->chl=make_shared<node>(l,m);
			}
			add(no->chl,x);

		}else{
			if(no->chr==nullptr){
				no->chr=make_shared<node>(m,r);

			}
			add(no->chr,x);
		}	
	}
}
int solve(shared_ptr<node>no){
	int l=no->l;
	int r=no->r;
	//WHATS(l)
	//WHATS(r)
	if(l+1==r){
		return 0;
	}else{
		int m((l+r)/2);
		if(no->chl==nullptr){
			return solve(no->chr);
		}else if(no->chr==nullptr){
			return solve(no->chl);
		}else{
			int am=solve(no->chl);
			int bm=solve(no->chr);
			return (r-l)/2+min(am,bm);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	ll sum=0;
	vector<vector<ll>>vs(N);
	map<ll,int>mp;
	vector<ll>ts(N);
	for(int i=0;i<N;++i){
		int a;cin>>a;
		for(int j=0;j<a;++j){
			ll x;cin>>x;
			mp[x]=i;
			vs[i].push_back(x);
			sum+=x;
			ts[i]+=x;
		}
	}
	if(sum%N){
		cout<<"No"<<endl;
		return 0;
	}else{
		sum/=N;
	}
	vector<vector<pair<int,int>>>answers(1<<N);
	for(int i=0;i<N;++i){
		for(auto x:vs[i]){
			int used=0;
			used|=(1<<i);
			int now=i;
			ll num=x;
			vector<pair<int,int>>anss(N,make_pair(-1,-1));
			while(true){
				WHATS(now)
				ll need=sum-ts[now]+num;
				WHATS(need)
				auto it=mp.find(need);
				if(it==mp.end())break;
				else{
					int next=it->second;
					
					if(next==i||(used&(1<<next))){
						anss[now]=(make_pair(num,next));
						break;
					}else{
						anss[now]=(make_pair(num,next));
						now=next;
						num=need;
						used|=(1<<next);
					}
				}
			}
			ll asum=0;
			int cnt=0;
			WHATS(used)
			for(int i=0;i<N;++i){
				if(used&(1<<i)){
					cnt++;
					asum+=ts[i];
				}
			}
			WHATS(asum)
			if(sum*cnt==asum){
				answers[used]=anss;
			}else{

			}
		}
	}
	WHATS(answers)
	for(int i=0;i<(1<<N);++i){
		if(answers[i].empty())continue;
		int mask=(i^((1<<N)-1));
		for(int j=mask; j>=0; j--) {
			j&=mask;
			if(answers[j].empty())continue;

			answers[i|j]=answers[i];
			for(int k=0;k<N;++k){
				if(answers[j][k].first!=-1)answers[i|j][k]=answers[j][k];
			}
		}
	}
	if(answers[(1<<N)-1].empty()){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
		vector<int>tos(N);
		for(int i=0;i<N;++i){
			auto p=answers[(1<<N)-1][i];
			tos[p.second]=i+1;
		}
		for(int i=0;i<N;++i){
			cout<<answers[(1<<N)-1][i].first<<' '<<tos[i]<<endl;
		}
	}
	return 0;
}