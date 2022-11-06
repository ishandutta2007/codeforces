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
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
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
using ll=long long ;
const int MAX_N=10000;
vector<int>min_divs(MAX_N+1);

void ini(){
	for(int i=2;i<=MAX_N;++i){
		if(min_divs[i]==0){
			min_divs[i]=i;
			for(int j=i*i;j<=MAX_N;j+=i){
				min_divs[j]=i;
			}
		}
	}
}
int main() {
	int N;cin>>N;
	ini();
	int ans=0;
	for(int i=2;i<=N;++i){
		set<int>aset;
		int rest=i;
		while(rest!=1){
			int num=min_divs[rest];
			rest/=num;
			aset.emplace(num);
		}
		if(aset.size()==2)ans++;
	}
	cout<<ans<<endl;
	return 0;
}