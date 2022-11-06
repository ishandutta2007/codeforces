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

using ll = long long int;



int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int H,N;cin>>H>>N;
		vector<int>v;
		set<int>aset;
		for(int i=0;i<N;++i){
			int a;cin>>a;
			v.push_back(a);
			for(int k=a+5;k>=a-5;--k){
				if(k<=H&&k>=0){
					aset.emplace(k);
				}
			}
		}
		if(H<=2){
			cout<<0<<endl;
		}else{
			int xxx=0;
			map<int,int>mp;
			{
				for(auto as:aset){
					mp[as]=xxx;
					xxx++;
				}
			}
			
			int start=mp[H];
			vector<int>memo(start+1,1e9);
			vector<int>forms(start+1);
			//WHATS(memo)
			for(auto& x:v){
				x=mp[x];
				forms[x]=true;
			}
			memo[start]=0;
			for(int y=start;y>=2;--y){
				if(!forms[y-1]){
					memo[y-1]=min(memo[y-1],memo[y]);
				}else{
					memo[y-1]=min(memo[y-1],memo[y]+1);
					if(forms[y-2]){
						memo[y-2]=min(memo[y-2],memo[y]);
					}else{
						memo[y-2]=min(memo[y-2],memo[y]+1);
					}
				}
			}
			int answer=min(memo[0],memo[1]);
			answer=min(answer,memo[2]);
			//WHATS(memo)
			cout<<answer<<endl;
		}
		
	}
	return 0;
}