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
	int T;cin>>T;
	string st_mp="ASDW";
	while(T--){
		string st;cin>>st;
		int N=st.size();
		int dx[]={-1,0,1,0,0};
		int dy[]={0,1,0,-1,0};
		vector<po>ls,rs;
		{
			int nx=0;int ny=0;
			po apo;
			ls.push_back(apo);
			for(int i=0;i<st.size();++i){
				int way=st_mp.find(st[i]);
				nx+=dx[way];
				ny+=dy[way];
				apo.upd(nx,ny);
				ls.push_back(apo);
			}
		}
		{
			int nx=0;int ny=0;
			po apo;
			rs.push_back(apo);
			for(int i=0;i<st.size();++i){
				int way=st_mp.find(st[st.size()-i-1]);
				way=(way+2)%4;
				nx+=dx[way];
				ny+=dy[way];
				apo.upd(nx,ny);
				rs.push_back(apo);
			}
		}
		ll answer=1e18;
		for(int x=0;x<=N;++x){
			int all=ls[x].l;
			int lr=ls[x].r;
			int lu=ls[x].u;
			int ld=ls[x].v;

			int rl=rs[N-x].l;
			int rr=rs[N-x].r;
			int ru=rs[N-x].u;
			int rd=rs[N-x].v;

			rl-=rs[N-x].nx-ls[x].nx;
			rr-=rs[N-x].nx-ls[x].nx;
			ru-=rs[N-x].ny-ls[x].ny;
			rd-=rs[N-x].ny-ls[x].ny;
			WHATS(rl)
			WHATS(rr)
			WHATS(ru)
			WHATS(rd)
			for(int way=0;way<5;++way){
				int arl=rl+dx[way];
				int arr=rr+dx[way];
				int aru=ru+dy[way];
				int ard=rd+dy[way];

				int al=min(arl,all);
				int ar=max(arr,lr);
				int au=min(aru,lu);
				int ad=max(ard,ld);

				ll dis=ll(ar-al+1)*(ad-au+1);
				WHATS(al)
				WHATS(ar)
				WHATS(au)
				WHATS(ad)
				WHATS(dis)
				answer=min(answer,dis);
			}
		}
			cout<<answer<<endl;

	}
	return 0;
}