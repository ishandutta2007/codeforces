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

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}

	
using ll = long long int;
void dfs(int now,int from,const vector<vector<int>>&graph,vector<int>&dists,int d){
	dists[now]=d;
	for(auto e:graph[now]){
		if(e!=from)dfs(e,now,graph,dists,d+1);
	}
}
vector<int>get_diamater(const vector<vector<int>>&graph){
	vector<int>dists(graph.size());
	dfs(0,-1,graph,dists,0);
	int k=max_element(dists.begin(),dists.end())-dists.begin();
	dfs(k,-1,graph,dists,0);
	int j=max_element(dists.begin(),dists.end())-dists.begin();

	vector<int>dias;
	int now=j;
	while(now!=k){
		dias.push_back(now);
		for(auto e:graph[now]){
			if(dists[e]==dists[now]-1){
				now=e;
				break;
			}
		}
	}
	dias.push_back(now);
	return dias;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int N;cin>>N;
    Graph g(N);
    for(int i=0;i<N-1;++i){
        int u,v;cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dias=get_diamater(g);
    int l=dias[0];
    int r=dias.back();

    vector<int>l_lens(N),r_lens(N);
    dfs(l,-1,g,l_lens,0);
    dfs(r,-1,g,r_lens,0);

    vector<pair<int,pair<int,int>>>anss;
    vector<int>in_dias(N);
    for(auto xx:dias)in_dias[xx]=true;
    ll answer=0;

    
    for(int i=0;i<N;++i){
        if(!in_dias[i]){
            int l_len=l_lens[i];
            int r_len=r_lens[i];
            answer+=max(l_len,r_len);
            if(l_len<r_len){
                anss.push_back(make_pair(r_len,make_pair(i,r)));
            }else{

                anss.push_back(make_pair(l_len,make_pair(i,l)));
            }
        }
    }
    sort(anss.begin(),anss.end());
    reverse(anss.begin(),anss.end());

    for(int i=0;i<int(dias.size())-1;++i){
        answer+=r_lens[dias[i]];
        anss.push_back(make_pair(-1,make_pair(dias[i],r)));
    }
    cout<<answer<<endl;
    for(int i=0;i<N-1;++i){
        cout<<anss[i].second.second+1<<' '<<anss[i].second.first+1<<' '<<anss[i].second.first+1<<endl;
    }
	return 0;
}