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
int xx;

using ll =long long ;

ll mod=1e9+7;
string hand_st="RPS";
int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int N;cin>>N;
		vector<int>nums(3);
		for(int i=0;i<3;++i)cin>>nums[i];
		string st;cin>>st;
		string my_hand(N,'A');
		for(int i=0;i<N;++i){
			if(st[i]=='R'&&nums[1]){
				my_hand[i]='P';
				nums[1]--;
			}else if(st[i]=='S'&&nums[0]){
				my_hand[i]='R';
				nums[0]--;
			}else if(st[i]=='P'&&nums[2]){
				my_hand[i]='S';
				nums[2]--;
			}
		}
		int win_cnt=N-accumulate(nums.begin(),nums.end(),0);
		if(win_cnt>=(N+1)/2){
			for(int i=0;i<N;++i){
				if(my_hand[i]=='A'){
					for(int j=0;j<3;++j){
						if(nums[j]){
							my_hand[i]=hand_st[j];
							nums[j]--;
							break;
						}
						
					}
				}
				
			}
			cout<<"YES"<<endl;
			cout<<my_hand<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;	
}