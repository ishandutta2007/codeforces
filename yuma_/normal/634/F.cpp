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
int N,K;
vector<int>nums;
vector<vector<int>>g;
int sum=0;
vector<int>szs;
vector<int>ok_cnts;
vector<int>sums;
vector<int>lens;
vector<int>anss;
void dfs(int now,int from,vector<int>&oks){
	szs[now]=1;
	if(oks[now]){
		ok_cnts[now]=1;
	}
	vector<int>v{0,0};
	for(auto e:g[now]){
		if(e==from)continue;

		dfs(e,now,oks);
		szs[now]+=szs[e];
		ok_cnts[now]+=ok_cnts[e];

		if(szs[e]==ok_cnts[e]){
			sums[now]+=szs[e];
		}else{
			v.push_back(lens[e]);
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	if(oks[now]){
		int nans=0;
		if(N-szs[now]==sum-ok_cnts[now]){
			nans+=N-szs[now];
		}
		//WHATS(v)
		nans+=1+sums[now]+v[0]+v[1];
		lens[now]=sums[now]+v[0]+1;
		anss[now]=nans;
	}
	
}
bool check(int amid){
	sum=0;
	szs=vector<int>(N);
	ok_cnts=vector<int>(N);
	sums=vector<int>(N);
	lens=vector<int>(N);
	anss=vector<int>(N);
	vector<int>oks(N);
	for(int i=0;i<N;++i){
		if(amid<=nums[i]){
			oks[i]=true;
			sum++;
		}
	}
	//WHATS(oks)
	dfs(0,-1,oks);
	//WHATS(anss)
	if(*max_element(anss.begin(),anss.end())>=K)return true;
	else return false;
}
vector<int>l_lens(10),r_lens(10);

int main() {
	
	ios::sync_with_stdio(false);
	int R,C,N,K;cin>>R>>C>>N>>K;
	vector<vector<int>>nums(C+1);
	for(int i=0;i<N;++i){
		int x,y;cin>>y>>x;
		x--;y--;
		nums[x].push_back(y);
	}
	ll answer=0;
	for(int r=1;r<=C;++r){
		list<int>alist;
		vector<vector<list<int>::iterator>>rms(C+1);

		{
			vector<pair<int,int>>v;

			for(int l=r-1;l>=0;--l){
				for(auto n:nums[l]){
					v.push_back(make_pair(n,l));
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<11;++i)alist.insert(alist.end(),-1);
			for(auto x:v){
				auto it=alist.insert(alist.end(),x.first);
				rms[x.second].push_back(it);
			}
			for(int i=0;i<11;++i)alist.insert(alist.end(),R);
			
		}

		
		ll nans=R*(R+1)/2;
		{
			vector<ll>lens;
			for(auto it=alist.begin();it!=alist.end();++it){
				if(it!=alist.begin()){
					lens.push_back(*it-*(prev(it)));
				}
			}
			for(int i=0;i<lens.size();++i){
				nans-=(lens[i]-1)*lens[i]/2;
				for(int j=i+1;j<min(i+K,int(lens.size()));++j){
					nans-=lens[i]*lens[j];
				}
			}
			//WHATS(lens)
		}
		//WHATS(nans)
		for(int l=0;l<r;++l){
			//WHATS(answer)
			//WHATS(nans)
			answer+=nans;
			for(auto rm_it:rms[l]){
				auto at=rm_it;
				auto bt=prev(rm_it);

				for(int i=0;i<K;++i){
					l_lens[i]=(*at-*bt);
					bt=prev(bt);
					at=prev(at);
				}
				at=rm_it;
				bt=next(rm_it);

				for(int i=0;i<K;++i){
					r_lens[i]=(*bt-*at);
					bt=next(bt);
					at=next(at);
				}
				for(int i=0;i<K;++i){
					nans-=l_lens[i]*r_lens[K-1-i];
				}
				alist.erase(rm_it);
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}