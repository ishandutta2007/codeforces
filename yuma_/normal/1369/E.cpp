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



int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    // string st="abracadabra";
    // asuffix_array suf(st);
    // vector<int>v=suf.get_lcp();
    // WHATS(v)
    // WHATS(suf.sa)
    // WHATS(suf.rank)
    int N,M;cin>>N>>M;
    vector<int>v(N);
    for(int i=0;i<N;++i)cin>>v[i];
    vector<pair<int,int>>ps(M);
    Graph g(N);
    for(int i=0;i<M;++i){
        int a,b;cin>>a>>b;a--;b--;
        ps[i]=make_pair(a,b);
        v[a]--;
        v[b]--;
        g[a].push_back(i);
        g[b].push_back(i);
    }
    vector<int>anss;
    vector<int>oks(M);
    queue<int>que;
    for(int i=0;i<N;++i){
        if(v[i]>=0){
            for(auto e:g[i]){
                if(!oks[e]){
                    oks[e]=true;
                    que.emplace(e);
                }
            }
        }
    }
    while(!que.empty()){
        int id=que.front();
        que.pop();
        int a=ps[id].first,b=ps[id].second;

        anss.push_back(id);
        v[a]++;
        if(v[a]==0){
            for(auto e:g[a]){
                if(!oks[e]){
                    oks[e]=true;
                    que.emplace(e);
                }
            }
        }
        v[b]++;
        if(v[b]==0){
            for(auto e:g[b]){
                if(!oks[e]){
                    oks[e]=true;
                    que.emplace(e);
                }
            }
        }
    }
    if(anss.size()==M){
        cout<<"ALIVE"<<endl;
        for(int i=anss.size()-1;i>=0;--i){
            cout<<anss[i]+1<<' ';
        }
        cout<<endl;
    }else{
        cout<<"DEAD"<<endl;
    }
	return 0;
}