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
	int N,M;cin>>N>>M;
	vector<int>v(N);
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
	vector<int>answer;

	if(M<*min_element(v.begin(),v.end()) || M>accumulate(v.begin(),v.end(),0)){
		if(v.size()>=2&&M<*min_element(v.begin(),v.end())&&M>=2){
			auto k=min_element(v.begin(),v.end())-v.begin();
			int num=accumulate(v.begin(),v.end(),0)-M;

			int x=k==0?1:0;
			answer.push_back(k);
			for(int i=0;i<N;++i){
				if(i==x || i==k){
					continue;
				}else{
					for(int j=0;j<v[i];++j){
							
						answer.push_back(i);
						answer.push_back(i);
					}
				}
			}
			for(int i=0;i<v[x]-1;++i){
				answer.push_back(x);
				answer.push_back(x);
			}
			answer.push_back(k);
			for(int i=0;i<M-2;++i){
				answer.push_back(k);
				answer.push_back(k);

			}
			answer.push_back(x);
			for(int i=M-1;i<v[k];++i){
				answer.push_back(k);
				answer.push_back(k);

			}
			answer.push_back(x);
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;

		}
	}else{
		cout<<"Yes"<<endl;
		auto k=min_element(v.begin(),v.end())-v.begin();
		int num=accumulate(v.begin(),v.end(),0)-M;
		answer.push_back(k);
		for(int i=0;i<N;++i){
			if(i==k)continue;
			while(v[i]>0 &&num>0){
				answer.push_back(i);
				answer.push_back(i);
				v[i]--;
				num--;
			}
		}
		answer.push_back(k);
		v[k]--;
		for(int i=0;i<N;++i){
			while(v[i]>0){
				answer.push_back(i);
				answer.push_back(i);
				v[i]--;
				
			}
		}
		
	}
	for(int i=0;i<answer.size();++i){
			cout<<answer[i]+1;
			if(i==answer.size()-1)cout<<endl;
			else cout<<' ';
		}
	return 0;
}