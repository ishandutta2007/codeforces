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
int say(vector<int>v){
    assert(!v.empty());
    cout<<"? "<<v.size();
    for(auto x:v){
        cout<<' '<<x+1;
    }
    cout<<endl;
    ll num;cin>>num;
    return num;
}
void say2(vector<ll>v){
    cout<<"!";
    for(auto x:v){
        cout<<' '<<x;
    }
    cout<<endl;
}
#include<random>
const int mod=1e9+7;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie();
    int N,M,Q;cin>>N>>M>>Q;
    Q++;
    Q++;
    Graph g(N);
    vector<ll>max_lens(N);
    for(int i=0;i<M;++i){
        int u,v;
        ll cost;
        cin>>u>>v>>cost;
        u--;v--;
        g[u].push_back(make_pair(v,cost));
        g[v].push_back(make_pair(u,cost));
        max_lens[u]=max(max_lens[u],cost);
        max_lens[v]=max(max_lens[v],cost);
    }
    vector<vector<ll>>dp(N,vector<ll>(N,ll(-1e18)));
    dp[0][0]=0;
    for(int i=0;i<N-1;++i){
        for(int now=0;now<N;++now){
            for(auto e:g[now]){
                dp[i+1][e.first]=max(dp[i][now]+e.second,dp[i+1][e.first]);
            }
        }
    }
    const int offset=N;

    // y = fi * x + se
    vector<pair<ll,ll>>lines;
    for(int i=0;i<N;++i){
        lines.emplace_back(max_lens[i],dp[N-1][i]);
    }
    sort( lines.begin(), lines.end());
    {
        vector<pair<ll,ll>>newlines;
        for(int i=0;i<N;++i){
            while((!newlines.empty())&&newlines.back().second<=lines[i].second){
                newlines.pop_back();
            }
            newlines.emplace_back(lines[i]);
        }
        WHATS(lines)
        lines=newlines;
    }
    WHATS(dp)
    WHATS(lines)

    // x y katamuki
    vector<pair<ll,pair<ll,ll>>>coors;
    coors.emplace_back(0,make_pair(lines[0].second,lines[0].first));
    for(int i=1;i<int(lines.size());++i){
        while(!coors.empty()){
            ll x,y,kata;
            x=coors.back().first;
            y=coors.back().second.first;
            kata=coors.back().second.second;

            ll mykata=lines[i].first;
            ll mysy=lines[i].second;
            ll dy=y-(mykata*x+mysy);

            if(dy<=0){
                coors.pop_back();
            }else{
                ll dx=(dy-1)/(mykata-kata)+1;
                coors.emplace_back(x+dx,make_pair(mysy+mykata*(x+dx),mykata));
                break;
            }
        }
    }
    WHATS(coors)

    ll answer=0;
    for(int i=0;i<N-1;++i){
        answer+=*max_element(dp[i].begin(),dp[i].end());
    }
    WHATS(answer)
    answer%=mod;
    for(int i=0;i<coors.size();++i){
        ll can_use=0;
        if(i==int(coors.size())-1){
            can_use=Q-N-coors[i].first;
        }else{
            can_use=Q-N-coors[i].first;
            can_use=min(can_use,coors[i+1].first-coors[i].first);
        }
        can_use=max(can_use,0ll);
        
        WHATS(can_use)
        ll miny=coors[i].second.first;
        ll maxy=miny+(can_use-1)*coors[i].second.second;

        miny%=mod;
        maxy%=mod;
        ll plus=(miny+maxy)*can_use;
        
        if(plus%2)plus+=mod;
        answer+=plus/2;
        answer%=mod;
    }
    cout<<answer<<endl;
    
	return 0;
}