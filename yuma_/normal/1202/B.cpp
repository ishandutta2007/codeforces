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
int main() {

	ios::sync_with_stdio(false);
	string st;cin>>st;
	int costs[10][10][10][10];
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				for(int l=0;l<10;++l)costs[i][j][k][l]=1e9;
			}
		}
	}
	for(int a=0;a<10;++a){
		for(int b=0;b<10;++b){
			queue<int>que;
			que.emplace(a);
			que.emplace(b);
			vector<int>memo(10,1e9);
			memo[a]=0;
			memo[b]=0;
			while(!que.empty()){
				int now=que.front();
				que.pop();
				for(int k=0;k<2;++k){
					int next=now;
					if(k)next+=b;
					else next+=a;
					next%=10;
					if(memo[next]>memo[now]+1){
						memo[next]=memo[now]+1;
						que.emplace(next);
					}
				}
				
			}
			for(int k=0;k<10;++k){
				for(int plus=0;plus<10;++plus){
					int nk=(k+plus)%10;
					costs[a][b][k][nk]=memo[plus];
				}
			}
		}
	}
	for(int a=0;a<10;++a){
		for(int b=0;b<10;++b){
			ll acost=0;
			for(int i=0;i<st.size()-1;++i){
				int num=int(st[i+1]-'0')-int(st[i]-'0');
				if(num<0)num+=10;
				acost+=costs[a][b][0][num];
			}
			if(acost>=1e8){
				acost=-1;
			}
			cout<<acost;
			if(b==9)cout<<endl;
			else cout<<' ';
		}
	}
	return 0;
}