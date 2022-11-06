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

	
using ll = long long int;

pair<int,int> say(vector<int>v){
    cout<<"? "<<v.size();
    for(auto x:v)cout<<' '<<x+1;
    cout<<endl;

    int a;cin>>a;
    int b;cin>>b;
    return make_pair(a-1,b);;
}
void dfs(const Graph&g,int now,int from,vector<int>&pas,vector<int>&ds,int depth){
    ds[now]=depth;
    pas[now]=from;
    for(auto e:g[now]){
        if(e==from)continue;
        else{
            dfs(g,e,now,pas,ds,depth+1);
        }
    }
}
void get_d(const Graph&g,int now,int from,int start,int rest_depth,int depth,vector<int>&anss,int cantgo=-1){
    if(now==cantgo)return;
    
    if(now==start){
        rest_depth=depth;
        WHATS(now)
    }else{
        if(rest_depth==0){
            anss.push_back(now);
        }else if(rest_depth>=1){
        }
    }
    for(auto e:g[now]){
        if(e==from)continue;
        get_d(g,e,now,start,rest_depth-1,depth,anss,cantgo);
    }
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie();
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        Graph g(N);
        for(int i=0;i<N-1;++i){
            int u,v;cin>>u>>v;u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int root,sum;

        {
            vector<int>v(N);
            iota(v.begin(),v.end(),0);
            auto p=say(v);
            root=p.first;
            sum=p.second;
        }
        vector<int>pas(N);
        vector<int>depths(N);
        dfs(g,root,-1,pas,depths,0);

        int l=root;
        int r=root;
        int rest=sum;

        while(rest>=1){
            int to_l=-1,to_r=-1;
            {
                if(l!=root){
                    int now(l);
                    while(pas[now]!=root){
                        now=pas[now];
                    }
                    to_l=now;
                }

                if(r!=root){
                    int now(r);
                    while(pas[now]!=root){
                        now=pas[now];
                    }
                    to_r=now;
                }
            }
            WHATS(l)
            WHATS(r)
            WHATS(rest)
            int adepth=(rest+1)/2;
            vector<int>l_cands,r_cands;
            WHATS(root)
            WHATS(to_l)
            get_d(g,root,-1,l,-1,adepth,l_cands,to_r);
            get_d(g,root,-1,r,-1,adepth,r_cands,to_l);
            vector<int>anss(l_cands);
            anss.insert(anss.end(),r_cands.begin(),r_cands.end());
            sort(anss.begin(),anss.end());
            anss.erase(unique(anss.begin(),anss.end()),anss.end());
            WHATS(l_cands)
            WHATS(r_cands)
            auto p=say(anss);
            int now=p.first;
            {
                int tt(now);
                while(tt!=l&&tt!=r){
                    tt=pas[tt];
                    if(tt==-1)assert(false);
                }
                if(tt==l){
                    rest-=depths[now]-depths[l];

                    l=now;
                }else{
                    assert(tt==r);
                    rest-=depths[now]-depths[r];

                    r=now;
                }
            }
            
        }
        cout<<"! "<<l+1<<' '<<r+1<<endl;
        string st;cin>>st;
        

    }
    return 0;
}