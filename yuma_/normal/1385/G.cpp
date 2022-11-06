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
#include<memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<pair<int,int>>>;
using ll=long long;
	
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int T;cin>>T;
	while(T--){
		int N;
		cin>>N;
		vector<vector<pair<int,int>>>places(N);
		for(int i=0;i<2;++i){
			for(int j=0;j<N;++j){
				int a;cin>>a;a--;
				places[a].push_back(make_pair(j,i));
			}
		}
		if(find_if(places.begin(),places.end(),[](const vector<pair<int,int>>&v){return v.size()!=2;})!=places.end()){
			cout<<-1<<'\n';
		}else{
			Graph g(N);
			for(int i=0;i<N;++i){
				auto l=places[i][0];
				auto r=places[i][1];
				int acost;
				if(l.second==r.second){
					acost=1;
				}else{
					acost=0;
				}
				g[l.first].push_back(make_pair(r.first,acost));
				g[r.first].push_back(make_pair(l.first,acost));

			}
			vector<int>used(N);
			vector<int>anss;
			for(int i=0;i<N;++i){
				if(used[i])continue;

				bool aon=false;
				vector<vector<int>>ids(2);
				int now=i;
				while(true){
					//WHATS(now)
					used[now]=true;
					ids[aon].push_back(now);
					pair<int,int>next(-1,-1);
					for(auto e:g[now]){
						if(!used[e.first]){
							next=e;
						}
					}
					//WHATS(next)
					if(next.first==-1)break;
					else{
						aon^=next.second;
						now=next.first;
					}
				}
				if(ids[0].size()<ids[1].size()){
					swap(ids[0],ids[1]);
				}
				anss.insert(anss.end(),ids[1].begin(),ids[1].end());
			}
			cout<<anss.size()<<'\n';
			for(auto ans:anss)cout<<1+ans<<' ';
			cout<<'\n';
		}
		
	}
	return 0;
}