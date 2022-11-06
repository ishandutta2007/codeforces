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
struct Edge{
	int src;
	int dst;
	int cost;
};
bool isso(long long int a) {
	if (a == 1 || a == 0)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if ((a%i)) {
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	int plus=0;
	while(!isso(N-1+plus))plus++;

	int rest=M-(N-1);
	cout<<N-1+plus<<' '<<N-1+plus<<endl;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			ll cost=-1;
			if(i+1==j){
				if(i==0){
					cost=1+plus;
				}else{
					cost=1;
				}
			}else{
				if(rest){
					cost=ll(1e9);
					rest--;
				}
			}
			if(cost!=-1){
				cout<<i+1<<' '<<j+1<<' '<<cost<<endl;
			}else{
				break;
			}
		}
	}

	return 0;
}