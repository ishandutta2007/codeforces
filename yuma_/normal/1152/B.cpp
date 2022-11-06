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
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14

12 1 11
13 3 10
14 5 9
15 7 8
16 2 14
17 4 13
18 6 12

1-12

11 1 10
12 3 9
13 5 8
13 6 7
14 2 12
15 4 11
*/

const int MAX_X=2220;

using ll=long long ;
int H,W;
vector<vector<int>>field;
vector<vector<int>>sums;
int main() {
	ios::sync_with_stdio(false);
	int X;cin>>X;
	vector<int>answers;
	int k=0;
	for(int i=20;i>=0;--i){
		if(X&(1<<i)){
			k=i;
			break;
		}
	}
	for(int i=k-1;i>=0;--i){
		//WHATS(i)
		//WHATS(X)
		if(X==(1<<(k+1))-1)break;
		int num=i;
		if((X&(1<<i))){
			continue;
		}
		if((X&((1<<i)-1))!=0){
			num++;
		}
		X^=(1<<(num))-1;
		X++;
		answers.push_back(num);
		//WHATS(X)
	}
	//WHATS(X)
	cout<<answers.size()*2<<endl;
	for(auto ans:answers)cout<<ans<<' ';
	cout<<endl;
	return 0;
}