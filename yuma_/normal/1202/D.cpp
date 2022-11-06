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
struct Node{
	vector<shared_ptr<Node>>tos;
	shared_ptr<Node>aback;
	ll sum=0;
	Node():tos(26,nullptr),aback(nullptr){
		
	}
};

struct SA2{
	
	vector<string>sts;
	
	shared_ptr<Node>root;
	SA2(const vector<string>&sts_):sts(sts_),root(make_shared<Node>()){
		init();
	}

	void mk_tree(){

		for(int i=0;i<sts.size();++i){
			shared_ptr<Node>now=root;
			auto S=sts[i];
			for(auto c:S){
				int x=c-'a';
				if(now->tos[x]==nullptr){
					now->tos[x]=make_shared<Node>();
				}
				now=now->tos[x];
			}
			now->sum+=1;
		}
	}
	void mk_back(){
		root->aback=nullptr;
		queue<shared_ptr<Node>>que;
		que.emplace(root);
		while(!que.empty()){
			auto anow=que.front();
			que.pop();
			for(int i=0;i<26;++i){
				if(anow->tos[i]!=nullptr){
					auto anext=anow->tos[i];
					auto anextback=anow->aback;
					while(anextback!=nullptr){
						if(anextback->tos[i]==nullptr){
							anextback=anextback->aback;
						}else{
							break;
						}
					}
					if(anextback==nullptr){
						anext->aback=root;
					}else{
						anext->aback=anextback->tos[i];
					}
					anext->sum+=anext->aback->sum;
					que.emplace(anext);
				}
			}
		}		
	}
	void init(){
		mk_tree();
		mk_back();
	}
	vector<ll>get_cnt(string T){
		vector<ll>nums(T.size()+1);
		nums[0]=0;
		auto now=root;
		for(int i=0;i<T.size();++i){
			int x=T[i]-'a';
			while(now!=root){
				if(now->tos[x]==nullptr){
					now=now->aback;
				}else{
					break;
				}
			}
			if(now->tos[x]==nullptr){
				now=root;
			}else{
				now=now->tos[x];
			}
			nums[i+1]=now->sum;
		}
		return nums;
	}
};

int main() {
	
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		int k=200;
		int num=k*(k-1)/2;

		int a=N/num;
		int b=N%num;

		string st=string(a,'1')+string(k-2,'3')+string(b,'1')+"337";
		cout<<st<<endl;
	}
	return 0;
}