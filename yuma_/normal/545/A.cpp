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

int answer=0;
int K,N;
int dfs(Graph&g,int now,int from=-1){
    int amax=0;
    for(auto e:g[now]){
        amax=max(amax,1+dfs(g,e,now));
    }
    if(amax==K-1&&(from!=0&&from!=-1)){
        amax=-1;
        answer++;
    }
    return amax;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int N;cin>>N;
    vector<vector<int>>v(N,vector<int>(N));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>v[i][j];
        }
    }
    vector<int>anss;
    for(int i=0;i<N;++i){
        bool ok=(v[i].end()==find(v[i].begin(),v[i].end(),3))&&(v[i].end()==find(v[i].begin(),v[i].end(),1));
        if(ok)anss.push_back(i);
    }
    cout<<anss.size()<<endl;
    for(auto ans:anss){
        cout<<ans+1<<' ';
    }
    cout<<endl;


    return 0;
}