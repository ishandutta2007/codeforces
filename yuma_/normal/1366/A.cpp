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
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int N;cin>>N;
   
    while(N--){
        int a,b;cin>>a>>b;
        if(a>2*b){
            cout<<b<<endl;
        }else if(b>2*a){
            cout<<a<<endl;
        }else{
            cout<<(a+b)/3<<endl;
        }
    }
	return 0;
}