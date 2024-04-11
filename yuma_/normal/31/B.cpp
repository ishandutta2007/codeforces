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
using ll =long long int;
ld dis(pair<int,int>a,pair<int,int>b){
	ld dx=a.first-b.first;
	ld dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}

using ll = long long int;
vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while ((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}
int main() {
	
	ios::sync_with_stdio(false);
	string st;cin>>st;
	vector<string>sts=split(st,'@');
	bool ok=true;
	if(sts.size()==1)ok=false;
	else{
		if(sts[0].size()==0){
			ok=false;
		}
		if(sts.back().size()==0){
			ok=false;
		}
		for(int i=1;i+1<sts.size();++i){
			if(sts[i].size()<=1)ok=false;
		}
	}
	if(ok){
		vector<string>anss;
		for(int i=0;i<sts.size()-1;++i){
			string ans;
			string pre;
			string nex;
			if(i==0){
				pre=sts[i];
			}else{
				pre=sts[i].substr(1);
			}
			if(i==sts.size()-2){
				nex=sts[i+1];
			}else{
				nex=sts[i+1].substr(0,1);
			}
			cout<<pre<<"@"<<nex;
			if(i==sts.size()-2){
				cout<<endl;
			}else{
				cout<<",";
			}
		}	
	}else{
		cout<<"No solution"<<endl;
	}
	
	return 0;
}