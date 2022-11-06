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


const int MAX_N=1e7;
vector<int>min_divs(MAX_N+1);
void init(){
    for(int i=2;i<=MAX_N;++i){
        if(min_divs[i]==0){
            min_divs[i]=i;
            for(ll j=ll(i)*i;j<=MAX_N;j+=i){
                if(min_divs[j]==0)min_divs[j]=i;
            }
        }
    }
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie();
    init();
    int T;cin>>T;
    vector<pair<int,int>>anss(T);
    int i=0;
    while(T--){
        int num;scanf("%d",&num);
        vector<int>v;
        while(num!=1){
            v.emplace_back(min_divs[num]);
            num/=min_divs[num];
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.size()<=1){
            anss[i]=make_pair(-1,-1);
        }else{
            anss[i].first=1;
            for(auto it=v.begin();next(it)!=v.end();++it){
                anss[i].first*=*it;
            }
            anss[i].second=*prev(v.end());
        }
        i++;
    }
    for(int i=0;i<anss.size();++i){
        //cout<<anss[i].first<<' ';
        printf("%d ",anss[i].first);
    }
    cout<<endl;
    for(int i=0;i<anss.size();++i){
        printf("%d ",anss[i].second);

    }
    cout<<endl;

    
	return 0;
}