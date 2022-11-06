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
	int place;
	Node():tos(26,nullptr),aback(nullptr){
		
	}
};
struct SA2{
	
	vector<string>sts;
	
	shared_ptr<Node>root;
	vector<shared_ptr<Node>>ids;
	SA2(const vector<string>sts_):sts(sts_),root(make_shared<Node>()){
		init();
	}

	void mk_tree(){

		for(int i=0;i<sts.size();++i){
			shared_ptr<Node>now=root;
			auto S=sts[i];
			ids.push_back(now);
			now->place=0;
			int xx=1;
			for(auto c:S){
				int x=c-'a';
				if(now->tos[x]==nullptr){
					now->tos[x]=make_shared<Node>();
				}
				now=now->tos[x];
				now->place=xx++;
				ids.push_back(now);

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
};
int main() {
	ios::sync_with_stdio(false);
	string A,B,C;cin>>A>>B>>C;
	vector<vector<vector<int>>>dp(A.size()+1,vector<vector<int>>(B.size()+1,vector<int>(C.size()+1,-1000000)));

	SA2 b_sa(vector<string>{B});
	SA2 c_sa(vector<string>{C});
	dp[0][0][0]=0;
	for(int a_place=0;a_place<A.size();++a_place){
		for(int b_place=0;b_place<=B.size();++b_place){
			for(int c_place=0;c_place<=C.size();++c_place){
				if(dp[a_place][b_place][c_place]<-100000)continue;
				char ch_l='a';
				char ch_r='z';
				if(A[a_place]=='*'){
					
				}else{
					ch_l=A[a_place];
					ch_r=ch_l;
				}

				for(char ch=ch_l;ch<=ch_r;++ch){
					const int ax=ch-'a';
					auto bit=b_sa.ids[b_place];
					auto cit=c_sa.ids[c_place];

					int next_b_place,next_c_place;
					int asum=dp[a_place][b_place][c_place];

					{
						auto now=bit;
						auto root=b_sa.root;
						
						while(now!=root){
							if(now->tos[ax]==nullptr){
								now=now->aback;
							}else{
								break;
							}
						}
						if(now->tos[ax]==nullptr){
							now=root;
						}else{
							now=now->tos[ax];
						}
						next_b_place=now->place;
						asum+=now->sum;
					}
					{
						auto now=cit;
						auto root=c_sa.root;
						
						while(now!=root){
							if(now->tos[ax]==nullptr){
								now=now->aback;
							}else{
								break;
							}
						}
						if(now->tos[ax]==nullptr){
							now=root;
						}else{
							now=now->tos[ax];
						}
						next_c_place=now->place;
						asum-=now->sum;
					}
					dp[a_place+1][next_b_place][next_c_place]=max(dp[a_place+1][next_b_place][next_c_place],asum);
				}
			}
		}
	}
	ll answer=-1000000;
	for(int i=0;i<=B.size();++i){
		for(int j=0;j<=C.size();++j){
			answer=max(answer,ll(dp[A.size()][i][j]));
		}
	}
	cout<<answer<<endl;
	return 0;
}