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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}


const int MAX_N=40;

int solve1(vector<int>cnts,vector<int>trashes,bool mkbig=false){
	int answer=0;
	for(int i=MAX_N;i>=0;--i){
		
		if(cnts[i]<trashes[i]){
			//WHATS(cnts)
			//WHATS(trashes)
			return -1;
		}else{
			while(cnts[i]){
				for(int j=0;j<=i;++j){
					cnts[j]--;
				}
				bool flag=false;
				
				for(int j=i;j>=0;--j){
					if(trashes[j]){
						trashes[j]--;
						flag=true;
						break;
					}
				}
				if(mkbig){
					if(!flag){
						for(int j=0;j<=i;++j){
							if(j==MAX_N||cnts[j]>cnts[j+1]){
								cnts[j]--;
								flag=true;
								break;
							}
						}
					}
					
				}
				
				answer++;
			}
			
		}
	}
	
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;cin>>N;
	vector<ll>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	vector<int>cnts(MAX_N+1);
	vector<int>trashes(MAX_N+1);
	for(int i=0;i<=MAX_N;++i){
		cnts[i]=upper_bound(v.begin(),v.end(),1ll<<i)-lower_bound(v.begin(),v.end(),1ll<<i);
		trashes[i]=lower_bound(v.begin(),v.end(),(1ll<<(i+1)))-upper_bound(v.begin(),v.end(),1ll<<i);
	}
	for(int i=0;i<MAX_N;++i){
		if(cnts[i]<cnts[i+1]){
			trashes[i]+=cnts[i+1]-cnts[i];
			cnts[i+1]=cnts[i];
		}
	}
	//WHATS(cnts)
	//WHATS(trashes)
	int ans2=solve1(cnts,trashes,false);
	int ans1=solve1(cnts,trashes,true);

	for(int k=ans1;k<=ans2;++k){
		cout<<k<<' ';
	}
	cout<<endl;
	
	
	return 0;
}