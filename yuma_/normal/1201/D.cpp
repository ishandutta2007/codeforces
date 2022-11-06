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
using ll=long long ;

map<int,ll>get_mp(int now,pair<int,int>lr,const vector<int>&oks,bool flag=true){
	int l=lr.first;
	int r=lr.second;
	if(r==-1){
		l=now;
		r=now;
	}
	map<int,ll>mp;
	{
		for(int k=0;k<2;++k){
			int to=k==0?l:r;
			int from=k==0?r:l;
			int plus=abs(now-from)+abs(r-l);
			auto it=lower_bound(oks.begin(),oks.end(),to);
			
			if(it!=oks.begin()){
				int nex=*prev(it);
				ll dis=abs(nex-to)+plus;
				if(flag)dis=plus;
				if(mp.find(nex)==mp.end()){
					mp[nex]=dis;
				}else{
					mp[nex]=min(dis,mp[nex]);
				}
			}
			if(it!=oks.end()){
				int nex=*it;
				ll dis=abs(nex-to)+plus;
				if(flag)dis=plus;
				if(mp.find(nex)==mp.end()){
					mp[nex]=dis;
				}else{
					mp[nex]=min(dis,mp[nex]);
				}
			}
		}
		
	}
	return mp;
}
int main() {
	
	ios::sync_with_stdio(false);
	int H,W;
	cin>>H>>W;
	int A,B;cin>>A>>B;
	int mh=0;
	vector<pair<int,int>>lrs(H,make_pair(W,-1));
	for(int i=0;i<A;++i){
		int x,y;cin>>y>>x;
		x--;y--;
		mh=max(mh,y);
		lrs[y].first=min(lrs[y].first,x);
		lrs[y].second=max(lrs[y].second,x);
	}
	vector<int>oks(B);
	for(int i=0;i<B;++i){
		cin>>oks[i];
		oks[i]--;
	}
	sort(oks.begin(),oks.end());
	map<int,ll>memo;
	memo[0]=0;
	for(int i=0;i<H;++i){
		// for(auto m:memo){
		// 	WHATS(m)
		// }
		// cout<<endl;
		if(i&&lrs[i].second==-1)continue;
		bool flag=false;
		if(i==mh)flag=true;
		map<int,ll>nextmemo;
		for(auto m:memo){
			auto nmemo=get_mp(m.first,lrs[i],oks,flag);
			for(auto nm:nmemo){
				if(nextmemo.find(nm.first)==nextmemo.end()){
					nextmemo[nm.first]=nm.second+m.second;
				}else{
					nextmemo[nm.first]=min(nextmemo[nm.first],nm.second+m.second);
				}
			}
		}
		memo=nextmemo;
	}
	ll answer=1e18;
	for(auto m:memo){
		answer=min(answer,m.second+mh);
	}
	cout<<answer<<endl;
	return 0;
}