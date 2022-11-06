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
using ll = long long int;

using Graph=vector<vector<pair<int,ll>>>;
	
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

	

void say(int A,int B,int X){
    for(int x=0;x<A;++x){
        cout<<'x'<<' '<<endl;
    }
    for(int x=A;x<B;++x){
        cout<<X<<' '<<endl;
    }
    for(int x=B;x<B+5;++x){
        cout<<X+(B-x+1)<<' '<<endl;
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int N,M;cin>>N>>M;
    vector<pair<ll,int>>ps;
    for(int i=0;i<N;++i){
        ll a;cin>>a;
        ps.emplace_back(a,i);
    }
    sort(ps.begin(),ps.end());

    Graph g(N);
    for(int i=1;i<N;++i){
        int u=ps[0].second;
        int v=ps[i].second;
        ll cost=ps[i].first+ps[0].first;
        g[u].push_back(make_pair(v,cost));
        g[v].push_back(make_pair(u,cost));
    }
    for(int i=0;i<M;++i){
        int u,v;
        ll cost;
        cin>>u>>v>>cost;
        u--;v--;
        
        g[u].push_back(make_pair(v,cost));
        g[v].push_back(make_pair(u,cost));
    
    }
    vector<int>used(N);
    priority_queue<pair<ll,int>>que;
    que.emplace(0,0);
    ll answer=0;
    while(!que.empty()){
        auto p(que.top());
        que.pop();
        int now=p.second;
        if(used[now])continue;
        used[now]=true;
        answer+=-p.first;

        for(auto e:g[now]){
            if(!used[e.first]){
                que.emplace(-e.second,e.first);
            }
        }
    }
    cout<<answer<<endl;
	return 0;
}