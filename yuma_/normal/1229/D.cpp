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
	
class HashVI {  // nbVIuWFNg
public:
	size_t operator()(const vector<int> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			t = t * C + x[i];
		}
		return t;
	}
	size_t operator()(const vector<vector<int>> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			for (int j = 0; j < x[i].size(); ++j) {
				t = t * C + x[i][j];
			}
		}
		return t;
	}
};
using ll = long long int;
unordered_map<vector<int>,int,HashVI>mp;
map<int,vector<int>>rev_mp;
vector<vector<int>>memo;
int CNT;
void ini(int K){
	vector<int>v(K);
	iota(v.begin(),v.end(),0);
	int id=0;
	do{
		mp[v]=id;
		rev_mp[id]=v;
		id++;
	}while(next_permutation(v.begin(),v.end()));
	CNT=mp.size();
	memo=vector<vector<int>>(CNT,vector<int>(CNT));

	for(int i=0;i<memo.size();++i){
		for(int j=0;j<memo.size();++j){
			vector<int>now_v(rev_mp[i]);
			vector<int>next_v(K);
			vector<int>perms(rev_mp[j]);

			for(int k=0;k<K;++k){
				next_v[k]=now_v[perms[k]];
			}
			memo[i][j]=mp[next_v];
		}
	}
}
int bfs(const vector<int>&ids){
	//WHATS(ids)
	//WHATS(memo)
	vector<int>oks(CNT);
	oks[0]=true;
	queue<int>que;
	que.emplace(0);
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto aid:ids){
			int next=memo[now][aid];
			if(!oks[next]){
				oks[next]=true;
				que.emplace(next);
			}
		}
	}
	return accumulate(oks.begin(),oks.end(),0);
}


int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	ini(M);
	map<int,pair<ll,vector<int>>>cnts;
	cnts[1]=make_pair(1,vector<int>());
	ll answer=0;
	for(int i=0;i<N;++i){
		int v_id;
		{
			vector<int>v(M);
			for(int x=0;x<M;++x){
				cin>>v[x];
				v[x]--;
			}
			//WHATS(v)
			v_id=mp[v];
		}
		//WHATS(v_id)
		map<int,pair<ll,vector<int>>>nex_cnts;
		for(auto cnt_p:cnts){
			//WHATS(cnt_p)
			int pre_num=cnt_p.first;
			vector<int>av(cnt_p.second.second);
			if(pre_num!=CNT&&find(av.begin(),av.end(),v_id)==av.end()){
				av.push_back(v_id);
				int nex_num=bfs(av);
				if(pre_num<nex_num){
					nex_cnts[nex_num].first+=cnt_p.second.first;
					nex_cnts[nex_num].second=av;
				}else{
					
					nex_cnts[pre_num].first+=cnt_p.second.first;
					nex_cnts[pre_num].second=av;
				}
			}else{
				nex_cnts[pre_num].first+=cnt_p.second.first;
				nex_cnts[pre_num].second=av;
			}
		}
		for(auto ncnt_p:nex_cnts){
			answer+=ncnt_p.first*ncnt_p.second.first;
			//WHATS(ncnt_p)
		}
		nex_cnts[1].first++;

		cnts=nex_cnts;
	}
	cout<<answer<<endl;
	return 0;
}