#define _CRT_SECURE_NO_WARNINGS
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
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;

#define ll long long
#define ld long double

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


vector<pair<ll,ll>>v;
vector<int>solve(){
    vector<int>anss;
    //WHATS(v)
    for(int i=0;i<v.size();++i){
        if((v[i].first+v[i].second)%2==0){
            anss.push_back(i);
        }
    }
    if(anss.empty()||anss.size()==v.size()){
        
        for(int i=0;i<v.size();++i){
            if(anss.empty())v[i].first++;
            ll nx=(v[i].first-v[i].second)/2;
            ll ny=(v[i].first+v[i].second)/2;

            v[i]=make_pair(nx,ny);
        }
        return solve();
    }else{
        return anss;
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int N;cin>>N;
    
    for(int i=0;i<N;++i){
        ll x,y;cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    auto ans=solve();
    cout<<ans.size()<<endl;
    for(auto an:ans){
        cout<<an+1<<' ';
    }
    cout<<endl;
    return 0;
}