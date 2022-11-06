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

#define WHAT(var) cout<<__LINE__<<' '<<#var<<" : "<<var<<endl;

const ll amod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		int H,W,M;cin>>H>>W>>M;
		vector<string>field(H);
		for(int i=0;i<H;++i)cin>>field[i];
		int rice_cnt=0;
		for(int i=0;i<H;++i)rice_cnt+=count(field[i].begin(),field[i].end(),'R');
		assert(rice_cnt>=M);
		int xx=rice_cnt/M;
		int high_cnt=rice_cnt-M*xx;
		int low_cnt=M-high_cnt;
		assert(high_cnt+low_cnt==M);
		vector<vector<int>>nums(H,vector<int>(W));

		int id=0;
		int num=0;
		for(int y=0;y<H;++y){
			for(int x=0;x<W;++x){
				if(y%2)x=W-1-x;
				if(field[y][x]=='R'){
					if(id<low_cnt&&num==xx){
						num=0;
						id++;
					}else if(id>=low_cnt&&num==xx+1){
						num=0;
						id++;
					}
					num++;
				}
				nums[y][x]=id;
				if(y%2)x=W-1-x;
			}
		}
		for(int y=0;y<H;++y){
			for(int x=0;x<W;++x){
				int k=nums[y][x];
				char ch;
				if(k<26)ch='a'+k;
				else if(k<52)ch='A'+(k-26);
				else ch='0'+(k-52);
				cout<<ch;
			}
			cout<<endl;
		}
	}
	return 0;
}