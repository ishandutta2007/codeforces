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

#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

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
struct po{
	int l;
	int r;
	int u;
	int v;
	int nx,ny;
	po(){
		l=0;
		r=0;
		u=0;v=0;
		nx=0;
		ny=0;
	}
	void upd(int x,int y){
		l=min(l,x);
		r=max(r,x);
		u=min(u,y);
		v=max(v,y);
		nx=x;
		ny=y;
	}
};
int to_num(string &ast){
	int num=0;
	for(int i=0;i<ast.size();++i){
		num*=2;
		if(ast[i]=='1')num++;
	}
	return  num;
}
int main() {

	ios::sync_with_stdio(false);
	int N;cin>>N;
	for(int i=0;i<N;++i){
		string st;cin>>st;
		vector<int>r_nums(st.size()+1);

		for(int i=1;i<st.size()+1;++i){
			if(st[i-1]=='0')r_nums[i]=r_nums[i-1]+1;
		}
		int need=1;
		int answer=0;
		for(int sz=1;sz<=min(int(st.size()),20);++sz){
			for(int l=0;l<int(st.size())-sz+1;++l){
				string ast=st.substr(l,sz);
				int anum=to_num(ast);
				if(need*2>anum && anum>=need){
					if(r_nums[l]>=anum-sz){
						answer++;
					}
				}
			}
			need*=2;
			
		}
		cout<<answer<<endl;
	}
	return 0;
}