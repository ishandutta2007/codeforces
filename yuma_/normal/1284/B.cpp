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

using ll=long long;
using ld =long double;

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
    ll N;cin>>N;
    vector<pair<int,int>>ps;
    ll num=0;
    for(int i=0;i<N;++i){
        int len;cin>>len;
        int amin=1e9;
        int amax=-1;
        bool flag=false;
        for(int i=0;i<len;++i){
            int a;cin>>a;
            if(i==0)amax=a;
            if(amin<a){
                flag=true;
            }else{
                amin=a;
            }
        }
        if(flag){
            num++;
        }else{
            ps.emplace_back(amax,amin);
        }
    }
    ll answer=ll(N)*N;
    sort(ps.begin(),ps.end());
    for(int i=0;i<ps.size();++i){
        auto it=upper_bound(ps.begin(),ps.end(),make_pair(ps[i].second,int(1e9)));
        answer-=it-ps.begin();
    }
    cout<<answer<<endl;
    return 0;
}