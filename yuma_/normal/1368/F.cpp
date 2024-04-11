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

int say(vector<int>v){
    cout<<v.size();
    for(auto x:v)cout<<' '<<x+1;
    cout<<endl;

    int a;cin>>a;
    a--;
    return a;
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie();
    int N;cin>>N;
    pair<int,int>p(0,-1);
    for(int i=1;i<N;++i){
        int ans=(N-((N-1)/(i+1)+1))-i;
        p=max(p,make_pair(ans,i));
        
    }
    if(p.first==0){

    }else{
        vector<int>v(N);
        int num=p.second+1;
        for(int i=0;i<N;++i){
            if(i%num==0){

            }else{
                v[i]=true;
            }
        }
        while(true){
            vector<int>says;
            for(int i=0;i<N;++i){
                if(v[i]==1){
                    says.push_back(i);
                }
            }
            if(says.size()<=p.second){
                break;
            }else{
                int l=say(says);
                for(int i=0;i<N;++i){
                    if(v[i]==1){
                        v[i]=2;
                    }
                }
                for(int i=0;i<says.size();++i){
                    int x=(l+i)%N;
                    if(v[x]==2){
                        v[x]=1;
                    }
                }
            }
        }
    }
        cout<<0<<endl;


    return 0;
}