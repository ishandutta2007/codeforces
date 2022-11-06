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


const int MAX_X=2220;

using ll=long long ;

struct Edge{
	int src;
	int dst;
	int id;
};
using Graph=vector<vector<Edge>>;
int main() {
	ios::sync_with_stdio(false);
	string st;cin>>st;
	vector<int>v;
	int ans=0;
	for(int i=0;i<st.size();++i){
		int x=st[i]-'0';
		bool ok=false;
		if(x%3==0){
			ok=true;
		}else{
			if(v.empty()||(v[0]+x)%3!=0){
				ok=false;
			}else{
				ok=true;
			}
			if(v.size()==2)ok=true;
		}
		if(ok){
			v.clear();
			ans++;
		}else{
			v.push_back(x);
		}
	}
	cout<<ans<<endl;
	return 0;
}