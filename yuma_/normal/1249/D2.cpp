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
ll solve(vector<ll>v){
	ll answer=0;
	sort(v.begin(),v.end());
	for(int i=0;i<3;++i)answer+=v[i]*v[i];
	answer+=v[0]*7;
	return answer;
}

struct player{
	int id;
	ld power;
	ld per;

};
 ostream& operator <<(ostream &os, const player &v){
	os<<v.id<<' '<<v.power<<' '<<v.per<<endl; return os;
}
vector<player>connect(const vector<player>&l,const vector<player>&r){
	vector<player>ps(l.size()+r.size());
	for(int i=0;i<l.size();++i){
		ps[i].id=l[i].id;
		ps[i].power=l[i].power;
		ps[i].per=0;
	}
	for(int i=0;i<r.size();++i){
		ps[i+l.size()].id=r[i].id;
		ps[i+l.size()].power=r[i].power;
		ps[i].power;
	}
	for(int i=0;i<l.size();++i){
		for(int j=0;j<r.size();++j){
			auto lpo=l[i].power;
			auto rpo=r[j].power;
			auto per=l[i].per*r[j].per;
			ps[i].per+=per*(lpo)/(lpo+rpo);
			ps[l.size()+j].per+=per*(rpo)/(lpo+rpo);
		}
	}
	return ps;
}
struct line {
	int id;
	int l;
	int r;
};
int main() {
	ios::sync_with_stdio(false);
	int N,K;cin>>N>>K;
	vector<line>lines;
	for(int i=0;i<N;++i){
		int l,r;cin>>l>>r;
		lines.push_back(line{i+1,l,r+1});
	}
	sort(lines.begin(),lines.end(),[](const line&l,const line&r){return l.l<r.l;});
	set<pair<int,int>>aset;
	vector<int>answer;
	for(int i=0;i<N;++i){
		int al=lines[i].l;
		int ar=lines[i].r;
		int aid=lines[i].id;
		while(!aset.empty()){
			auto it=aset.begin();
			if(it->first<=al){
				aset.erase(it);
			}else{
				break;
			}
		}
		aset.emplace(make_pair(ar,aid));
		if(aset.size()>K){
			auto it=prev(aset.end());
			answer.push_back(it->second);
			aset.erase(it);
		}
	}	
	cout<<answer.size()<<endl;
	for(auto an:answer)cout<<an<<' ';
	cout<<endl;
	return 0;
}