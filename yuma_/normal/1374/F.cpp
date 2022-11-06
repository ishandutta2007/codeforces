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

vector<int>anss;
void rot(vector<pair<int,int>>&v,vector<int>&places,int l){
    anss.emplace_back(l);
    std::rotate(v.begin()+l,v.begin()+l+2,v.begin()+l+3);
    for(int x=l;x<l+3;++x){
        places[v[x].first]=x;
    }
}
vector<int>solve(vector<pair<int,int>>v,vector<int>places){
    anss.clear();
    for(int i=0;i<int(v.size())-2;++i){
        int aplace=places[i];
        while(i<aplace){
            //WHATS(v)
            if(i+1==aplace){
                rot(v,places,i);
                rot(v,places,i);
                aplace--;
            }else{
                rot(v,places,aplace-2);
                aplace-=2;
            }
            assert(v[aplace].first==i);
        }
    }

    //WHATS(v)
    int rest=3;
    while(rest--){
        if(v[v.size()-2]<v[v.size()-1]&&v[v.size()-3]<v[v.size()-2])return anss;
        else{
            rot(v,places,v.size()-3);
           
        }
    }
    return vector<int>{-1};
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<pair<int,int>>v(N);
        vector<int>places(N);
        vector<pair<int,int>>ps;
        
        for(int i=0;i<N;++i){
            cin>>v[i].first;
            v[i].second=v[i].first;
            ps.emplace_back(v[i].first,i);
        }
        sort(ps.begin(),ps.end());
        for(int i=0;i<N;++i){
            places[i]=ps[i].second;
            v[places[i]].first=i;
        }
        auto ans1=solve(v,places);
        for(int i=0;i<N-1;++i){
            if(ps[i].first==ps[i+1].first){
                swap(places[i],places[i+1]);
                swap(v[places[i]].first,v[places[i+1]].first);
                break;
            }
        }
        auto ans2=solve(v,places);
        vector<int>answer{-1};
        bool ok=true;
        if((!ans1.empty())&&ans1[0]==-1){
            if((!ans2.empty())&&ans2[0]==-1){
                ok=false;
            }else{
                answer=ans2;
            }
        }else{
            answer=ans1;
        }
        if(!ok)cout<<-1<<endl;
        else {
            cout<<answer.size()<<endl;
            for(auto ans:answer)cout<<ans+1<<' ';
            cout<<endl;
        }
    }

	return 0;
}