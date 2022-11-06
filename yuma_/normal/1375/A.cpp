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

	
using ll = long long int;

int check(vector<int>as){
	int acnt=0;
	int num=0;
	int N=as.size();
	for(int i=0;i<N-1;++i){
		if(as[i]<as[i+1])acnt++;
		else if(as[i]==as[i+1])num++;
		else acnt--;
	}
	return abs(acnt)<=num;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		vector<int>as(N);
		vector<pair<int,int>>ps;
		for(int i=0;i<N;++i){
			cin>>as[i];
			as[i]=abs(as[i]);
			ps.emplace_back(as[i],i);
		}
		for(int i=0;i<N;++i){
			if(check(as))break;
			as[i]=-as[i];
		}
		assert(check(as));

		// int cnt=0;
		// for(int i=0;i<N-1;++i){
		// 	if(as[i]<as[i+1])cnt++;
		// 	else cnt--;
		// }

		// int kk=0;
		// //WHATS(cnt)
		// if(cnt>0){
		// 	int need=cnt/2+1;
		// 	int ncnt=0;
		// 	kk=-1;
		// 	for(int i=0;i<N-1;++i){
		// 		if(as[i]<as[i+1])ncnt++;
		// 		else ncnt--;

		// 		if(ncnt==need){
		// 			kk=i;
		// 			break;
		// 		}
		// 	}
			
		// }else{
		// 	int need=cnt/2-1;
		// 	int ncnt=0;
		// 	kk=-1;
		// 	for(int i=0;i<N-1;++i){
		// 		if(as[i]<as[i+1])ncnt++;
		// 		else ncnt--;

		// 		if(ncnt==need){
		// 			kk=i;
		// 			break;
		// 		}
		// 	}
		// }
		// for(int i=0;i<kk;++i)as[i]=-as[i];
		for(int i=0;i<N;++i)cout<<as[i]<<' ';
		cout<<endl;

		// int acnt=0;
		// int num=0;
		// for(int i=0;i<N-1;++i){
		// 	if(as[i]<as[i+1])acnt++;
		// 	else if(as[i]==as[i+1])num++;
		// 	else acnt--;
		// }
		// assert(abs(acnt)<=num);
		// sort(ps.begin(),ps.end(),greater<pair<int,int>>());

		// int rest=N/2;
		// vector<int>used(N);
		// for(int i=0;i<N;++i){
		// 	int id=ps[i].second;
		// 	int l=i-1;
		// 	int r=i+1;
		// 	int num=0;
		// 	if(l>=0&&!used[l])num++;
		// 	if(r<N&&!used[r])num--;


		// }

	}

	return 0;
}