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

void check(){
    for(int N=10;N<=110;++N){
        vector<int>v(3*N+1,1);
        for(int j=N;j>=1;--j){
            if((v[j+1]==false)||(v[2*j]==false)){
                v[j]=true;
            }else{
                v[j]=false;
            }
        }
        cout<<N<<endl;
        for(int i=0;i<=N;++i){
            char ch='0'+i;
            if(i>=10)ch='a'+(i-10);

            cout<<ch;
        }
        cout<<endl;
        for(int i=0;i<=N;++i){
            if(i==0)cout<<'x';
            else cout<<v[i];
        }
        cout<<endl;
    }
}

bool solve(ll awin,ll S){
    while(true){
        if(awin<=S)return true;
        else{
            if(awin%2==0){
                return !((awin-S)%2);
            }else{
                ll nwin=(awin+3)/4;
                ll nlose=(awin+1)/2;
                if(nlose<=S)return !((awin-S)%2);
                else if(nwin<=S)return true;

                awin=nwin;
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int N;cin>>N;
    vector<int>types(N);

    bool canfst,cansnd;
    canfst=true;
    cansnd=false;
    for(int i=0;i<N;++i){
        ll S,E;cin>>S>>E;
        ll awin=S;

        
        bool fst_win=solve(E+1,S);
        bool fst_lose=solve((E+2)/2,S);

       // WHATS(fst_win)
        //WHATS(fst_lose)

        bool ncanfst=false,ncansnd=false;
        if(canfst){
            if(fst_win)ncanfst=true;
            if(fst_lose)ncansnd=true;
        }
        if(cansnd){
            if(!fst_win)ncanfst=true;
            if(!fst_lose)ncansnd=true;
        }
        canfst=ncansnd;
        cansnd=ncanfst;
       // WHATS(canfst)
        //WHATS(cansnd)
        
    }
    cout<<cansnd<<' '<<canfst<<endl;
	return 0;
}