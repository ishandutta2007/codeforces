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

//using Graph=vector<vector<pair<int,ll>>>;
	
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
const int mod=998244353;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie();
    //init();
    int N,M;cin>>N>>M;
    vector<int>as(N);
    vector<int>bs(M);
    for(int i=0;i<N;++i)scanf("%d",&as[i]);
    for(int i=0;i<M;++i)scanf("%d",&bs[i]);
    //WHATS(as)
    //WHATS(bs)
    vector<vector<int>>places(M+1,vector<int>(2));
    for(int i=0;i<N;++i){
        auto lt=lower_bound(bs.begin(),bs.end(),as[i]);
        auto rt=upper_bound(bs.begin(),bs.end(),as[i]);

        
            places[lt-bs.begin()][0]=i+1;
        {
            places[rt-bs.begin()][1]=i+1;
        }
        //WHATS(places)
    }
    //WHATS(places)
    ll answer=1;
    
    if(places[M][1]!=N)answer=0;
    for(int i=0;i<M;++i){
        if(i==0){
            if(places[i][1]!=0)answer=0;
            if(places[i][0]==0)answer=0;
       }else answer*=places[i][0]-places[i][1];
        //if(places[i][0]==0)answer=0;
        answer%=mod;
        //WHATS(answer)
    }
    if(answer<0)answer=0;
    cout<<answer<<endl;
    
	return 0;
}