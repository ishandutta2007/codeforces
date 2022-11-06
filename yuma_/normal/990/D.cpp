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
using ld = __float128;
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
using ll =long long ;
struct Compress {
	map<long long int, int>mp;
	map<int, long long int>revmp;
	
	Compress(vector<long long int>vs) {
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
};
void out(vector<vector<int>>field,bool flag=false){
	cout<<"YES"<<endl;
	for(int i=0;i<field.size();++i){
		for(int j=0;j<field[i].size();++j){
			if(flag&&i!=j)field[i][j]=!field[i][j];
			cout<<field[i][j];
		}
		cout<<endl;

	}
	return ;
}
	
int main() {
	ios::sync_with_stdio(false);
	int N,A,B;cin>>N>>A>>B;
	vector<vector<int>>field(N,vector<int>(N));
	bool ok=true;
	bool flag=false;
	if(N==1){
		ok=true;
	}else if(N==2){
		if(A+B==3){
			if(A==2){
				ok=true;
			}else{
				field[0][1]=1;
				field[1][0]=1;
			}
		}else{
			ok=false;
		}
	}else{
		if(A==1&&B==1){
			if(N==3){
				ok=false;
			}else{
				for(int k=0;k<N-1;++k){
					field[k][k+1]=1;
					field[k+1][k]=1;
				}
			}
		}else{
			if(A==1 || B==1){
				if(A==1){
					swap(A,B);
					flag=true;
				}

				assert(B==1);
				for(int k=0;k<N-A;++k){
					field[N-1][k]=1;
					field[k][N-1]=1;
				}
			}else{
				ok=false;
			}
		}
	} 
	if(ok){
		out(field,flag);
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}