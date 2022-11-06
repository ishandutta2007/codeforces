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

struct Node{
	
	int amax;
	shared_ptr<Node>lch;
	shared_ptr<Node>rch;

	Node(){
		amax=1e9;
		lch=nullptr;
		rch=nullptr;
	}
	void add(int x,int l,int r){
		amax=min(amax,x);

		if(l+1==r){
			return;
		}
		int m((l+r)/2);
		if(x<m){
			if(lch==nullptr)lch=make_shared<Node>();
			lch->add(x,l,m);
		}else{
			if(rch==nullptr)rch=make_shared<Node>();
			rch->add(x,m,r);
		}
	}
	int solve(int d,int x,int aamax){
		if(d==-1)return 0;
		bool lok=(lch!=nullptr)&&(lch->amax<=aamax);
		bool rok=(rch!=nullptr)&&(rch->amax<=aamax);
		if(x&(1<<d)){
			if(lok){

				return lch->solve(d-1,x,aamax)+(1<<d);
			}else{
				if(rok){
					return rch->solve(d-1,x,aamax);
				}else{
					return -1;
				}
			}
		}else{
			if(rok){
				return rch->solve(d-1,x,aamax)+(1<<d);
			}else{
				if(lok){
					return lch->solve(d-1,x,aamax);
				}else{
					return -1;
				}
			}
		}
	}
};
const int MAX_N=1e5;
#include<unordered_map>
int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	vector<vector<int>>divs(MAX_N+1);
	vector<vector<int>>divs2(MAX_N+1);

	for(int i=1;i<=MAX_N;++i){
		for(int j=i;j<=MAX_N;j+=i){
			divs[i].push_back(j);
			divs2[j].push_back(i);
		}
	}
	vector<shared_ptr<Node>>roots;
	for(int i=0;i<=MAX_N;++i){
		roots.push_back(make_shared<Node>());
	}
	while(Q--){
		int type;cin>>type;
		if(type==1){
			int a;cin>>a;
			for(auto d:divs2[a]){
				roots[d]->add(a,0,(1<<17));
			}
			
		}else{
			int x,k,s;cin>>x>>k>>s;
			int answer=-1;
			bool ok=false;
			if(x%k!=0){

			}else{
				int num=roots[k]->solve(16,x,s-x);
					//WHATS(div)
					//WHATS(num)
				 	if(num!=-1)answer=max(answer,num);
				
			}
			if(answer!=-1)answer=answer^x;
			cout<<(answer)<<endl;
		}
	}
	return 0;
}